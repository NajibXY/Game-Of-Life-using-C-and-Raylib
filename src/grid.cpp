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

bool Grid::IsInBounds(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < columns;
}

void Grid::SetCell(int x, int y, int value) {
    if(IsInBounds(x, y)) {
        cells[x][y] = value;
    }
}

int Grid::GetCell(int x, int y) {
    if(!IsInBounds(x, y)) {
        return 0;
    }
    return cells[x][y]; 
}