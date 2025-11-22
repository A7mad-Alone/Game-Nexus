# The Game Nexus

## Project Status: ABANDONED

A collection of classic and new mini-games, all accessible through a single terminal-based UI. This project was developed as a C++ course project, designed to be modular and extensible.

---

## Table of Contents

1.  [Overview](#overview)
2.  [Features](#features)
3.  [Requirements](#requirements)
4.  [Setup Instructions](#setup-instructions)
5.  [Version History](#version-history)
6.  [Notes](#notes)
7.  [Contributors](#contributors)
8.  [Contributing](#contributing)
9.  [License](#license)

---

## Overview

The Game Nexus is a C++ console application that serves as a central hub for various mini-games. It features a main menu for game selection and aims for modularity, allowing easy integration of new games. The project was originally developed under tight constraints, leading to a focus on core functionality and a streamlined architecture.

## Features

*   **Modular Game Integration:** New games can be easily added by creating `.h/.cpp` pairs and integrating them into the main menu.
*   **Included Games:**
    *   **Worm Game:** A classic snake game, built using the `raylib` library for graphics and audio.
    *   **Word Scramble:** A word-guessing game with multiple difficulty levels.
    *   **Number Memory Game:** A memory challenge where players recall sequences of numbers.
    *   **Coin Flip:** A simple, quick coin toss game.
    *   **Rock Paper Scissors:** The timeless hand game.
    *   **Guess The Number:** A number guessing game with a customizable range.
*   **User-Friendly Interface:** Text-based menus with input validation for smooth navigation.
*   **Cross-Platform Build (via CMake):** Configured for easy compilation on Windows using MSYS2.

## Requirements

### To Run the Executable (`GameNexus.exe`)
*   Windows Operating System (The executable is statically linked, so no external DLLs are needed).

### To Build the Project from Source (Windows with MSYS2)
*   **MSYS2 Environment:**
    *   [MSYS2](https://www.msys2.org/) installed on your system.
    *   Within the **MSYS2 UCRT64 terminal**, you need the MinGW-w64 toolchain and CMake. Install them using:
        ```sh
        pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
        pacman -S mingw-w64-ucrt-x86_64-cmake
        ```
*   **C++ Compiler:** (Provided by the MinGW-w64 toolchain, e.g., g++).
*   **CMake:** (Installed via pacman).
*   **raylib Library:** (Included in this repository under `src/lib/` and `src/include/`).

---

## Setup Instructions

To build and run the Game Nexus from source:

1.  **Clone the Repository:**
    ```bash
    git clone https://github.com/A7mad-Alone/Game-Nexus.git
    cd Game-Nexus
    ```

2.  **Open MSYS2 UCRT64 Terminal:**
    Launch the **"MSYS2 UCRT64"** terminal from your Windows Start Menu.

3.  **Navigate to Project Root:**
    In the MSYS2 UCRT64 terminal, change your directory to the root of the cloned repository (e.g., `cd /c/Users/YourUser/path/to/Game-Nexus`).

4.  **Generate Build Files:**
    Run CMake to generate the build system (Makefiles):
    ```sh
    cmake -B build -G "MinGW Makefiles"
    ```

5.  **Compile the Project:**
    Build the executable:
    ```sh
    cmake --build build
    ```

6.  **Run the Game:**
    The compiled executable (`GameNexus.exe`) will be located in `src/`.
    ```sh
    ./src/GameNexus.exe
    ```

---

## Version History

### V1.0 - Initial Release (November 2025)
*   **Overview:** First public release of the Game Nexus, featuring multiple integrated mini-games and a modular C++ architecture.
*   **Features:** Includes Worm Game, Word Scramble, Number Memory, Coin Flip, Rock Paper Scissors, and Guess The Number.
*   **Improvements:** Refactored codebase for modularity, unified build system using CMake, asset path handling for portability, and comprehensive code documentation.
*   **Notes:** The initial project was created back in December 2024, a year ago. I've only recently had the time to organize and refactor it with AI assistance.

---

## Notes

*   **College Project:** This project was initially created as part of coursework. While functional, it serves as a foundation with planned future enhancements.
*   **Development Story:** The project was developed under a tight 72-hour deadline by a team of three. Early design ambitions (detailed in `src/Game Plan/`) were scoped down due to time constraints, prioritizing a working core over all planned features like a full user and score saving system.
*   **AI Assistance:** This project benefited from AI assistance in aspects of code organization, refactoring, and documentation generation.
*   **Suggestions for Future Versions:** Future plans include implementing a persistent user and scoring system, adding more games, and further UI/UX improvements.
*   **Project Status:** This project is abandoned and is likely to not get updated anytime soon.

---

## Contributors

*   **Ahmad Adham**
*   **Eslam Mohammed**
*   **Ali Abdel-Nasser**

---

## Contributing

Contributions are welcome! If you'd like to contribute, please fork the repository and create a pull request with your changes. Ensure your contributions align with the project's goals and coding standards.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details (or implied by common open-source practices).

---

Thank you for checking out The Game Nexus!
