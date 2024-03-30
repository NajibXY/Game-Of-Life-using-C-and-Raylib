#pragma once
#include "grid.hpp"

class Simulation {
    private :
        Grid grid;
        
    public :
        Simulation(int width, int height, int cellDim): grid(width, height, cellDim) {};
        void DrawGrid();
        void SetCell(int x, int y, int value);
        int CountLiveNeighbours(int x, int y);
};