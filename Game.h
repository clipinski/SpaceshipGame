#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>

// Forward Delcarations
class GameEntity;

//////////////////////////////////////////////////////////////////////////////
// Game Class
//////////////////////////////////////////////////////////////////////////////
class Game
{
private:

    // Window Size
    const int m_windowWidth = 1280;
    const int m_windowHeight = 720;

    // Framerate timing - want to Run at about 60 fps
    const unsigned int desiredFrameTime = 1000 / 60;

    // The window we'll be rendering to
    SDL_Window* m_pMainWindow = NULL;
        
    // The surface contained by the window
    SDL_Surface* m_pMainScreenSurface = NULL;

    // List of game entities
    std::vector<GameEntity*> m_listEntities;

protected:
    //************************************************************************
    // Internal Methods
    //************************************************************************
    bool Initialize();
    void Close();
    void UpdateGame();
    void RenderGame();

public:   
    //************************************************************************
    // Public Interface
    //************************************************************************
    int GetWindowWidth();
    int GetWindowHeight();
    void AddEntity(GameEntity *pEntity);
    int Run();
};

#endif