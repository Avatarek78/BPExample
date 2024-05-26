It sounds like you've encountered some confusion with the compilation process in Unreal Engine 5 when making changes to your C++ code. Let's break down the two scenarios you've described:

1. **Using the Button for Recompilation:**
   - When you click the button labeled "Recompile and reload C++ code for game systems on the fly," UE5 prints "Manual recompile triggered" in the log.
   - However, your changes in the C++ code don't seem to take effect.

2. **Using the Shortcut (Ctrl+Alt+F11) for Compilation:**
   - When you use the shortcut, compilation starts with the message "Accepted Live coding shortcut" in the log.
   - Changes in your code are always affected, and this method reliably updates your code in the game.

The difference between these two methods might stem from how Unreal Engine 5 handles compilation triggers:

- The button you're clicking seems to trigger a manual recompilation, but it's possible that it doesn't fully capture all the necessary dependencies or configurations for your changes to take effect properly. Hence, while the compilation may complete without errors, the changes may not be reflected in the game.

- On the other hand, the shortcut (Ctrl+Alt+F11) you're using might be tied directly into the live coding functionality of Unreal Engine 5. This means it's optimized to detect and incorporate changes in your code more seamlessly, ensuring that your modifications are reflected in the game as expected.

Given these observations, it's understandable why you might feel confused and frustrated. The inconsistency in behavior between the two methods can be perplexing. However, it's worth noting that the shortcut method appears to be more reliable for your purposes.

To address your concerns and ensure a smoother workflow, you could consider the following steps:

1. **Stick to the Shortcut**: Since the shortcut method reliably updates your code in the game, consider using it as your primary approach for compilation during development.

2. **Investigate Button Behavior**: If you're curious about why the button's behavior differs from the shortcut, you could delve into Unreal Engine's documentation or community forums to see if there are any insights or explanations provided by other users or developers.

3. **Report the Issue**: If you suspect that the button's behavior may be a bug or oversight in Unreal Engine 5, consider reporting it to Epic Games, the developer of Unreal Engine. They may be able to provide clarification or address the issue in a future update.

By following these steps, you can hopefully streamline your development process and gain a better understanding of how to effectively work with C++ code in Unreal Engine 5.