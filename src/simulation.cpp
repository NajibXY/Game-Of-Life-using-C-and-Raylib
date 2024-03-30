#include "simulation.hpp"

// Implement the DrawGrid method
void Simulation::DrawGrid() {
    grid.DrawGrid();
}

// Implement the SetCell method
void Simulation::SetCell(int x, int y, int value) {
    // Set the value of the cell at (x, y) in the grid
    grid.SetCell(x, y, value);
}

int Simulation::CountLiveNeighbours(int x, int y) {
    // Define the number of live neighbours
    int liveNeighbours = 0;

    // Define the coordinates of the neighbours in a TOROIDAL grid
    int neighbourCoordinates[8][2] = {
        {(x-1 + grid.getColumns()) % grid.getColumns(), (y-1 + grid.getRows()) % grid.getRows()},
        {x, (y-1 + grid.getRows()) % grid.getRows()},
        {(x+1) % grid.getColumns(), (y-1 + grid.getRows()) % grid.getRows()},
        {(x-1 + grid.getColumns()) % grid.getColumns(), y},
        {(x+1) % grid.getColumns(), y},
        {(x-1 + grid.getColumns()) % grid.getColumns(), (y+1) % grid.getRows()},
        {x, (y+1) % grid.getRows()},
        {(x+1) % grid.getColumns(), (y+1) % grid.getRows()}
    };

    // Loop through the neighbours
    for (int i = 0; i < 8; i++) {
        // Get the coordinates of the neighbour and its value
        liveNeighbours += grid.GetCell(neighbourCoordinates[i][0], neighbourCoordinates[i][1]);
    }

    // Return the number of live neighbours
    return liveNeighbours;
}