#pragma once
#include <vector>

class Grid {
    private :
        int rows;
        int columns;
        int cellDim;
        std::vector<std::vector<int>> cells;
    public :
        Grid(int width, int height, int cellDim):   
            rows(height/cellDim), columns(width/cellDim), cellDim(cellDim), 
            cells(rows, std::vector<int>(columns, 0)) {};
        void DrawGrid();

        void SetCell(int x, int y, int value);
};