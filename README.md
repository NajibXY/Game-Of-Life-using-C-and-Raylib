# Game Of Life using C++ and Raylib

## TODO

# 1. Basic Game of Life rules 

- Underpopulation : 1 && alive nighbors < 2 -> 0
- Statis : 1 && alive nighbors in (2,3) -> 1
- Overpopulation : 1 && alive nighbors > 3 -> 0
- Reproduction : 0 && alive nighbors == 3 -> 1

# 2. Basic Shapes & Oscillators implemented

- Dot (for custom shapes)
- Glider https://conwaylife.com/wiki/Glider
- Blinker (Randomly between vertical blinker, horizontal blinker, angel blinker and another type of blinkers) https://conwaylife.com/wiki/Blinker
- Gosper glider gun https://conwaylife.com/wiki/Gosper_glider_gun
- Basic Pulsar https://conwaylife.com/wiki/Pulsar


# 2. Possible upgrades

- Seed input
- Grid size modification
- Step backward
- Memorize steps
- Save run
- Add more shapes
- Add variations of Game of Life