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
    ~PlayerShip();
    virtual void Update();
    virtual void Render(SDL_Surface* pSurface);
};

#endif