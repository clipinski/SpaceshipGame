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
#include "GameConfig.h"
#include "PlayerShip.h"

//////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////
PlayerShip::PlayerShip(Game* pGame, int x, int y) : GameEntity(pGame, x, y)
{
    // Set initial defaults
    m_velocityX = 0;
    m_velocityY = 0;
    m_nLastBulletFireTime = 0;
    m_bEnginesOn = false;
    m_nEnginesOnFrameCounter = 0;

    // Try and create the animated image
    m_pShipImage = new AnimImage("gfx/00ShipFrames1.bmp", SHIP_IMAGE_NUM_FRAMES, SHIP_IMAGE_WIDTH, SHIP_IMAGE_HEIGHT);

    // Now load the images displayed when the ship is firing engines
    m_pShipImagesThrusting[0] = new AnimImage("gfx/00ShipFrames2.bmp", SHIP_IMAGE_NUM_FRAMES, SHIP_IMAGE_WIDTH, SHIP_IMAGE_HEIGHT);
    m_pShipImagesThrusting[1] = new AnimImage("gfx/00ShipFrames3.bmp", SHIP_IMAGE_NUM_FRAMES, SHIP_IMAGE_WIDTH, SHIP_IMAGE_HEIGHT);
    m_pShipImagesThrusting[2] = new AnimImage("gfx/00ShipFrames4.bmp", SHIP_IMAGE_NUM_FRAMES, SHIP_IMAGE_WIDTH, SHIP_IMAGE_HEIGHT);
}

//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
PlayerShip::~PlayerShip()
{
    // Clean up main image
    if (m_pShipImage)
    {
        delete m_pShipImage;
    }

    // Clean up array of "thrusting" images
    for( auto pImage : m_pShipImagesThrusting )
    {
        if (pImage)
        {
            delete pImage;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// HandleUserInput
//////////////////////////////////////////////////////////////////////////
void PlayerShip::HandleUserInput()
{
 // Query the current state of the keyboard
    const Uint8* stateArray = SDL_GetKeyboardState(NULL);

    // Reset defaults
    m_bEnginesOn = false;

    // Check Turn Left Key
    if (stateArray[GameConfig::Controls::TURN_LEFT] == 1) 
    {
        m_rotationAngle -= GameConfig::PlayerShip::TURN_RATE;
        if ( m_rotationAngle < 0.0 )
        {
            m_rotationAngle = m_rotationAngle + 360.0;
        }
    }

    // Check Turn Right Key
    if (stateArray[GameConfig::Controls::TURN_RIGHT] == 1)
    {
        m_rotationAngle += GameConfig::PlayerShip::TURN_RATE;
        if ( m_rotationAngle > 360.0 )
        {
            m_rotationAngle = m_rotationAngle - 360.0;
        } 
    }

    // Check Forward Thrust Key
    if (stateArray[GameConfig::Controls::FORWARD_THRUST] == 1)
    {
        m_velocityX += ( GameConfig::PlayerShip::FORWARD_THRUST_AMT * cos(GetRotationAngleInRads()) );
        m_velocityY += ( GameConfig::PlayerShip::FORWARD_THRUST_AMT * sin(GetRotationAngleInRads()) );

        // Engines are "on" so we'll make sure and display that animation later
         m_bEnginesOn = true;
    }

    // Check Reverse Thrust Key
    if (stateArray[GameConfig::Controls::REVERSE_THRUST] == 1)
    {
        m_velocityX -= ( GameConfig::PlayerShip::REVERSE_THRUST_AMT * cos(GetRotationAngleInRads()) );
        m_velocityY -= ( GameConfig::PlayerShip::REVERSE_THRUST_AMT * sin(GetRotationAngleInRads()) );
    }
}

//////////////////////////////////////////////////////////////////////////
// Update
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerShip::Update()
{
    // Update oursleves based on any input from the user
    HandleUserInput();

    // NOTE: We've implemented a different movement system than the
    //   default GameEntity object.  We apply thrust in the X and Y
    //   direction to make the ship control in an "Asteroids" style.
    m_X += m_velocityX;
    m_Y += m_velocityY;
   
    // Call base class to update position
    GameEntity::HandleWrapAround();
}

//////////////////////////////////////////////////////////////////////////
// Render
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerShip::Render(SDL_Surface* pSurface)
{
    // Calculate what row and col in the image we will display based on
    //  the rotation of the ship
    int nFrame = (m_rotationAngle / (360.0 / (double)SHIP_IMAGE_NUM_FRAMES));

    // NOTE: We only have 1 "point right" frame, so if we wrap around 360 degrees, just
    //  pass in frame 0
    if (nFrame == SHIP_IMAGE_NUM_FRAMES)
    {
        nFrame = 0;
    }

    // Copy the correct frame to the screen
    // NOTE: We want the X and Y to be in the center of the ship, so
    //   we will adjust by half the size of the image
    if (!m_bEnginesOn)
    {
        // Draw the "no engines firing" version of the ship
        m_pShipImage->BltFrame(nFrame, m_X - ( SHIP_IMAGE_WIDTH / 2 ), m_Y - ( SHIP_IMAGE_HEIGHT / 2 ), pSurface);

        // Reset "engines on" animation frame counter
        m_nEnginesOnFrameCounter = 0;
    }
    else
    {   
        // Show each "engines on" animation frame for ENGINES_ON_ANIMATION_FRAMES number of frames

        // Low Engine Fire
        if (m_nEnginesOnFrameCounter < (GameConfig::PlayerShip::ENGINES_ON_ANIMATION_FRAMES * 1))
        {
            m_pShipImagesThrusting[0]->BltFrame(nFrame, m_X - ( SHIP_IMAGE_WIDTH / 2 ), m_Y - ( SHIP_IMAGE_HEIGHT / 2 ), pSurface);
        }
        // Med Engine Fire
        else if (m_nEnginesOnFrameCounter < (GameConfig::PlayerShip::ENGINES_ON_ANIMATION_FRAMES * 2))
        {
            m_pShipImagesThrusting[1]->BltFrame(nFrame, m_X - ( SHIP_IMAGE_WIDTH / 2 ), m_Y - ( SHIP_IMAGE_HEIGHT / 2 ), pSurface);
        }
        // High Engine Fire
        else if (m_nEnginesOnFrameCounter < (GameConfig::PlayerShip::ENGINES_ON_ANIMATION_FRAMES * 3))
        {
            m_pShipImagesThrusting[2]->BltFrame(nFrame, m_X - ( SHIP_IMAGE_WIDTH / 2 ), m_Y - ( SHIP_IMAGE_HEIGHT / 2 ), pSurface);
        }
        // Back to Low
        else
        {
           m_pShipImagesThrusting[0]->BltFrame(nFrame, m_X - ( SHIP_IMAGE_WIDTH / 2 ), m_Y - ( SHIP_IMAGE_HEIGHT / 2 ), pSurface);
           m_nEnginesOnFrameCounter = 0; 
        }

        // Increment "engines on" frame counter
        m_nEnginesOnFrameCounter++;
    }
}