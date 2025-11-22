cmake_minimum_required(VERSION 3.10)
project(GameNexus CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # For better IDE integration

# Add flags for static linking to create a portable executable
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")

# Path to raylib includes and library
set(RAYLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/include")
set(RAYLIB_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/lib")

# Find raylib library
find_library(RAYLIB_LIBRARY raylib PATHS ${RAYLIB_LIB_DIR} NO_DEFAULT_PATH)

if(NOT RAYLIB_LIBRARY)
    message(FATAL_ERROR "raylib library not found! Please check ${RAYLIB_LIB_DIR}/libraylib.a")
endif()

# Collect all source files
set(GAME_SOURCES
    src/GamePROJECT.cpp
    src/Menus.cpp
    src/Utilities.cpp
    src/CoinFlip.cpp
    src/RPS.cpp
    src/GTN.cpp
    src/WordScramble.cpp
    src/NumberMemory.cpp
    src/WormGame.cpp
    src/ScoreS.cpp
    src/Users.cpp
)

# Add the executable
add_executable(GameNexus ${GAME_SOURCES})

# Include directories
target_include_directories(GameNexus PRIVATE
    ${RAYLIB_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link libraries
target_link_libraries(GameNexus PRIVATE
    ${RAYLIB_LIBRARY}
    opengl32
    gdi32
    winmm
)

# Set output directory for the executable
set_target_properties(GameNexus PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
