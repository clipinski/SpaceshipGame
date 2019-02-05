# SpaceshipGame
Sample game in C++ and SDL.

## What is this for?
This project is intended to be a learning tool/starting point for anyone interested in game development in C++.  The code contains many comments designed to help a beginner understand how and why the code works.

## How to compile and run under Windows

### Step 1: Install [MinGW](http://www.mingw.org/)

Follow the basic instructions on the MinGW website.  I recommend downloading and running the Graphical User Interface Installer.  In addition to the "base" installation, I recommend installing MSYS.  This will give you a Unix-like command window in which you can compile and run your code.

### Step 2: Install [Simple Direct Media Layer](https://www.libsdl.org/)

Download the Development Library for MinGW and extract the files to your hard drive.   The default directory will look something like this:

    C:\SDL2-2.0.9

### Step 3: Clone this project

When using MingGW and Microsoft Windows, I suggest cloning the project into your MSYS "home" directory.  That will make it much easier to navigate to and compile with MinGW.  The path will look something like this:

    MinGW\msys\1.0\home\<USER NAME>\SpaceshipGame

### Step 4: Edit the makefile

Open the makefile for this project in a text editor.  Ensure the following lines match your installation of SDL as described above:

    #INCLUDE_PATHS specifies the additional include paths we'll need
    INCLUDE_PATHS = -IC:\SDL2-2.0.9\i686-w64-mingw32\include\SDL2

    #LIBRARY_PATHS specifies the additional library paths we'll need
    LIBRARY_PATHS = -LC:\SDL2-2.0.9\i686-w64-mingw32\lib

NOTE: If you installed SDL in the default directory on your C: drive, no changes will be needed.

### Step 5: Copy DLL's

Ensure the following files are either in your PATH or are copied to the SpaceshipGame project directory:

    libgcc_s_dw2-1.dll     -- Originally located in MinGW\bin
    SDL2.dll               -- Originally located in SDL2-2.0.9\x86_64-w64-mingw32\bin\

### Step 6: Build and Run

Once all previous steps have been executed, launch MSYS by running MinGW\msys\1.0\msys.bat.  You will find yourself in your home directory.  If you followed the instructions in Step 3, you should be able to:

    1. Navigate to the SpacehipGame directory by typing: cd SpaceshipGame
    2. Build and Run the game by typing: make all run


## License
[MIT License](https://opensource.org/licenses/MIT)