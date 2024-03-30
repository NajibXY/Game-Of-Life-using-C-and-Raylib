#include <raylib.h>

int main()
{
    // Simulations consts
    const int WIDTH_W = 500;
    const int HEIGHT_W = 500;
    const int INITIAL_FPS = 10;
    Color FULL_BLACK = {0 ,0 ,0 ,255 };

    // Initialisation of window
    InitWindow(WIDTH_W, HEIGHT_W, "Game of Life Basic Simulation");

    SetTargetFPS(INITIAL_FPS);

    /* ------------ Simulation loop ------------*/
    while (WindowShouldClose() == false)
    {
        // Event Handling   

        // State update

        // Object drawing
        BeginDrawing();
        ClearBackground(FULL_BLACK);
        EndDrawing();
    }

    // Closing window
    CloseWindow();
}