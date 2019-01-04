//////////////////////////////////////////////////////////////////////////////
// PlayerShip Class Implementation
//////////////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "GameConfig.h"
#include "PlayerShip.h"

//////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////
PlayerShip::PlayerShip(Game* pGame, int x, int y) : GameEntity(pGame, x, y)
{
    m_pShipImage = new AnimImage(SHIP_IMAGE_PATH, SHIP_IMAGE_NUM_FRAMES, SHIP_IMAGE_WIDTH, SHIP_IMAGE_HEIGHT);
}

//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
PlayerShip::~PlayerShip()
{
    if (m_pShipImage)
    {
        delete m_pShipImage;
    }
}

//////////////////////////////////////////////////////////////////////////
// Update
//////////////////////////////////////////////////////////////////////////
/*virtual*/ void PlayerShip::Update()
{
    // Query the current state of the keyboard
    const Uint8* stateArray = SDL_GetKeyboardState(NULL);

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
        m_velocity += GameConfig::PlayerShip::FORWARD_THRUST_AMT;
    }

    // Check Reverse Thrust Key
    if (stateArray[GameConfig::Controls::REVERSE_THRUST] == 1)
    {
        m_velocity -= GameConfig::PlayerShip::REVERSE_THRUST_AMT;
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
    int nFrame = (m_rotationAngle / (360.0 / (double)SHIP_IMAGE_NUM_FRAMES));

    // NOTE: We only have 1 "point right" frame, so if we wrap around 360 degrees, just
    //  pass in frame 0
    if (nFrame == 72)
    {
        nFrame = 0;
    }

    // Copy the correct frame to the screen
    // NOTE: We want the X and Y to be in the center of the ship, so
    //   we will adjust by half the size of the image
    m_pShipImage->BltFrame(nFrame, m_X - ( SHIP_IMAGE_WIDTH / 2 ), m_Y - ( SHIP_IMAGE_HEIGHT / 2 ), pSurface);
}