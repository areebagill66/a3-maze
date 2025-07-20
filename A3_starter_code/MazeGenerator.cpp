#include "MazeGenerator.h"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>


 MazeGenerator::MazeGenerator(int h, int w) {
        height = h;
        width = w;
        srand(15); 
    }


   void MazeGenerator::createSkeleton() {
    for (int i = 0; i < height; ++i) {
        std::vector<char> row;

        for (int j = 0; j < width; ++j) {
            row.push_back('.');
        }

        maze.push_back(row);
    }
//create 'x' boundary walls
    for (int i = 0; i < height; i++){
maze[i][0]= 'x';  //left wall
maze[i][width-1] = 'x';  //right wall
    }

     for (int j = 0; j < width; j++){
maze[0][j]= 'x';  //upper wall
maze[height-1][j] = 'x';  //lower wall
    }

    //entrance/exit gates
   for (int j = 1; j < width - 1; ++j) {
            if (maze[1][j] == '.') {
                maze[0][j] = '.'; 
                break;
            }
        }

}



void MazeGenerator::recursiveDivision(int x, int y, int w, int h, bool horz) {
   
    if (w < 3 || h < 3){ 
        return;
    }

    if (horz){
        int rows = (h - 1) / 2;
        if(!rows){
            return;
        }
        int wallY = y + 1+ (rand() % rows) * 2;
             int hole = x +(rand() % (w / 2)) * 2 + 1;

        
             for (int i = x; i < x + w; i++){
            maze[wallY][i] = 'x';
        }
        maze[wallY][hole] = '.'; 
        recursiveDivision(x, y, w, wallY - y, !horz);
        recursiveDivision(x, wallY + 1, w, y + h - wallY - 1, !horz);
    } 
    else{ 
        int cols = (w - 1) / 2;
        if(!cols){
            return;
        } 
        
           int wallX = x + 1 + (rand() % cols) * 2;
        int hole = y+(rand()%(h / 2))* 2+ 1;

              for (int i = y; i < y + h; i++){
            maze[i][wallX] = 'x';
        }
        maze[hole][wallX] = '.'; 
           recursiveDivision(x, y, wallX - x, h, !horz);
        recursiveDivision(wallX + 1, y, x + w - wallX - 1, h, !horz);
    }
}

    

 

    

   


      


  
void MazeGenerator::printMaze() {
    for (const auto& row : maze) {
        for (char c : row){
             std::cout << c;
        }
        std::cout << '\n';
    }
}



    std::vector<std::vector<char>> MazeGenerator::generateMaze() {
        createSkeleton();
        recursiveDivision(1, 1, width - 2, height - 2, true); // start recursive divide
       
        return maze;
    }
    


