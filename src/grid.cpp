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
    } else {
        // Wrap around toroidal coordinates
        int wrappedX = (x + rows) % rows;
        int wrappedY = (y + columns) % columns;
        cells[wrappedX][wrappedY] = value;
    }
}

int Grid::GetCell(int x, int y) {
    if(!IsInBounds(x, y)) {
        // Wrap around toroidal coordinates
        int wrappedX = (x + rows) % rows;
        int wrappedY = (y + columns) % columns;
        return cells[wrappedX][wrappedY];
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

void Grid::SetRandomRate(int value) {
    randomRate = value;
}

void Grid::SetShapeIndex(int value) {
    shapeIndex = value;
}

void Grid::DrawShape(int x, int y) {
    if (shapeIndex == 3) {
        SetCell(x, y, 1);
    } else if (shapeIndex == 1) { // Glider
        SetCell(x, y, 1);
        SetCell((x + 1) % rows, y, 1);
        SetCell((x + 2) % rows, y, 1);
        SetCell((x + 2) % rows, (y + 1) % columns, 1);
        SetCell((x + 1) % rows, (y + 2) % columns, 1);
    } else if (shapeIndex == 2) { // Blinker
        if (GetRandomValue(0, 1) == 0) { // Randomly choose orientation
            SetCell(x, y, 1);
            SetCell(x, (y + 1) % columns, 1);
            SetCell(x, (y + 2) % columns, 1);
        } else {
            SetCell(x, y, 1);
            SetCell((x + 1) % rows, y, 1);
            SetCell((x + 2) % rows, y, 1);
        }
    } else if (shapeIndex == 4) { // Glider Gun
        SetCell(x, y, 1);
        SetCell(x, (y + 1) % columns, 1);
        SetCell((x - 1 + rows) % rows, y, 1);
        SetCell((x - 1 + rows) % rows, (y + 1) % columns, 1);

        SetCell(x, (y + 10) % columns, 1); //X Y+10
        SetCell((x - 1 + rows) % rows, (y + 10) % columns, 1); //X-1 Y+10
        SetCell((x + 1) % rows, (y + 10) % columns, 1); //X+1 Y+10
        SetCell((x + 2) % rows, (y + 11) % columns, 1); //X+2 Y+11
        SetCell((x + 3) % rows, (y + 12) % columns, 1); //X+3 Y+12
        SetCell((x + 3) % rows, (y + 13) % columns, 1); //X+3 Y+13
        SetCell((x + 2) % rows, (y + 15) % columns, 1); //X+2 Y+15
        SetCell((x + 1) % rows, (y + 16) % columns, 1); //X+1 Y+16
        SetCell(x, (y + 16) % columns, 1); //X Y+16
        SetCell(x, (y + 17) % columns, 1); //X Y+17
        SetCell((x - 1 + rows) % rows, (y + 16) % columns, 1); //X-1 Y+16
        SetCell((x - 2 + rows) % rows, (y + 15) % columns, 1); //X-2 Y+15
        SetCell(x, (y + 14) % columns, 1); //X Y+14
        SetCell((x - 3 + rows) % rows, (y + 13) % columns, 1); //X-3 Y+13
        SetCell((x - 3 + rows) % rows, (y + 12) % columns, 1); //X-3 Y+12
        SetCell((x - 2 + rows) % rows, (y + 11) % columns, 1); //X-2 Y+11
        
        SetCell((x - 1 + rows) % rows, (y + 20) % columns, 1); // X-1 Y+20
        SetCell((x - 2 + rows) % rows, (y + 20) % columns, 1); // X-2 Y+20
        SetCell((x - 3 + rows) % rows, (y + 20) % columns, 1); // X-3 Y+20
        SetCell((x - 1 + rows) % rows, (y + 21) % columns, 1); // X-1 Y+21
        SetCell((x - 2 + rows) % rows, (y + 21) % columns, 1); // X-2 Y+21
        SetCell((x - 3 + rows) % rows, (y + 21) % columns, 1); // X-3 Y+21
        SetCell((x - 4 + rows) % rows, (y + 22) % columns, 1);  // X-4 Y+22 
        SetCell((x - 4 + rows) % rows, (y + 24) % columns, 1); // X-4 Y+24
        SetCell((x - 5 + rows) % rows, (y + 24) % columns, 1); // X-5 Y+24
        SetCell(x, (y + 22) % columns, 1); // X Y+22
        SetCell(x, (y + 24) % columns, 1); // X Y+24
        SetCell((x + 1) % rows, (y + 24) % columns, 1); // X+1 Y+24

        SetCell((x - 3 + rows) % rows, (y + 34) % columns, 1);
        SetCell((x - 2 + rows) % rows, (y + 34) % columns, 1);
        SetCell((x - 3 + rows) % rows, (y + 35) % columns, 1);
        SetCell((x - 2 + rows) % rows, (y + 35) % columns, 1);
    }
}