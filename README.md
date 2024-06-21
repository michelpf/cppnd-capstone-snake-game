# Capstone Snake Game Example

## Introduction

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Milestones

This C++ project encapsulates the knowledge acquired throughout the Udacity C++ Nanodegree, drawing upon foundations in language fundamentals, object-oriented programming, memory management, and concurrency. The source code has undergone significant adaptations based on the provided starter code from Udacity. The codebase is structured and functionally divided into four distinct class-based components:

The Renderer component is responsible for rendering the game state using the popular SDL library.

The Game component constructs and maintains the game board and the placement of game elements, such as the snake and food.

The Snake component constructs and maintains the snake object as it moves across the board, accumulating points and checking for self-collisions.

The Controller component receives user input to control the snake's movement.

Additionally, a control mechanism has been implemented to adjust the difficulty of each game based on the control speed. With three levels - the first being easier and slower, the second with intermediate speed, and the third at high speed - players can face varying challenges. Upon starting the game, the initial game level is randomly selected. During gameplay, players can also change the difficulty level using the "1" key for easy, "2" for normal, and "3" for difficult levels.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
5. Check your difficultu level. If you want to change, press 1 for easy, 2 for normal and 3 for hard.

## Relevant Points

### Code Organization: Loops, Functions, I/O:
The project exhibits a well-organized structure with a focus on functions and classes, preventing code duplication and incorporating user input for snake control and various game features.

### Object-Oriented Approach:
The project's code embraces an object-oriented paradigm, utilizing classes with clear attribute specifications for data and method implementations for task execution. Friend classes are employed, and detailed comments accompany each class method.

### Effective Memory Management:
The project demonstrates proficiency in memory management, utilizing references in function declarations and employing both references and pointers throughout the codebase for enhanced flexibility.

### Thread Implementation for Concurrency:
Concurrency seamlessly enhances the project by introducing a unique gameplay element: a special food item appears every 10 seconds, allowing players to multiply their points by 100. The threads created for this purpose wait for the designated time and then modify the game's private pointer variable to introduce the special food. This approach ensures an exciting and dynamic experience for players, offering an opportunity to significantly boost their scores.

The probability of encountering this special food item varies with the difficulty level. In the easy difficulty setting, there's a 50% chance, in the normal difficulty setting, there's a 20% chance, and in the difficult setting, there's a 10% chance. This strategic implementation adds an extra layer of challenge and reward, enhancing the overall gaming experience.

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
