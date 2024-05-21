# Originálně vytvořený pouze BP projekt s přidáním C++ zdrojáků dodatečně
![Vytvoření projektu](Doc/create-project.png)

## Jak to celé rozchodit a nezbláznit se z toho

TODO: Sepsat presne postup jak jsem to cele rozchodil (a vzteky to u toho nerozslapal)

*Tohle se věčně hnojí samo od sebe!*
```Can't connect pins  Target  and  Return Value : Example Plugin Class Object Reference is not compatible with LIVECODING Example Plugin Class 0 Object Reference.```
![LIVECODING_Object_Reference_Mismatch.png](Doc/LIVECODING_Object_Reference_Mismatch.png)

> [!IMPORTANT]
> No jediný způsob jak to opravit je celé to zavřít (UE i VS) a smazat jak v projektu **BPExample** tak ve vnořeném projektu 
> **Plugins\ExampleBlankPlugin** složky **Binaries** a **Intermediate** a v **BPExample** ještě složku .vs.
> Potom znovu otevřít projekt a nechat ho celý i s pluginen znovu sestavit. To je prostě taková 💩

----
## Pokročilejší možnosti
- [Nastaveni log level-u](Log_level.MD)

- [Vytváření BP nodů s možností přidat/odebrat piny nebo některé parametry skrýt](BP_with_add_pins_or_hide_parameters_in_CPP.MD)

- [Singleton s instancí uloženou ve statické proměnné](CPP_Singleton_statically_stored.MD)

