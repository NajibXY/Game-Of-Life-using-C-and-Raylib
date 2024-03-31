#pragma once
#include "grid.hpp"

class Simulation {
    private :
        Grid grid;
        
    public :
        Simulation(int width, int height, int cellDim, int randomRate): grid(width, height, cellDim, randomRate) {grid.Randomize();};
        void DrawGrid();
        void SetCell(int x, int y, int value);
        int CountLiveNeighbours(int x, int y);
        void Update();
};