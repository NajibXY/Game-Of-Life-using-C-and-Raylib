#include <raylib.h>
#include "grid.hpp"

void Grid::DrawGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Color color = cells[i][j] == 1 ? GREEN : BLACK;
            DrawRectangle(j*cellDim, i*cellDim, cellDim, cellDim, color);

        }
    }
}

void Grid::SetCell(int x, int y, int value) {
    cells[y][x] = value;
}