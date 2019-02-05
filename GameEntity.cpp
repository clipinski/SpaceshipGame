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
// GetRotationAngleInRads
//////////////////////////////////////////////////////////////////////////////
double GameEntity::GetRotationAngleInRads()
{
    return m_rotationAngle * M_PI / 180.0;
}

//////////////////////////////////////////////////////////////////////////////
// HandleWrapAround
//////////////////////////////////////////////////////////////////////////////
void GameEntity::HandleWrapAround()
{
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
// Update
//////////////////////////////////////////////////////////////////////////////
/*virtual*/ void GameEntity::Update()
{
    // Default Movement Behaviour:
    //      Update x and y positions based on the current velocity 
    //      and rotation angle.
    m_X = m_X + (m_velocity * cos(GetRotationAngleInRads()));
    m_Y = m_Y + (m_velocity * sin(GetRotationAngleInRads()));

    // By Default, make all entities "wrap around" the screen
    HandleWrapAround();
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