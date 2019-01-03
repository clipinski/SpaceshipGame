#ifndef PLAYER_SHIP_H
#define PLAYER_SHIP_H

#include <SDL.h>
#include "GameEntity.h"

// Forward declaration of Game
class Game;

//////////////////////////////////////////////////////////////////////////////
// PlayerShip Class
//////////////////////////////////////////////////////////////////////////////
class PlayerShip : public GameEntity
{
protected:

    // Behavior Defines
    const double m_fTurnRate = 2.0;
    const unsigned int m_nBulletFireRate = 500;
    const double m_fDefaultBulletVelocity = 2.0;

    // Control bullet fire speed
    unsigned int m_nLastBulletFireTime = 0;

    // Surface loaded with ship image
    SDL_Surface* m_pShipImage = NULL;

public:

    // Public Interface
    PlayerShip(Game* pGame, int x, int y);
    ~PlayerShip();
    virtual void Update();
    virtual void Render(SDL_Surface* pSurface);
};

#endif