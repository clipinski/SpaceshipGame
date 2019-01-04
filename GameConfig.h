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