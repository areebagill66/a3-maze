#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <vector>

class MazeGenerator {
private:
    int height, width;
    std::vector<std::vector<char>> maze;

    void createSkeleton();
    void recursiveDivision(int x, int y, int w, int h, bool horz);
    

public:
    MazeGenerator(int h, int w);
    std::vector<std::vector<char>> generateMaze();
     void printMaze();
};

#endif