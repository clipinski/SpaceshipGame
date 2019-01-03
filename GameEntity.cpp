#include <math.h>
#include "Game.h"
#include "GameEntity.h"

//////////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////////
GameEntity::GameEntity(Game* pGame, int x, int y)
{
    m_pGame = pGame;
    m_X = (double)x;
    m_Y = (double)y;
    m_bIsAlive = true;
    m_velocity = 0.0;
    m_rotationAngle = 0.0;
}

//////////////////////////////////////////////////////////////////////////////
// Update
//////////////////////////////////////////////////////////////////////////////
/*virtual*/ void GameEntity::Update()
{
    // Update x and y positions based on the current velocity and rotation angle
    double fAngleInRads = m_rotationAngle * M_PI / 180.0;
    m_X = m_X + (m_velocity * cos(fAngleInRads));
    m_Y = m_Y + (m_velocity * sin(fAngleInRads));

    // Wraparound Code
    if (m_X > m_pGame->GetWindowWidth())
    {
        m_X = 0;
    }
    if (m_X < 0)
    {
        m_X = m_pGame->GetWindowWidth();
    }
    if (m_Y > m_pGame->GetWindowHeight())
    {
        m_Y = 0;
    }
    if (m_Y < 0)
    {
        m_Y = m_pGame->GetWindowHeight();
    }
}

//////////////////////////////////////////////////////////////////////////////
// IsAlive
//////////////////////////////////////////////////////////////////////////////
bool GameEntity::IsAlive()
{
    return m_bIsAlive;
}

//////////////////////////////////////////////////////////////////////////////
// Kill
//////////////////////////////////////////////////////////////////////////////
void GameEntity::Kill()
{
    m_bIsAlive = false;
}