cmake_minimum_required(VERSION 3.30)
project(Sokoban VERSION 1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost COMPONENTS date_time locale log filesystem REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp src/main.hpp src/core/actor.cpp src/core/actor.hpp src/core/movable.cpp src/core/movable.hpp src/core/box.cpp src/core/box.hpp src/core/player.cpp src/core/player.hpp src/core/platform.cpp src/core/platform.hpp src/core/wall.cpp src/core/wall.hpp src/core/board.cpp src/core/board.hpp)

include(FindPkgConfig)

pkg_search_module(SDL3 REQUIRED sdl3)
pkg_search_module(SDL3_Image REQUIRED sdl3_image)

include_directories(${SDL3_INCLUDE_DIRS} ${SDL3_Image_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} ${SDL3_LIBRARIES} ${SDL3_Image_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
