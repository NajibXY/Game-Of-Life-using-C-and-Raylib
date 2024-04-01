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
        {(x-1 + grid.GetColumns()) % grid.GetColumns(), (y-1 + grid.GetRows()) % grid.GetRows()},
        {x, (y-1 + grid.GetRows()) % grid.GetRows()},
        {(x+1) % grid.GetColumns(), (y-1 + grid.GetRows()) % grid.GetRows()},
        {(x-1 + grid.GetColumns()) % grid.GetColumns(), y},
        {(x+1) % grid.GetColumns(), y},
        {(x-1 + grid.GetColumns()) % grid.GetColumns(), (y+1) % grid.GetRows()},
        {x, (y+1) % grid.GetRows()},
        {(x+1) % grid.GetColumns(), (y+1) % grid.GetRows()}
    };

    // Loop through the neighbours
    for (int i = 0; i < 8; i++) {
        // Get the coordinates of the neighbour and its value
        liveNeighbours += grid.GetCell(neighbourCoordinates[i][0], neighbourCoordinates[i][1]);
    }

    // Return the number of live neighbours
    return liveNeighbours;
}

void Simulation::Update() {
    // Create a new grid to store the updated values
    Grid newGrid = grid;

    // Loop through the cells in the grid
    for (int i = 0; i < grid.GetRows(); i++) {
        for (int j = 0; j < grid.GetColumns(); j++) {
            // Get the number of live neighbours for the cell
            int liveNeighbours = CountLiveNeighbours(i, j);

            // Update the cell value based on the rules of the Game of Life
            if (grid.GetCell(i, j) == 0) {
                if (liveNeighbours == 3) {
                    // Reproduction
                    newGrid.SetCell(i, j, 1);
                } else {
                    // No change
                    newGrid.SetCell(i, j, 0);
                }
            } else {
                if (liveNeighbours + grid.GetCell(i, j) < 3 || liveNeighbours + grid.GetCell(i, j)  > 4) {
                    // Underpopulation and Overpopulation
                    newGrid.SetCell(i, j, 0);
                } else {
                    // Survival
                    newGrid.SetCell(i, j, grid.GetCell(i, j));
                }
            }
        }
    }

    // Update the grid with the new values
    grid = newGrid;
}

void::Simulation::SetRunning(bool value) {
    // Set the running state of the simulation
    running = value;
}