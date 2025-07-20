#include "MazeGenerator.h"
#include <iostream>

int main() {

      //test1
    std::cout << "Test 1: 4x4\n";
    MazeGenerator maze1(4,4);
    maze1.generateMaze();
    maze1.printMaze();
   
     //test2
    std::cout << "Test 2: 5x5\n";
    MazeGenerator maze2(5,5);
    maze2.generateMaze();
    maze2.printMaze();

     //test3
    std::cout << "Test 3: 7x9\n";
    MazeGenerator maze3(7,9);
    maze3.generateMaze();
    maze3.printMaze();

     //test4
    std::cout << "Test 4: 11x11\n";
    MazeGenerator maze4(11,11);
    maze4.generateMaze();
    maze4.printMaze();

     //test5
    std::cout << "Test 5: 2x2\n";
    MazeGenerator maze5(2,3);
    maze5.generateMaze();
    maze5.printMaze();

    

    return 0;
}