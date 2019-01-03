//////////////////////////////////////////////////////////////////////////////
// PlayerShip Class Implementation
//////////////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "PlayerShip.h"

//////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////
PlayerShip::PlayerShip(Game* pGame, int x, int y) : GameEntity(pGame, x, y)
{
    m_pShipImage = SDL_LoadBMP("gfx/00ShipFrames1.bmp");
}

//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
PlayerShip::~PlayerShip()
{
    SDL_FreeSurface(m_pShipImage);
}

//////////////////////////////////////////////////////////////////////////
// Update
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerShip::Update()
{
    const Uint8* stateArray = SDL_GetKeyboardState(NULL);
    if (stateArray[SDL_SCANCODE_LEFT] == 1) 
    {
        m_rotationAngle -= m_fTurnRate;
        if ( m_rotationAngle < 0.0 )
        {
            m_rotationAngle = m_rotationAngle + 360.0;
        }
    }
    if (stateArray[SDL_SCANCODE_RIGHT] == 1)
    {
        m_rotationAngle += m_fTurnRate;
        if ( m_rotationAngle > 360.0 )
        {
            m_rotationAngle = m_rotationAngle - 360.0;
        } 
    }
    if (stateArray[SDL_SCANCODE_UP] == 1)
    {
        m_velocity += .05;
    }
    if (stateArray[SDL_SCANCODE_DOWN] == 1)
    {
        m_velocity -= .05;
    }
   
    // Call base class to update position
    GameEntity::Update();
}

//////////////////////////////////////////////////////////////////////////
// Render
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerShip::Render(SDL_Surface* pSurface)
{
    // Calculate what row and col in the image we will display based on
    //  the rotation of the ship
    int nFrame = (m_rotationAngle / 5.0);
    int nRow = nFrame / 9;
    int nCol = nFrame % 9;

    // Create the src and destination rectangles for the bitblt
    SDL_Rect srcrect = { nCol * 63, nRow * 63, 63, 63 };
    SDL_Rect dstrect = { m_X - ( 63 / 2 ) - 1, m_Y - ( 63 / 2 ) - 1, 63, 63 };

    // Copy ship image to the screen
    SDL_BlitSurface( m_pShipImage, &srcrect, pSurface, &dstrect );
}