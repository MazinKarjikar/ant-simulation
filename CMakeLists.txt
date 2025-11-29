cmake_minimum_required(VERSION 3.15)
project(SDL2Demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SDL2 via pkg-config (preferred)
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)

link_directories(${SDL2_LIBRARY_DIRS})

add_executable(main
    src/main.cpp
    src/Ant/Ant.cpp
    src/AntRenderer/AntRenderer.cpp
)

target_include_directories(main PRIVATE
    ${SDL2_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(main ${SDL2_LIBRARIES})
