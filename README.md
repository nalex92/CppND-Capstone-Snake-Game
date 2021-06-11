# CPPND: Capstone Snake Game Updated

This is a capstone project for Udacity, which has been adapted from starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). 

<img src="snake_game.gif"/>

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

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

The code base can be divided into five distinct classes (that are sequentially instatiated in main):
- Renderer - render the state of the snake using SDL library
- Game - constructs the game window and place the food and snake
- Snake - constructs the snake and maintains its state
- Controller - receives input from the user that controls the movement of the snake
- Statistics - new class added in order to print in a file the status at the end of a game

New features:
- snake will not wrap around at the edge of the window and it should avoid to hit the margins in order to be kept alive
- the game takes as input the desired difficulty at the console (0 - Easy, 1 - Medium, 2 - Hard)
- the game will output the statistics (score, size of the snake and difficulty) in order to keep a history of games on the same machine.

Rubric Items:
1. Loops, Functions, I/O - The project accepts user input and processes the input.
  Contribution: the program waits for a difficulty level to be introduced by the user. According to the difficulty set, the speed_ and the speed_step_ will be adjusted accordingly. The functionality can be found in a new member from Game class, namely GetDifficultyFromUser (game.cpp), which is called in main.cpp.

2. Loops, Functions, I/O - The project reads data from a file and process the data, or the program writes data to a file. The project reads data from an external file or writes data to a file as part of the necessary operation of the program.
  Contribution: the program keeps the score and the difficulty level for a game that will be appended to a file. A history of the games played will be kept there locally in  "CppND-Capstone-Snake-Game/build/statistics.txt". The functionality can be found in the file statistics.cpp and its corresponding header statistics.h.

3. Object Oriented Programming - The project uses Object Oriented Programming techniques. The project is organized into classes with class attributes to hold data and class methods to perform tasks.
  Contribution: The original starter project was designed based on OOP. The subsequent features added fulfill the same design. Few examples:
  - new methods added to Snake class (snake.cpp): CheckMargins, SetGameParams, IncrementSnakeSpeed
  - new attribute was added to Snake class(snake.h): speed_step_.

4. Object Oriented Programming - Classes use appropiate access specifiers for class members. All class data members are explicitlly specified as public, protected or private.
  Contribution: New members in Snake class are either private or public:
  - private members added in Snake class (snake.h): attribute speed_ has reduced scope, new attribute speed_step_ and new method CheckMargins;
  - public members added in Snake class (snake.h): method SetGameParams and method IncrementSnakeSpeed;

5. Object Oriented Programming - Classes abstract implementation details from their interfaces. All class member functions document their effects, either through function names, comments or formal documentation. Member functions do not change program state in undocumented ways.
  Contribution: All the new methods created within Snake class have comments: SetGameParams, IncrementSnakeSpeed, CheckMargins;

6. Object Oriented Programming - Classes encapsulate behavior. Appropiate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
  Contribution: State of attributes in Snake class is controlled through member functions. Example:
  - attribute speed_ and attribute speed_step_ are set through SetGameParams method;
  - attribute alive_ is accessed through getter GetAliveState;
  
7. Memory Management - The project makes use of reference in function declaration.
  Contribution: Two functions use pass-by-reference in the project code: CheckMargins and SetGameParams in snake.cpp;


