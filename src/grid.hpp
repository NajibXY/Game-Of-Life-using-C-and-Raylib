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
        
        int getRows() { return rows; }
        int getColumns() { return columns; }

        bool IsInBounds(int x, int y);
        void SetCell(int x, int y, int value);
        int GetCell(int x, int y);

        void Randomize();
};