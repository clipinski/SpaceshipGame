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

    // Internal Helpers
    double GetRotationAngleInRads();
    void HandleWrapAround();

public:

    // Main interface
    virtual void Render(SDL_Surface* pSurface) = 0;
    virtual void Update();
    bool IsAlive();
    void Kill();
    GameEntity(Game* pGame, int x, int y);
    virtual ~GameEntity() = default;

};

#endif
