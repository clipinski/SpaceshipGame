///////////////////////////////////////////////////////////////////////////////////
// MIT License
//
// Copyright (c) 2019, 2025 Craig J. Lipinski
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

#ifndef ANIM_IMAGE_H
#define ANIM_IMAGE_H

#include <SDL.h>

//////////////////////////////////////////////////////////////////////////////
// PlayerShip Class
//////////////////////////////////////////////////////////////////////////////
class AnimImage
{
private:
    // Surface loaded with image that contains the frames
    SDL_Surface* m_pImage = NULL;

    // Metrics for the animation
    int m_nNumFrames;
    int m_nFrameHeight;
    int m_nFrameWidth;
    int m_nNumRows;
    int m_nNumCols;

    // Hide the default constructor as we want to force the user of this class to specify
    //  an image to load and the metrics for that image.
    AnimImage();

public:
    AnimImage(const char* szImageFileName, int numFrames, int frameHeight, int frameWidth);
    ~AnimImage();

    // Copy a frame to another surface at the specified x,y coordinates
    int BltFrame(int nFrame, int x, int y, SDL_Surface * pDstSurface);
};

#endif