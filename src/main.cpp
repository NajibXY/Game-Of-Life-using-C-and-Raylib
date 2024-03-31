#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

int main()
{
    // Simulations consts
    const int WIDTH_W = 1300;
    const int HEIGHT_W = 900;
    const int CELL_DIM = 5;
    const int INITIAL_FPS = 10;
    Color GREY = {29,29,29,255};

    // Initialisation of window
    InitWindow(WIDTH_W, HEIGHT_W, "Game of Life Basic Simulation");
    SetTargetFPS(INITIAL_FPS);

    Simulation simulation(WIDTH_W, HEIGHT_W, CELL_DIM);
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

        // State update
    
        simulation.Update();

        // Object drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.DrawGrid();
        EndDrawing();
    }

    // Closing window
    CloseWindow();
}