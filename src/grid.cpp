#include <raylib.h>
#include "grid.hpp"

void Grid::DrawGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Color color = cells[i][j] == 1 ? GREEN : BLACK;
            DrawRectangle(j*cellDim, i*cellDim, cellDim-1, cellDim-1, color);

        }
    }
}

void Grid::SetCell(int x, int y, int value) {
    if(x >= 0 && x < rows && y >= 0 && y < columns) {
        cells[x][y] = value;
    }
}