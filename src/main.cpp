#include <raylib.h>
#include "simulation.hpp"
#include <iostream>
#include <cmath>
#include <string>

// Simulation consts
const int MENU_W = 420;
const int WIDTH_W = 1300; // MAX 1920 - 420 = 1500
const int HEIGHT_W = 900; // MAX 1080
const int CELL_DIM = 10;
const int INITIAL_RANDOM_RATE = 5;
const int INITIAL_FRAMERATE = 10;
const int MAX_FRAMERATE = 1000;
const int SUBMAX_FRAMERATE = 640;
const int MIN_FRAMERATE = 5;
const std::string GLIDER_NAME = "GLIDER";
const std::string BLINKER_NAME = "BLINKER";
const std::string DOT_NAME = "DOT";
const std::string GLIDER_GUN = "GLIDER GUN";
const std::string PULSAR_NAME = "PULSAR";

// Simulation variables
int FRAMERATE = INITIAL_FRAMERATE;
int RANDOM_RATE = INITIAL_RANDOM_RATE;
std::string CURRENT_SHAPE = DOT_NAME;
std::string SIMULATION_STATUS = "Initialized";

void DrawControlText() {
    int i=1;
    DrawText("  Controls", WIDTH_W+60, 30*i, 40, WHITE);
    i++;
    DrawText("  ---------", WIDTH_W+60, 30*i, 40, WHITE);
    i+=2;
    // Refresh rate controls
    DrawText("Space : Start/Stop simulation", WIDTH_W+30, 30*i, 20, BLUE);
    i++;
    DrawText("S : Slow down simulation", WIDTH_W+30, 30*i, 20, BLUE);
    i++;
    DrawText("D : Accelerate simulation", WIDTH_W+30, 30*i, 20, BLUE);
    i++;
    DrawText("F : Reset refresh rate", WIDTH_W+30, 30*i, 20, BLUE);
    i+=2;
    // Randomization controls
    DrawText("R : Randomize grid", WIDTH_W+30, 30*i, 20, YELLOW);
    i++;
    DrawText("K : Decrease random rate", WIDTH_W+30, 30*i, 20, YELLOW);
    i++;
    DrawText("L : Increase random rate", WIDTH_W+30, 30*i, 20, YELLOW);
    i++;
    DrawText(("J : Reset random rate to 1/" + std::to_string(INITIAL_RANDOM_RATE)).c_str(), WIDTH_W+30, 30*i, 20, YELLOW);
    i++;
    DrawText("E : Clear grid", WIDTH_W+30, 30*i, 20, YELLOW);
    i+=2;
    // Shape controls
    DrawText("O & P to navigate shapes", WIDTH_W+30, 30*i, 20, WHITE);
    i++;
    DrawText(("     < "+CURRENT_SHAPE+" >     ").c_str(), WIDTH_W+30, 30*i, 20, RED);
    i++;
    DrawText("Left click : Draw shape", WIDTH_W+30, 30*i, 20, GREEN);
    i++;
    DrawText("Right click : Erase dot", WIDTH_W+30, 30*i, 20, GREEN);
    i+=2;

    // Simulation info
    DrawText(("Simulation status : " + SIMULATION_STATUS).c_str(), WIDTH_W + 30, HEIGHT_W - 110, 20, GRAY);
    DrawText(("Current randomization rate : 1/" + std::to_string(RANDOM_RATE)).c_str(), WIDTH_W + 30, HEIGHT_W - 80, 20, GRAY);
    DrawText(("Current refresh rate : " + std::to_string(FRAMERATE) + "/sec").c_str(), WIDTH_W + 30, HEIGHT_W - 50, 20, GRAY);
}

