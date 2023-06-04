# About the Code
The code functions to provide a classic menu-based (dictionary pre-defined) version of the game of wordle.

## Algorithm:
- The header files iostream, string, and random are included.
- Under the namespace std, the following lines of code are built.
- A list of 5-letter words is declared as an array of strings. This list acts as the dictionary of possible words as answers.
- A function randword() is declared with return type string, and returns a random string word from the array mentioned.
- 2 functions, menu() (return type void) and playagain() (return type void) are declared using forward declaration for use in upcoming functions.
- A function playgame() is declared with return type void. This function performs the role of displaying each of the 6 rounds of the wordle game, including the guess made, its relevance with the actual answer and (if required) whether or not the game is over with a loss/win. It also includes a user-input feature that allows the user to play again or exit to menu, using the forward-declared playagain() function.
- The forward-declared playagain() function is defined to perfoem the function of displaying the options to either play again or return to the main menu and taking in the user input to do so.
- A function howtoplay() is declared with return type void, and defined to perform the function of displaying the rules and simple explanataion of the game in a readable format, and allows the user to return to menu by calling the forwad-declared menu() function using user input.
- A function quit() is declared witj return type void, and defined to perform the function of asking the user if leaving the game is intentional and offers the user 2 options (Yes or No) and either exits the game (terminating the program) or returns to the main menu by calling the forward-declared menu function respective to the user input.
- The forward-declared menu() function is defined to perform the function of displaying 3 options (PLAY, HOW TO PLAY, EXIT), each of which can be selected by the user by inputting their allotted number. Based on the input, using a switch-case algorithm, the respective function (playgame(), howtoplay(), quit()) is called, with the default case returning to the menu again by calling the menu() function (similar to recursive syntax).
- The main() function is declared with return type int, and defined to display a greeting message and then calling the menu() function.
- Finally, the main() function is closed by returning the integer 0.

## Need-to-knows:
- The 'dictionary' of possible answers is limited and does not contain every possible 5-letter word.
- Each guess is valid as long as it contains exactly 5 characters and each character is an uppercase letter.
- To play the version where the entire list of possible answers in the official game of wordle are used, refer the Wordle Archetype directory in this repository: 
