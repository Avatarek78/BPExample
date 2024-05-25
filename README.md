# Unreal Engine demonstrační, originálně vytvořený pouze jako BP projekt s přidáním C++ zdrojáků dodatečně a následným přidáním pluginu
![Vytvoření projektu](Doc/create-project.png)

## Jak přidat plugin, ale hlavně jak to celé rozchodit a nezbláznit se z toho

- založit nový UE projekt, ideálně rovnou na začátku zvolit variantu C++ projekt (nebo dodatečně přidat nějakou C++ třídu a nechat tak vygenerovat .sln soubor),
  pokud chceme vytvořit všechny typy pluginů, protože v projektu bez C++ lze vytvořit jen plugin typu "Content Only" a o takový mě v této demonstraci vůbec nejde.
- dále u lze pokračovat např. dle tohoto návodu https://www.quodsoler.com/blog/how-to-create-an-unreal-engine-plugin-a-step-by-step-guide-with-examples
  ve kterém mimochodem ten první důležitý bod vůbec nezmiňují, takže skončíte s návodem hned po první minutě a dál to nejde.
- pak tedy dle návodu Edit -> Plugins -> [+Add] -> Blank -> Pojmenovat plugin a zaškrtnout

  Do teď to vypadá jako pohoda, ale jen do té doby, než se začnou dít hrozné věci bez zjevných příčin o kterých se dozvíte v dalších řádcích níže.

----

## ☠️Tyhle věci se věčně hnojí sami od sebe!☠️

> [!IMPORTANT]
> Čirou náhodou jsem přišel na klávesovou zkratku v UE a to **Ctrl+Alt+F11**, kterou mě poradil Live Coding poté co jsem ho vypnul a zapnul.
> Zkusil jsem tuto zkratku několikrát za sebou při drobných změnách v C++ kódu a vždy se projevili. Testoval jsem to asi 10x za sebou
> a pokaždé úspěšně což se ještě nikdy historicky nestalo!
> Takže to chtějí říct, že tahle tajná zkratka dělá něco jiného než klik na tlačítko Live Coding vpravo dole?
> Proč takováto důležitá fce není k nalezení např. v menu pod Build kde bych ji čekal?
> > Zkusím to příště ověřit ještě většími změnami jak moc je to spolehlivé.

❌ Předchozí den vše v poho, další den jen otevřeš projekt, klikneš na Live Coding a hle:

```
Failed to move file from N:\EpicGames\UE_projects\BPExample\Intermediate\Build\Win64\x64\UnrealEditor\Development\BPExample\BPExample.cpp.obj to 
N:\EpicGames\UE_projects\BPExample\Intermediate\Build\Win64\x64\UnrealEditor\Development\BPExample\BPExample.cpp.obj.lctmp. Error: 0x5
```
Jako jaký má smysl přesouvat nějaký soubor (ne jen tento je jich mnoho) v rámci stejné složky, takže přejmenovávat z BPExample.cpp.obj na BPExample.cpp.obj.1ctmp?
OK takže zase trapné kolečko, zavřít VS zavřít UE, vymazat složku *Plugins\ExampleBlankPlugin\Intermediate*, otevřít znovu UE a spusti znovu kompilaci přes Live Coding...
BUM💥 ani to nedoběhlo a UE 5.4.1 padá na hubu tvrdou chybou!
```
Unhandled Exception: EXCEPTION_ACCESS_VIOLATION 0x0000000300905a4d

UnrealEditor_BPExample_patch_1!__ImageBase <PERF> (UnrealEditor_BPExample_patch_1+0x1044)()
ucrtbase
UnrealEditor_BPExample_patch_1!dllmain_crt_process_attach() [D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\dll_dllmain.cpp:66]
UnrealEditor_BPExample_patch_1!dllmain_dispatch() [D:\a\_work\1\s\src\vctools\crt\vcstartup\src\startup\dll_dllmain.cpp:276]
UnrealEditor_LiveCoding
UnrealEditor_LiveCoding
UnrealEditor_LiveCoding
ucrtbase
kernel32
```
Vůbec nechápu co je to tam za cestu, disk D: sice mám, ale na něm žádná složka D:\a neexistuje, takže co to plácá?
Každopádně jediné řešení na které jsem přišel je uvedeno na konci této sekce.

❌ Stačí něco změnit v C++ (naprosto validní nebo bezvýznamná změna, která nic nerozbíjí) a najednou se v BP divíš co to provádí:

```Can't connect pins  Target  and  Return Value : Example Plugin Class Object Reference is not compatible with LIVECODING Example Plugin Class 0 Object Reference.```
![LIVECODING_Object_Reference_Mismatch.png](Doc/LIVECODING_Object_Reference_Mismatch.png)

> [!IMPORTANT]
> No jediný způsob jak tyto prapodivné problémy opravit je celé to zavřít (UE i VS) a smazat jak v projektu **BPExample** tak ve vnořeném projektu 
> **Plugins\ExampleBlankPlugin** složky **Intermediate** Potom znovu otevřít projekt a nechat ho celý i s pluginen znovu sestavit.
> To je prostě taková 💩
> Pokud by to postoupilo na vyšší level a ani tohle nepomohlo, potom jedině asi ještě smazat složky **.vs** a **Binaries**

❌ Dostal jsem to do stavu, kdy to vůbec nereaguje na změny v kódu a tvrdošíjně to drží starou verzi.
- přejmenoval jsem metodu UExamplePluginClass::LogInfo na Log a přidal novou metodu LogFatal avšak v BluePrintech v UE se vše tváří při starém, vše je OK a vše funguje po staru,
  takže metoda se stále jmenuje Log Info a nová metoda Log Fatal neexistuje.
- zkoušel jsem samozřejmě Live Coding build a Refresh All Nodes v UE, potom build ve VS, prostě nic nejde to tam dostat
- zkusil jsem kombinaci dát v VS Clean a v UE Live Coding build -> BUM💥 padlo to na:
  Unhandled Exception: EXCEPTION_ACCESS_VIOLATION writing address 0x00007fffff0ed26c
  UnrealEditor_CoreUObject

> [!IMPORTANT]
> Prostě nic normálního co by fungovalo za běhu nefunguje, až když jsem zavřel UE a ve složce pluginu jsem smazal složku Binaries tak se to při otevírání projektu, přeptalo na rebuild
> a konečně to zjistilo skutečnost, že jsem přejmenoval fci LogInfo na Log. Takže to jako budu dělat při každé změně ve zdrojáku takového tanečky, aby se to milostivě propsalo do UE?! 🤦‍♂️
> Pokud by náhodou nestačilo smazat složku Binaries tak ještě zkusit smazat i složku Intermidiate.
> ![image](Doc/method_name_change_detected.png)

----

## Pokročilejší možnosti
> zdroj: ChatGPT
- [Nastaveni log level-u](Log_level.MD)

- [Vytváření BP nodů s možností přidat/odebrat piny nebo některé parametry skrýt](BP_with_add_pins_or_hide_parameters_in_CPP.MD)

- [Singleton s instancí uloženou ve statické proměnné](CPP_Singleton_statically_stored.MD)

- [Popis základních C++ tříd ze kterých lze v UE vytvářet BP jako jejich potomky](UE_BP_base_classes.MD)
