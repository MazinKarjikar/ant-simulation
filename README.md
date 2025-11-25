# Ant Simulation

SDL2 playground for a 2D ant-inspired simulation. Right now it opens a 680x480 window, animates a small white rectangle across the screen, and draws a filled circle as a placeholder for future visuals. The `Ant` class is stubbed in `src/Ant/` for later movement/behavior work.

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
This generates and compiles the `main` executable in `build/main`. Reconfigure with `-DCMAKE_BUILD_TYPE=Release` if you want an optimized build.

## Run
```bash
./build/main
```
An SDL2 window appears; close the window to exit. The frame delay is ~8ms (~120 FPS target).

## Project layout
- `CMakeLists.txt` — CMake project, finds SDL2 via `pkg-config` and builds the `main` target.
- `src/main.cpp` — SDL2 setup, render loop, and simple animated shapes.
- `src/main.hpp` — shared screen dimension constants.
- `src/Ant/` — early scaffolding for an `Ant` class (movement logic to be filled in).
