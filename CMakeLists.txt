cmake_minimum_required(VERSION 3.30)
project(GioSokobanSDL VERSION 0.1 DESCRIPTION "Giorgio's Sokoban Written in SDL3")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "-march=native -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-mtune=generic -O2 -Wpedantic")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wfloat-equal -Wundef")
set(THREADS_PREFER_PTHREAD_FLAG ON)

include(GNUInstallDirs)
include(CPack)
include(FindPkgConfig)
include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${CMAKE_PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_VENDOR "Giorgio Caculli")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md")
set(CPACK_PACKAGE_VERSION_MAJOR ${CMAKE_PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${CMAKE_PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${CMAKE_PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
if (WIN32 AND NOT UNIX)
    # There is a bug in NSI that does not handle full UNIX paths properly.
    # Make sure there is at least one set of four backlashes.
    set(CPACK_PACKAGE_ICON "${CMake_SOURCE_DIR}/Utilities/Release\\\\InstallIcon.bmp")
    set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\SokobanSDL.exe")
    set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} SokobanSDL")
    set(CPACK_NSIS_HELP_LINK "http:\\\\\\\\www.gitlab.com\\\\GiorgioCaculli\\\\Sokoban-SDL-CPP")
    set(CPACK_NSIS_URL_INFO_ABOUT "https:\\\\\\\\www.gitlab.com\\\\GiorgioCaculli\\\\Sokoban-SDL-Cpp")
    set(CPACK_NSIS_CONTACT "giorgio.caculli@icloud.com")
    set(CPACK_NSIS_MODIFY_PATH ON)
else ()
    set(CPACK_STRIP_FILES "bin/SokobanSDL")
    set(CPACK_SOURCE_STRIP_FILES "")
endif ()
set(CPACK_PACKAGE_EXECUTABLES "SokobanSDL" "${CMAKE_PROJECT_DESCRIPTION}")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)

find_library(GZC_UTIL_LOGGER util_logger REQUIRED)
find_library(GZC_UTIL_SERIALIZE util_serialize REQUIRED)
find_library(GZC_GAMES_SOKOBAN sokoban_core REQUIRED)

file(COPY src/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(include)

include_directories(${SDL3_INCLUDE_DIRS} ${SDL3_image_INCLUDE_DIRS} ${GZC_GAMES_SOKOBAN_INCLUDE_DIRS})

add_executable(SokobanSDL
        src/main.cpp
        src/gui/Window.cpp
        src/gui/Menu.cpp
        src/gui/MenuPause.cpp
        src/gui/MenuSettings.cpp)

target_link_libraries(SokobanSDL ${SDL3_LIBRARIES} SDL3_image::SDL3_image SDL3_ttf::SDL3_ttf ${GZC_UTIL_LOGGER} ${GZC_UTIL_SERIALIZE} ${GZC_GAMES_SOKOBAN})
