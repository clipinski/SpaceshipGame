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
    const char * SHIP_IMAGE_PATH = "gfx/00ShipFrames1.bmp";
    const int SHIP_IMAGE_WIDTH = 63;
    const int SHIP_IMAGE_HEIGHT = 63;
    const int SHIP_IMAGE_NUM_FRAMES= 72;

    // Control bullet fire speed
    unsigned int m_nLastBulletFireTime = 0;

    // Surface loaded with ship image
    AnimImage* m_pShipImage = NULL;

public:

    // Public Interface
    PlayerShip(Game* pGame, int x, int y);
    ~PlayerShip();
    virtual void Update();
    virtual void Render(SDL_Surface* pSurface);
};

#endif