cmake_minimum_required(VERSION 3.30)
project(Sokoban VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "-march=native -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-mtune=generic -O2 -Wpedantic")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wfloat-equal -Wundef")
set(THREADS_PREFER_PTHREAD_FLAG ON)

include(GNUInstallDirs)

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
    set(CPACK_NSIS_INSTALLED_ICON_NAME "bin\\\\${CMAKE_PROJECT_NAME}.exe")
    set(CPACK_NSIS_DISPLAY_NAME "${CPACK_PACKAGE_INSTALL_DIRECTORY} ${CMAKE_PROJECT_NAME}")
    set(CPACK_NSIS_HELP_LINK "http:\\\\\\\\www.gitlab.com\\\\GiorgioCaculli\\\\Sokoban-SDL")
    set(CPACK_NSIS_URL_INFO_ABOUT "https:\\\\\\\\www.gitlab.com\\\\GiorgioCaculli\\\\Sokoban-SDL")
    set(CPACK_NSIS_CONTACT "giorgio.caculli@icloud.com")
    set(CPACK_NSIS_MODIFY_PATH ON)
else ()
    set(CPACK_STRIP_FILES "bin/${CMAKE_PROJECT_NAME}")
    set(CPACK_SOURCE_STRIP_FILES "")
endif ()
set(CPACK_PACKAGE_EXECUTABLES "${CMAKE_PROJECT_NAME}" "${CMAKE_PROJECT_DESCRIPTION}")

include(CPack)
include_directories(${Boost_INCLUDE_DIR})
include_directories(include)

find_package(Boost
        COMPONENTS
        date_time
        filesystem
        locale
        log
        unit_test_framework
        REQUIRED CONFIG)

find_package(SDL3)
find_package(SDL3_image)

file(COPY src/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/main.hpp
        src/core/actor.cpp
        src/core/movable.cpp
        src/core/box.cpp
        src/core/player.cpp
        src/core/platform.cpp
        src/core/wall.cpp
        src/core/board.cpp)

include(FindPkgConfig)

include_directories(${Boost_INCLUDE_DIR} ${SDL3_INCLUDE_DIRS} ${SDL3_Image_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${SDL3_LIBRARIES} ${SDL3_Image_LIBRARIES})
