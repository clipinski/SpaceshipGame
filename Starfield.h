///////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2025 Craig J. Lipinski
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

#ifndef STARFIELD_H
#define STARFIELD_H

#include <SDL.h>
#include <vector>

// Forward declaration of Game
class Game;

//////////////////////////////////////////////////////////////////////////////
// Starfield Class
//
// Creates a static starfield background with twinkling stars
//////////////////////////////////////////////////////////////////////////////
class Starfield
{
private:
    struct Star {
        float x, y;           // Position
        uint8_t baseBrightness;   // Base brightness level (0-255)
        float twinkleSpeed;       // How fast the star twinkles
        float twinklePhase;       // Current phase in twinkle animation (0-2π)
        float twinkleAmount;      // How much the star twinkles (0-1)
    };

    static const int NUM_STARS = 200;
    std::vector<Star> m_stars;
    Game* m_pGame;

    void ResetStar(Star& star);

public:
    Starfield(Game* pGame);
    ~Starfield();

    void Update(float deltaTime);
    void Render(SDL_Surface* pSurface);
};

#endif // STARFIELD_H 