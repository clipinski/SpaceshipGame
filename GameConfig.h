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
        const int TURN_LEFT      = SDL_SCANCODE_LEFT;
        const int TURN_RIGHT     = SDL_SCANCODE_RIGHT;
        const int FORWARD_THRUST = SDL_SCANCODE_UP;
        const int REVERSE_THRUST = SDL_SCANCODE_DOWN;
    }

    // Player Ship Configuration
    namespace PlayerShip
    {
        const double       TURN_RATE = 2.0;
        const unsigned int BULLET_FIRE_RATE = 500;
        const double       BULLET_VELOCITY = 2.0;
        const double       FORWARD_THRUST_AMT = .05;
        const double       REVERSE_THRUST_AMT = .05;
    }
}

#endif