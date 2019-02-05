///////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2019 Craig J. Lipinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
///////////////////////////////////////////////////////////////////////////////////

#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <SDL.h>

//////////////////////////////////////////////////////////////////////////////
// GameConfig
//
// This file contains settings used to tweak the game.
//////////////////////////////////////////////////////////////////////////////
namespace GameConfig
{
    // Main Game Configuration
    namespace Game
    {
        const int WINDOW_WIDTH = 1280;
        const int WINDOW_HEIGHT = 720;
    }

    // Game Controls
    namespace Controls
    {
        const int TURN_LEFT      = SDL_SCANCODE_A;
        const int TURN_RIGHT     = SDL_SCANCODE_S;
        const int FORWARD_THRUST = SDL_SCANCODE_SEMICOLON;
        const int REVERSE_THRUST = SDL_SCANCODE_SPACE;
        const int FIRE           = SDL_SCANCODE_APOSTROPHE;
    }

    // Player Ship Configuration
    namespace PlayerShip
    {
        const double       TURN_RATE = 2.0;
        const unsigned int BULLET_FIRE_RATE = 500;
        const double       BULLET_VELOCITY = 2.0;
        const double       FORWARD_THRUST_AMT = .05;
        const double       REVERSE_THRUST_AMT = .05;
        const int          ENGINES_ON_ANIMATION_FRAMES = 2;
    }
}

#endif