# Spaceship Game

## Prerequisites for macOS

These installation instructions are specifically for macOS users. For other operating systems, please refer to the appropriate section below.

### Required Libraries for macOS
```bash
# Install SDL2 and additional SDL2 libraries
brew install sdl2
brew install sdl2_image
brew install sdl2_ttf
brew install sdl2_mixer
```

### Build Requirements for macOS
- clang++ compiler (included with macOS)
- make (included with macOS Command Line Tools)
- Homebrew package manager (for installing SDL2 libraries)

If you don't have Homebrew installed, install it first:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

## Building the Game

To build the game, simply run:
```bash
make
```

To run the game:
```bash
make run
```

To clean build files:
```bash
make clean
```

## Development Notes
- The game is built using C++11 standard
- Compilation includes debug symbols (-g flag)
- All warning flags are enabled (-Wall -Wextra)

## Other Operating Systems

### Linux
Installation instructions for Linux will be provided soon.

### Windows
Installation instructions for Windows will be provided soon.

## License
[MIT License](https://opensource.org/licenses/MIT)
