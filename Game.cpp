#include <SDL.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Game.h"
#include "GameEntity.h"
#include "PlayerShip.h"

//////////////////////////////////////////////////////////////////////////
// Initialize
//////////////////////////////////////////////////////////////////////////
bool Game::Initialize()
{
    // Initialization flag
    bool success = true;

    // Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not Initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        // Create window
        m_pMainWindow = SDL_CreateWindow( "Space Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_windowWidth, m_windowHeight, SDL_WINDOW_SHOWN );
        if( m_pMainWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            // Get window surface
            m_pMainScreenSurface = SDL_GetWindowSurface( m_pMainWindow );
        }

        // Create our entities
        this->AddEntity(new PlayerShip(this, m_windowWidth/2, m_windowHeight/2));
    }

    return success;
}

//////////////////////////////////////////////////////////////////////////
// Close
//////////////////////////////////////////////////////////////////////////
void Game::Close()
{
    // Clean up our entities
    for( std::size_t i = 0; i < m_listEntities.size(); i++ )
    {
        delete m_listEntities[i];
    }

    // Destroy window
    SDL_DestroyWindow( m_pMainWindow );
    m_pMainWindow = NULL;

    // Quit SDL subsystems
    SDL_Quit();
}

//////////////////////////////////////////////////////////////////////////
// UpdateGame
//////////////////////////////////////////////////////////////////////////
void Game::UpdateGame()
{
    // Loop through list of entities and tell each one to update itself
    for( std::size_t i = 0; i < m_listEntities.size(); i++ )
    {
        // Get the entity at each index in the loop
        GameEntity* pEntity = m_listEntities[i];

        // Check for "dead" entities
        if (pEntity->IsAlive())
        {
            pEntity->Update();
        }
        else
        {
            // Remove the "dead" element from the list
            m_listEntities.erase(m_listEntities.begin() + i);

            // Clean up the memory
            delete pEntity;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// RenderGame
//////////////////////////////////////////////////////////////////////////
void Game::RenderGame()
{
    // Clear the surface
    SDL_FillRect(m_pMainScreenSurface, NULL, 0x000000);

    // Loop through list of entities and tell each one to render itself
    for( std::size_t i = 0; i < m_listEntities.size(); i++ )
    {
        // Render each entity
        m_listEntities[i]->Render(m_pMainScreenSurface);
    }

    // Update the surface
    SDL_UpdateWindowSurface( m_pMainWindow );
}

//////////////////////////////////////////////////////////////////////////
// GetWindowWidth
//////////////////////////////////////////////////////////////////////////
int Game::GetWindowWidth()
{
    return m_windowWidth;
}

//////////////////////////////////////////////////////////////////////////
// GetWindowHeight
//////////////////////////////////////////////////////////////////////////
int Game::GetWindowHeight()
{
    return m_windowHeight;
}

//////////////////////////////////////////////////////////////////////////
// AddEntity
//
// Adds a new entity to the game.
//////////////////////////////////////////////////////////////////////////
void Game::AddEntity(GameEntity *pEntity)
{
    m_listEntities.push_back(pEntity);
}

//////////////////////////////////////////////////////////////////////////
// Run
//////////////////////////////////////////////////////////////////////////
int Game::Run()
{
    // Start up SDL and create main window
    if( !Initialize() )
    {
        // Something failed!
        return 1;
    }
            
    // Update the surface
    SDL_UpdateWindowSurface( m_pMainWindow );

    // Main loop flag
    bool playing = true;

    // Timing control
    unsigned int lastTime = 0;

    // Main game loop
    while( playing )
    {
        // Poll events
        SDL_Event event;
        while( SDL_PollEvent(&event) )
        {
            switch (event.type)
            {
                // SDL Quit message
                case SDL_QUIT:
                    playing = false;
                    break;

                // Allow escape key to exit
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        playing = false;
                    }
                    break;
            }
        }

        // Timing Control
        unsigned int currentTime = SDL_GetTicks();
        if (currentTime - lastTime > desiredFrameTime) 
        {
            UpdateGame();
            RenderGame();

            // Update last time
            lastTime = currentTime;
        }
    }

    // Free resources and Close SDL
    Close();

    return 0;
}