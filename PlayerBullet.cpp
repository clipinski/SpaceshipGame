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

#include <math.h>
#include "PlayerBullet.h"
#include "GameConfig.h"

//////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////
PlayerBullet::PlayerBullet(Game* pGame,
                           int x,
                           int y,
                           double rotationAngleDegrees,
                           double shipVelocityX,
                           double shipVelocityY) : GameEntity(pGame, x, y)
{
    m_rotationAngle = rotationAngleDegrees;

    const double angleRadians = rotationAngleDegrees * M_PI / 180.0;
    const double dirX = cos(angleRadians);
    const double dirY = sin(angleRadians);

    m_velocityX = (dirX * GameConfig::PlayerBullet::VELOCITY) +
                  (shipVelocityX * GameConfig::PlayerBullet::SHIP_VELOCITY_INFLUENCE);
    m_velocityY = (dirY * GameConfig::PlayerBullet::VELOCITY) +
                  (shipVelocityY * GameConfig::PlayerBullet::SHIP_VELOCITY_INFLUENCE);

    m_spawnTimeMs = SDL_GetTicks();
    m_lifetimeMs = GameConfig::PlayerBullet::LIFETIME_MS;
    m_pulseFrameCounter = 0;
}

//////////////////////////////////////////////////////////////////////////
// Update
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerBullet::Update()
{
    // Bullet movement uses x/y velocity components and does not wrap around.
    m_X += m_velocityX;
    m_Y += m_velocityY;

    // Advance pulse animation.
    m_pulseFrameCounter++;

    // Kill this bullet once its lifetime expires.
    if ((SDL_GetTicks() - m_spawnTimeMs) >= m_lifetimeMs)
    {
        Kill();
    }
}

//////////////////////////////////////////////////////////////////////////
// Render
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerBullet::Render(SDL_Surface* pSurface)
{
    const int pulseStep = (m_pulseFrameCounter / GameConfig::PlayerBullet::PULSE_STEP_FRAMES) % 4;

    Uint8 red = 255;
    Uint8 green = 255;
    Uint8 blue = 255;

    switch (pulseStep)
    {
        case 1:
            green = 245;
            blue = 120;
            break;
        case 2:
            green = 180;
            blue = 60;
            break;
        case 3:
            green = 245;
            blue = 120;
            break;
        default:
            break;
    }

    const Uint32 bulletColor = SDL_MapRGB(pSurface->format, red, green, blue);
    const int nSize = GameConfig::PlayerBullet::SIZE_PX;
    const int drawX = static_cast<int>(m_X) - (nSize / 2);
    const int drawY = static_cast<int>(m_Y) - (nSize / 2);

    // Draw a compact rounded-ish 6x6 shape: 4x4 core with small edge caps.
    SDL_Rect coreRect = { drawX + 1, drawY + 1, 4, 4 };
    SDL_Rect topCap = { drawX + 2, drawY, 2, 1 };
    SDL_Rect bottomCap = { drawX + 2, drawY + 5, 2, 1 };
    SDL_Rect leftCap = { drawX, drawY + 2, 1, 2 };
    SDL_Rect rightCap = { drawX + 5, drawY + 2, 1, 2 };

    SDL_FillRect(pSurface, &coreRect, bulletColor);
    SDL_FillRect(pSurface, &topCap, bulletColor);
    SDL_FillRect(pSurface, &bottomCap, bulletColor);
    SDL_FillRect(pSurface, &leftCap, bulletColor);
    SDL_FillRect(pSurface, &rightCap, bulletColor);
}