int main()
{
    Color GREY = {29,29,29,255};

    // Initialisation of window
    InitWindow(WIDTH_W + MENU_W, HEIGHT_W, "Game of Life Basic Simulation");
    SetTargetFPS(INITIAL_FRAMERATE);

    Simulation simulation(WIDTH_W, HEIGHT_W, CELL_DIM, RANDOM_RATE);

    /* ------------ Simulation loop ------------*/
    while (WindowShouldClose() == false)
    {   
        // Event Handling 
        if (IsKeyPressed(KEY_R)) {
            // Randomize the grid
            simulation.Randomize();
        }  
        else if (IsKeyPressed(KEY_SPACE)) {
            // Start/Stop simulation
            simulation.SetRunning(!simulation.IsRunning());
            simulation.IsRunning() ? SIMULATION_STATUS = "Running" : SIMULATION_STATUS = "Paused";
        }
        else if (IsKeyPressed(KEY_D)) {
            // Accelerate simulation
            if (FRAMERATE < MAX_FRAMERATE) FRAMERATE = round(FRAMERATE*2) >= MAX_FRAMERATE ? MAX_FRAMERATE : round(FRAMERATE*2), SetTargetFPS(FRAMERATE);
        }
        else if (IsKeyPressed(KEY_S)) {
            // Slow down simulation
            FRAMERATE = (FRAMERATE == MAX_FRAMERATE) ? SUBMAX_FRAMERATE : (FRAMERATE > MIN_FRAMERATE) ? round(FRAMERATE/2) : FRAMERATE;
            SetTargetFPS(FRAMERATE);
        }
        else if (IsKeyPressed(KEY_F)) {
            // Reset refresh rate
            FRAMERATE = INITIAL_FRAMERATE;
            SetTargetFPS(INITIAL_FRAMERATE);
        }
        else if (IsKeyPressed(KEY_E)) {
            // Clear the grid
            simulation.Clear();
        }
        else if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Draw selected shape
            Vector2 mousePos = GetMousePosition();
            simulation.DrawShape(mousePos.y/CELL_DIM, mousePos.x/CELL_DIM);
        }
        else if(IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
            // Erase dot
            Vector2 mousePos = GetMousePosition();
            simulation.SetCell(mousePos.y/CELL_DIM, mousePos.x/CELL_DIM, 0);
        }
        else if (IsKeyPressed(KEY_K)) {
            // Decrease random rate
            RANDOM_RATE++;
            simulation.SetRandomRate(RANDOM_RATE);
        }
        else if (IsKeyPressed(KEY_L)) {
            // Increase random rate
            if (RANDOM_RATE > 1) RANDOM_RATE--, simulation.SetRandomRate(RANDOM_RATE);
        }
        else if (IsKeyPressed(KEY_J)) {
            // Reset random rate
            RANDOM_RATE = INITIAL_RANDOM_RATE;
            simulation.SetRandomRate(RANDOM_RATE);
        }
        else if (IsKeyPressed(KEY_O)) {
            // Navigate shapes right to left
            if (CURRENT_SHAPE == GLIDER_NAME) {
                CURRENT_SHAPE = DOT_NAME;
                simulation.SetShapeIndex(3);
            } else if (CURRENT_SHAPE == BLINKER_NAME) {
                CURRENT_SHAPE = GLIDER_NAME;
                simulation.SetShapeIndex(1);
            } else if (CURRENT_SHAPE == GLIDER_GUN) {
                CURRENT_SHAPE = BLINKER_NAME;
                simulation.SetShapeIndex(2);
            } else if (CURRENT_SHAPE == PULSAR_NAME) {
                CURRENT_SHAPE = GLIDER_GUN;
                simulation.SetShapeIndex(4);
            } else {
                CURRENT_SHAPE = PULSAR_NAME;
                simulation.SetShapeIndex(5);
            }
        }
        else if (IsKeyPressed(KEY_P)) {
            // Navigate shapes left to right
            if (CURRENT_SHAPE == GLIDER_NAME) {
                CURRENT_SHAPE = BLINKER_NAME;
                simulation.SetShapeIndex(2);
            } else if (CURRENT_SHAPE == BLINKER_NAME) {
                CURRENT_SHAPE = GLIDER_GUN;
                simulation.SetShapeIndex(4);
            } else if (CURRENT_SHAPE == GLIDER_GUN) {
                CURRENT_SHAPE = PULSAR_NAME;
                simulation.SetShapeIndex(5);
            } else if (CURRENT_SHAPE == PULSAR_NAME) {
                CURRENT_SHAPE = DOT_NAME;
                simulation.SetShapeIndex(3);
            } else {
                CURRENT_SHAPE = GLIDER_NAME;
                simulation.SetShapeIndex(1);
            }
        }

        // State update
        if (simulation.IsRunning()) {
            simulation.Update();
        }

        // Object drawing
        BeginDrawing();
        DrawControlText();
        ClearBackground(GREY);
        simulation.DrawGrid();
        EndDrawing();
    }

    // Closing window
    CloseWindow();
}

