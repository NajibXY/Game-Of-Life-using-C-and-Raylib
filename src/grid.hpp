#pragma once
#include <vector>

class Grid {
    private :
        int rows;
        int columns;
        int cellDim;
        int randomRate;
        std::vector<std::vector<int>> cells;
    public :
        Grid(int width, int height, int cellDim, int randomRate):   
            rows(height/cellDim), columns(width/cellDim), cellDim(cellDim), randomRate(randomRate),
            cells(rows, std::vector<int>(columns, 0)) 
            {};
        void DrawGrid();
        
        int GetRows() { return rows; }
        int GetColumns() { return columns; }
        int GetRandomeRate() { return randomRate; }

        bool IsInBounds(int x, int y);
        void SetRandomRate(int value);
        void SetCell(int x, int y, int value);
        int GetCell(int x, int y);

        void Randomize();
        void Clear();
};