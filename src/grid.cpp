#include <raylib.h>
#include "grid.hpp"

void Grid::DrawGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            Color color = cells[i][j] == 1 ? RED : BLACK;
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

void Grid::Randomize() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int random = randomRate > 0 ? GetRandomValue(0, randomRate - 1) : 1;
            cells[i][j] = (random == 0) ? 1 : 0;
        }
    }
}

void Grid::Clear() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cells[i][j] = 0;
        }
    }
}