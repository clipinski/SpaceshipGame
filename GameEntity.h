#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

// Forward declaration of Game
class Game;

//////////////////////////////////////////////////////////////////////////////
// GameEntity Class
//
// Absttact Base class for all game "entities" - ie objects that make up 
//   game play.
//////////////////////////////////////////////////////////////////////////////
class GameEntity
{
protected:

    // Location
    double m_X;
    double m_Y;

    // "Alive" Flag
    bool m_bIsAlive;

    // Pointer back to the game
    Game* m_pGame;

    // Allow every game enitity the ability to move
    double m_velocity;
    double m_rotationAngle;  // In Degrees

public:

    // Main interface
    virtual void Render(SDL_Surface* pSurface) = 0;
    virtual void Update();
    bool IsAlive();
    void Kill();
    GameEntity(Game* pGame, int x, int y);

};

#endif