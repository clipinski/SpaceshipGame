///////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2019, 2025 Craig J. Lipinski
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

#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include <SDL.h>
#include "GameEntity.h"

// Forward declaration of Game
class Game;

//////////////////////////////////////////////////////////////////////////////
// PlayerBullet Class
//////////////////////////////////////////////////////////////////////////////
class PlayerBullet : public GameEntity
{
private:
    // Explicit x/y velocity components for bullet movement.
    double m_velocityX;
    double m_velocityY;

    // Lifetime bookkeeping.
    unsigned int m_spawnTimeMs;
    unsigned int m_lifetimeMs;

    // Used to step the color pulse animation.
    unsigned int m_pulseFrameCounter;

public:
    PlayerBullet(Game* pGame,
                 int x,
                 int y,
                 double rotationAngleDegrees,
                 double shipVelocityX,
                 double shipVelocityY);

    virtual ~PlayerBullet() override = default;
    virtual void Update() override;
    virtual void Render(SDL_Surface* pSurface) override;
};

#endif
