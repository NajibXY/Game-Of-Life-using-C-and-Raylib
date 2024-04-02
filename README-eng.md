# C++ Game of Life Simulation with Raylib Library

## Author: [Najib El khadir](https://github.com/NajibXY)

## 1. Motivations

<img align="right" src="https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/main.gif">

The Game of Life stands as one of the most striking examples in developmental AI due to the contrast between the simplicity of the initial rules imposed on agents and the complexity of emerging behaviors. 
It remains a cornerstone for anything related to emergent behaviors and bio-inspired intelligent systems, as well as a fascinating visual introduction to AI currents that are slightly less fashionable these days. 
Therefore, I was eager to start my series of projects for April 2024 with this classic.

## 2. Technologies Used

- C++14
- Raylib Library for game development: I've been meaning to test this user-friendly library for a while, which offers very good tools for developing 2D games (and more generally interfaces).
- The template used for the Raylib project configuration comes from this repository: https://github.com/educ8s/Raylib-CPP-Starter-Template-for-VSCODE-V2

## 3. Simulation Rules

- Underpopulation: If the cell is alive and has fewer than two live neighbors, it dies in the next iteration.
- Stasis: If the cell is alive and has 2 or 3 live neighbors, it remains alive in the next iteration.
- Overpopulation: If the cell is alive and has more than three live neighbors, it dies in the next iteration.
- Reproduction: If the cell is inactive and has exactly 3 live neighbors, it becomes alive in the next iteration.

## 4. Implemented Features

- Grid randomization (Key R)
- Grid clearing (Key E)
- Acceleration and deceleration of simulation (Keys S, D & F)
- Pause/Resume simulation (Space Key)
- Play one step (Key G)
- Modify randomization rate (Keys K, L & J)  
![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/randomization.gif)

### Implemented Patterns and Oscillators

- It is also possible to manually activate and deactivate cells with mouse clicks.
  
- The following predefined patterns have been implemented (navigation for selecting shapes to draw is done with keys O & P):
  + The Dot (for customized shapes):  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/dot.gif)

  + The Glider: https://conwaylife.com/wiki/Glider  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/glider.gif)

  + The Blinker: https://conwaylife.com/wiki/Blinker  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/blinker.gif)

  + The Gosper Glider Gun: https://conwaylife.com/wiki/Gosper_glider_gun  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/glider-gun.gif)
    
  + The Pulsar: https://conwaylife.com/wiki/Pulsar  
      ![](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/gifs/pulsar.gif)

## 5. Possible Improvements

- Customization of grid size
- Customization of initial grid with a seed file
- Memorization of steps and backward step-by-step playback
- Saving a run from initialization to stabilization
- Implementation of more oscillators and shapes
- Implementation of variations of the Game of Life (different rules, different dimensionality, and properties of space): https://conwaylife.com/wiki/Conway%27s_Game_of_Life#Variations_on_Life

## 6. Running the Project

- If you simply want to play with the simulation, you can download the .exe from the main repository: [game_of_life.exe](https://github.com/NajibXY/Game-Of-Life-using-CPP-and-Raylib/blob/master/game_of_life.exe)
  
### Prerequisites

- C++ installation (preferably 14)
- Raylib for C++ installation: https://www.raylib.com/

## Compilation, Duplication, and Improvement of the Project

- Download or fork the project
- Open the project in VS Code via the main.code-workspace file
- Press F5 to compile and run
- From there, you can make any modifications you want to the project fork.
