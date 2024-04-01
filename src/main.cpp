#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

int main()
{
    // Simulations consts
    const int WIDTH_W = 1300;
    const int HEIGHT_W = 900;
    const int CELL_DIM = 5;
    const int RANDOM_RATE = 5; // Calculation of random rate = 1/RANDOM_RATE, if negative or 0, no cell will be activated
    const int INITIAL_FPS = 10;
    Color GREY = {29,29,29,255};

    // Initialisation of window
    InitWindow(WIDTH_W, HEIGHT_W, "Game of Life Basic Simulation - Press space to start/stop simulation / R to Randomize");
    SetTargetFPS(INITIAL_FPS);

    //todo implement type of simulation (random, seeded, etc.)
    Simulation simulation(WIDTH_W, HEIGHT_W, CELL_DIM, RANDOM_RATE);
    // simulation.SetCell(10,0,1);
    // simulation.SetCell(9,0,1);
    // simulation.SetCell(11,1,1);
    // simulation.SetCell(10,18,1);
    // simulation.SetCell(9,19,1);

    // std::cout   << simulation.CountLiveNeighbours(10,0) << std::endl;

    /* ------------ Simulation loop ------------*/
    while (WindowShouldClose() == false)
    {   
        // Event Handling 
        if (IsKeyPressed(KEY_R)) {
            simulation.Randomize();
        }  
        else if (IsKeyPressed(KEY_SPACE)) {
            simulation.SetRunning(!simulation.IsRunning());
            simulation.IsRunning() ? SetWindowTitle("GoL Simulation Resumed - Press space to Pause / R to Randomize") : 
                                     SetWindowTitle("GoL Simulation Paused - Press space to Rerun / R to Randomize");
        }

        // State update
        if (simulation.IsRunning()) {
            simulation.Update();
        }

        // Object drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.DrawGrid();
        EndDrawing();
    }

    // Closing window
    CloseWindow();
}