# Ant Simulation

SDL2 playground for a 2D ant-inspired simulation. The program opens a 1500x800 window, spawns a small swarm of ants at the center, and has them wander with a random heading and slight Gaussian noise on their direction each frame. Ants are rendered as small filled circles.

## Prerequisites
- CMake 3.15+ and a C++17 compiler (clang++/g++).
- SDL2 development libraries plus `pkg-config` so CMake can locate SDL2.
- Install hints:
  - macOS (Homebrew): `brew install sdl2 pkg-config`
  - Ubuntu/Debian: `sudo apt install libsdl2-dev pkg-config cmake build-essential`

## Build
From the repository root:
```bash
cmake -S . -B build
cmake --build build
```
This builds the `main` executable in `build/main`. Add `-DCMAKE_BUILD_TYPE=Release` for an optimized build.

## Run
```bash
./build/main
```
An SDL2 window appears and the ants begin moving. Close the window to exit.

## Project layout
- `CMakeLists.txt` — CMake project, finds SDL2 via `pkg-config` and builds the `main` target.
- `src/main.cpp` — entry point; instantiates and runs the simulation.
- `src/main.hpp` — shared screen dimension constants (`SCREEN_WIDTH`/`SCREEN_HEIGHT`).
- `src/Simulation/` — `Simulation<Count>` template that owns ants, SDL window/renderer, update/render loop.
- `src/Ant/` — `Ant` class with simple random-walk movement.
- `src/AntRenderer/` — drawing helpers for ants (filled circle rendering).
- `src/util/` — miscellaneous helpers (e.g., distance to screen border).
