#include <raylib.h>
#include "grid.hpp"

int main()
{
    // Simulations consts
    const int WIDTH_W = 500;
    const int HEIGHT_W = 500;
    const int CELL_DIM = 25;
    const int INITIAL_FPS = 10;
    Color GREY = {29,29,29,255};

    // Initialisation of window
    InitWindow(WIDTH_W, HEIGHT_W, "Game of Life Basic Simulation");

    SetTargetFPS(INITIAL_FPS);

    Grid grid(WIDTH_W, HEIGHT_W, CELL_DIM);

    /* ------------ Simulation loop ------------*/
    while (WindowShouldClose() == false)
    {
        // Event Handling   

        // State update

        // Object drawing
        BeginDrawing();
        ClearBackground(GREY);
        grid.DrawGrid();
        EndDrawing();
    }

    // Closing window
    CloseWindow();
}