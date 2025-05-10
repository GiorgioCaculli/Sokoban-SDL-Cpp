# Sokoban Game written in C++11 and SDL2

## Authors:
- Giorgio Caculli

## Dependencies
- SDL2
- SDL2 gfx
- SDL2 image
- SDL2 mixer
- SDL2 net
- SDL2 ttf
- Boost

## Build Tools:
- Autotools
- CMake

## Building Instructions:

### Autotools
1. mkdir build
2. cd build
3. autoreconf -fiv ../Sokoban
4. ../Sokoban/configure
5. make

### CMake
1. mkdir build
2. cd build
3. cmake ../Sokoban
4. make
