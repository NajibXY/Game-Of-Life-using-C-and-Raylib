#include <raylib.h>
#include "simulation.hpp"
#include <iostream>
#include <cmath>

int main()
{
    // Simulations consts
    const int WIDTH_W = 1300;
    const int HEIGHT_W = 900;
    const int CELL_DIM = 20;
    const int RANDOM_RATE = 5; // Calculation of random rate = 1/RANDOM_RATE, if negative or 0, no cell will be activated
    const int INITIAL_FRAMERATE = 10;
    int FRAMERATE = INITIAL_FRAMERATE;
    Color GREY = {29,29,29,255};

    // Initialisation of window
    //todo create string for settings and add it constantly to the window title or check for a panel to display settings & inputs
    InitWindow(WIDTH_W, HEIGHT_W, "Game of Life Basic Simulation - Press space to start/stop simulation / R to Randomize / D to Accelerate / S to Slow down / F to Reset speed / E to Clear grid");
    SetTargetFPS(INITIAL_FRAMERATE);

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
            simulation.IsRunning() ? SetWindowTitle("GoL Simulation Resumed - Press space to Pause / R to Randomize / D to Accelerate / S to Slow down / F to Reset speed / E to Clear grid") : 
                                     SetWindowTitle("GoL Simulation Paused - Press space to Rerun / R to Randomize / D to Accelerate / S to Slow down / F to Reset speed / E to Clear grid");
        }
        else if (IsKeyPressed(KEY_D)) {
            int newFramerate = round(FRAMERATE*2);
            if (newFramerate == 4) {
                newFramerate = 5;
            }
            if (newFramerate > 0) {
                FRAMERATE = newFramerate;
                SetTargetFPS(FRAMERATE);
            }
        }
        else if (IsKeyPressed(KEY_S)) {
            int newFramerate = round(FRAMERATE/2);
            if (newFramerate > 1) {
                FRAMERATE = newFramerate;
                SetTargetFPS(FRAMERATE);
            }
        }
        else if (IsKeyPressed(KEY_F)) {
            FRAMERATE = INITIAL_FRAMERATE;
            SetTargetFPS(INITIAL_FRAMERATE);
        }
        else if (IsKeyPressed(KEY_E)) {
            simulation.Clear();
        }
        else if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            simulation.SetCell(mousePos.y/CELL_DIM, mousePos.x/CELL_DIM, 1);
        }
        else if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            Vector2 mousePos = GetMousePosition();
            simulation.SetCell(mousePos.y/CELL_DIM, mousePos.x/CELL_DIM, 0);
        }
        //todo hold mouse button to draw cells
        // TODO implement bigger size of grid and lower

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