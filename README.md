# Text-Based-Game-Cpp

## Description
This is a text-based combat game where you play as a character battling different enemies. The objective of the game is to defeat all enemies and earn points. As you progress, enemies will become stronger and harder to defeat. You can use different attack moves to defeat enemies, and you have a shield to defend yourself. After each battle, your shield will be restored, and your stats will improved.

## Technologies Used
This project is implemented in C++, and it runs on the console. The project uses the following libraries:
* Windows.h
* ctime
* fstream
* iostream
* string

## How to Set Up and Run the Project
You can either download the Executable file, or
1. Clone the repository to your local machine
2. Open the project in an IDE that supports C++.
3. Compile and run the project in the IDE.

## How to Play
1. When you run the project, you will be asked to enter the difficulty mode. Difficulty modes range from easy to hard. You can also choose random to test you luck ;)
2. The you will have to set up your character's strong and weak points by entering values of his attack, shield and heal effectiveness.
2. After you enter the values, the first battle will begin.
3. You will be presented with three attack options: pepper spray, sword, and Ground Punch. Choose your move by typing the corresponding number and pressing Enter.
4. After you attack, the enemy will attack you.
5. You can choose to defend yourself with your shield. When you defend, you take reduced damage, but your shield will take damage instead.
6. The battle will continue until either you or the enemy is defeated.
7. After the battle, your shield will be restored, and your stats will improve.
9. The game will continue until you defeat all 10 enemies.

## Code Overview
The code consists of two classes, Player and Enemy. The Player class has properties for health, mana, attack, shield, maxShield, maxHealth, maxMana, usingShield, and points. The Enemy class has properties for health, attack, and points. The code also has functions for attacking, defending, and checking if the enemy is dead. The game is played on the console, and the user interacts with the game by entering numbers and pressing Enter.
