# Battleships

This repository contains an application that is an implementation of the popular game battleships using C++14 and the SFML library. It was created as a student project using Visual Studio 2022.

## How to run

To start the application, run: x64/Release/Statki.exe.exe program.

## How to play

The application allows the user to play against a computer opponent.

### Starting the game and placing Battleships

After launching the `.exe` file, a 1600x900 window opens showing the start screen with the game title and a **Play** button.

Pressing **Play** lets the player place their ships on the board. On the right side, buttons allow selection of ship type (1–4, corresponding to ship length) and orientation (horizontally or vertically, horizontal by default). The black button indicates the currently selected option, while gray buttons show ship types that are already fully placed. Ships cannot touch each other, including diagonally.

The **Clear board** button resets the board. Once all ships are placed, the **Play** button becomes active (red background) and starts the game.

### Game

The main gameplay screen contains **two boards**:

- Left: the player’s own board, showing ships placed earlier, which the computer opponent will target.  
- Right: the player’s attack board, where the player selects positions to shoot at.

Above the boards, messages indicate whose turn it is. Below the boards, messages show the results of hits.  

The game starts with the player’s turn. The player selects a position of an enemy ship by clicking on a dark blue square. If the enemy ship is hit, the player gets another shot. Otherwise, the turn passes to the opponent. Shooting at the same square twice is not allowed.


Color Legend:
- Dark Blue – square not yet selected
- Light Blue – “miss”
- Yellow – hit on a ship that is not yet sunk
- Red – hit on a ship that has been sunk
- Black – location of a ship (or part of it) placed by the player



