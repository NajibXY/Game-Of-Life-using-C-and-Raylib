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
        
        // Getters and setters
        int GetRows() { return rows; }
        int GetColumns() { return columns; }
        int GetRandomeRate() { return randomRate; }
        void SetRandomRate(int value) { randomRate = value; }
        void SetShapeIndex(int value) { shapeIndex = value; }

        // Operations on a cell
        bool IsInBounds(int x, int y);
        int GetCell(int x, int y);
        void SetCell(int x, int y, int value);

        // Global Drawing operations
        void DrawGrid();
        void Randomize();
        void Clear();

        // Drawing shapes
        void DrawShape(int x, int y);


};