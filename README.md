# Wordle
A C++ program implementation of the classic and popular game of Worlde

## What is Wordle?
Wordle is a classic word game that is popular due to its simplistic rules but engaging gameplay.
At the time of creation of this file, the official site for Wordle is owned by New York Times.
The official link to the online game can be found here: https://www.nytimes.com/games/wordle/index.html

## How to Play?
There is a secret 5-letter word which will not be revealed until the end of the game. The objective of the game is for you to guess that word within 6 tries.
In each of the 6 attempts, you are allowed to guess a valid 5-letter word. Your guess will then be displayed back to you with the following annotations under each letter: <br>
  - No luck! <br> '\-' means that the letter does not appear in the secret word at all.
  - Close! <br>'\*' means that the letter appears in the secret word but not in the guessed position.
  - On point! <br>'\^' means that the letter appears in that position in the secret word.

<br>The game ends either when you guess the word correctly or if you are unable to within 6 tries.

Tip: You may choose to either prioritiize minimizing the number of attempts or ensuring the word is guessed within 6 attempts.
    Either way, make sure you experience the fun gammeplay and working of this game!


# About the Codes
This repository contains, primarily, 2 program files:
  
 - Wordle Concise <br> This lets you play the game assuming a dictionary of a few (at this point in time, 10) simple words that have been specificed within the code. More so, you may guess a combination of any 5 letters i.e. the guess need not be a word in the actual English dictionary. <br>This version is available for 'quickplay' and does not require the user to download an additional text file for the dictionary.

 - Wordle Archetype <br> This lets you play the game using a downloadable text file that contains essentially every 5-letter word in the official Wordle dictionary. More so, only guesses that fall under this dictionary are allowed. <br>This version contains holds more variety and is closer to the gameplay of the official Wordle application.

<b>Note: At this point in time, Wordle Concise is recommended.
