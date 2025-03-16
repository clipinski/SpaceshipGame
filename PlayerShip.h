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

#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include <SDL.h>
#include "GameEntity.h"
#include "AnimImage.h"

// Forward declaration of Game
class Game;

//////////////////////////////////////////////////////////////////////////////
// PlayerShip Class
//////////////////////////////////////////////////////////////////////////////
class PlayerShip : public GameEntity
{
protected:
    // Ship image
    const int SHIP_IMAGE_WIDTH = 63;
    const int SHIP_IMAGE_HEIGHT = 63;
    const int SHIP_IMAGE_NUM_FRAMES= 72;

    // Values for specific ship movement style
    double m_velocityX;
    double m_velocityY;

    // Control bullet fire speed
    unsigned int m_nLastBulletFireTime;

    // Used for displaying engines animation
    bool m_bEnginesOn;
    unsigned int m_nEnginesOnFrameCounter;

    // Surface loaded with ship image
    AnimImage* m_pShipImage;
    AnimImage* m_pShipImagesThrusting[3];

    // Internal Helpers
    void HandleUserInput();

public:

    // Public Interface
    PlayerShip(Game* pGame, int x, int y);
    virtual ~PlayerShip() override;
    virtual void Update() override;
    virtual void Render(SDL_Surface* pSurface) override;
};

#endif
