#pragma once
#include <vector>

class Grid {
    private :
        int rows;
        int columns;
        int cellDim;
        int randomRate;
        int shapeIndex; // 1 for glider, 2 for blinker, 3 for dot, 4 for glider gun, 5 for pulsar
        std::vector<std::vector<int>> cells;
    public :
        Grid(int width, int height, int cellDim, int randomRate):   
            rows(height/cellDim), columns(width/cellDim), cellDim(cellDim), randomRate(randomRate), shapeIndex(3),
            cells(rows, std::vector<int>(columns, 0))
            {};
        void DrawGrid();
        
        int GetRows() { return rows; }
        int GetColumns() { return columns; }
        int GetRandomeRate() { return randomRate; }
        int GetCell(int x, int y);

        bool IsInBounds(int x, int y);
        void SetRandomRate(int value);
        void SetShapeIndex(int value);
        void DrawShape(int x, int y);
        void SetCell(int x, int y, int value);

        void Randomize();
        void Clear();
};