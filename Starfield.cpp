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

#include "Starfield.h"
#include "Game.h"
#include "GameConfig.h"
#include <random>
#include <cmath>
#include <ctime>

//////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////
Starfield::Starfield(Game* pGame)
    : m_pGame(pGame)
{
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Initialize stars
    m_stars.resize(NUM_STARS);
    for (auto& star : m_stars) {
        ResetStar(star);
    }
}

//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
Starfield::~Starfield()
{
}

//////////////////////////////////////////////////////////////////////////
// ResetStar
//////////////////////////////////////////////////////////////////////////
void Starfield::ResetStar(Star& star)
{
    star.x = static_cast<float>(rand() % m_pGame->GetWindowWidth());
    star.y = static_cast<float>(rand() % m_pGame->GetWindowHeight());
    star.baseBrightness = 100 + (rand() % 155); // Base brightness between 100-255
    
    // 50% chance the star doesn't twinkle at all
    if (rand() % 100 < 50) {
        star.twinkleAmount = 0.0f;
        star.twinkleSpeed = 0.0f;
    } else {
        // Faster speed but keep subtle intensity
        star.twinkleSpeed = 10.0f + (static_cast<double>(rand()) / RAND_MAX * 10.0f); // Speed between 10-30
        star.twinkleAmount = 0.1f + (static_cast<double>(rand()) / RAND_MAX * 0.2f); // Twinkle amount between 0.1-0.3
    }
    
    star.twinklePhase = static_cast<double>(rand()) / RAND_MAX * 2.0f * M_PI; // Random starting phase
}

//////////////////////////////////////////////////////////////////////////
// Update
//////////////////////////////////////////////////////////////////////////
void Starfield::Update(float deltaTime)
{
    // Update twinkle phase for each star
    for (auto& star : m_stars) {
        star.twinklePhase += star.twinkleSpeed * deltaTime;
        if (star.twinklePhase > 2.0f * M_PI) {
            star.twinklePhase -= 2.0f * M_PI;
        }
    }
}

//////////////////////////////////////////////////////////////////////////
// Render
//////////////////////////////////////////////////////////////////////////
void Starfield::Render(SDL_Surface* pSurface)
{
    for (const auto& star : m_stars) {
        // Calculate current brightness using sine wave
        float twinkleFactor = 1.0f + (sinf(star.twinklePhase) * star.twinkleAmount);
        int brightness = static_cast<int>(star.baseBrightness * twinkleFactor);
        
        // Clamp brightness to valid range
        brightness = (brightness > 255) ? 255 : brightness;
        brightness = (brightness < 0) ? 0 : brightness;

        // Draw each star as a single pixel
        SDL_Rect pixel = { 
            static_cast<int>(star.x), 
            static_cast<int>(star.y), 
            1, 
            1 
        };
        
        SDL_FillRect(pSurface, 
                    &pixel, 
                    SDL_MapRGB(pSurface->format, 
                              brightness, 
                              brightness, 
                              brightness));
    }
} 