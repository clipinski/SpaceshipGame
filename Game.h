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

#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <list>

// Forward Delcarations
class GameEntity;

//////////////////////////////////////////////////////////////////////////////
// Game Class
//////////////////////////////////////////////////////////////////////////////
class Game
{
private:
    // Framerate timing - want to Run at about 60 fps
    const unsigned int desiredFrameTime = 1000 / 60;

    // The window we'll be rendering to
    SDL_Window* m_pMainWindow = NULL;
        
    // The surface contained by the window
    SDL_Surface* m_pMainScreenSurface = NULL;

    // List of game entities
    std::list<GameEntity*> m_listEntities;

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