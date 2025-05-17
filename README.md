# Spaceship Game

## Prerequisites for macOS

These installation instructions are specifically for macOS users. For other operating systems, please refer to the appropriate section below.

### Required Libraries for macOS
    # Install SDL2 and additional SDL2 libraries
    brew install sdl2
    brew install sdl2_image
    brew install sdl2_ttf
    brew install sdl2_mixer

### Build Requirements for macOS
- clang++ compiler (included with macOS)
- make (included with macOS Command Line Tools)
- Homebrew package manager (for installing SDL2 libraries)

If you don't have Homebrew installed, install it first:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
---

## Prerequisites for Linux/Ubuntu

### Required Libraries for Linux/Ubuntu

Open a terminal and run:

    sudo apt update
    sudo apt install build-essential clang make libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev

This installs:
- `clang` (C++ compiler)
- `make` (build tool)
- SDL2 libraries and development headers required to build and run the game

---

## Building the Game

To build the game, simply run:

    make

To run the game:

    make run

To clean build files:

    make clean

---

## Development Notes
- The game is built using C++11 standard
- Compilation includes debug symbols (`-g` flag)
- All warning flags are enabled (`-Wall -Wextra`)

---

## Other Operating Systems

### Windows
Installation instructions for Windows will be provided soon.

---

## License

[MIT License](https://opensource.org/licenses/MIT)
