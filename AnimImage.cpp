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

#include "AnimImage.h"

//////////////////////////////////////////////////////////////////////////
// Ctor
//////////////////////////////////////////////////////////////////////////
AnimImage::AnimImage(const char* szImageFileName, int numFrames, int frameHeight, int frameWidth)
{
    // Store our metrics
    m_nNumFrames = numFrames;
    m_nFrameHeight = frameHeight;
    m_nFrameWidth = frameWidth;

    // Ask SDL to load the image
    m_pImage = SDL_LoadBMP(szImageFileName);
    
    // If we loaded the image correctly
    if (m_pImage)
    {
        // Set black as the transparent color (RGB: 0,0,0)
        SDL_SetColorKey(m_pImage, SDL_TRUE, SDL_MapRGB(m_pImage->format, 0, 0, 0));

        // Calculate rows and colums
        m_nNumCols = m_pImage->w / frameWidth;
        m_nNumRows = m_pImage->h / frameHeight;

        // Check for correct data
        SDL_assert((m_nNumRows * m_nNumCols) == m_nNumFrames);
    }
}

//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
AnimImage::~AnimImage()
{
    // Tell SDL to free the surface
    if (m_pImage)
    {
        SDL_FreeSurface(m_pImage);
        m_pImage = NULL;
    }
}

//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
int AnimImage::BltFrame(int nFrame, int x, int y, SDL_Surface * pDstSurface)
{
    int nRetVal = 0;

    // Check for valid destination surface
    if (pDstSurface)
    {
        // Check for valid image
        if (m_pImage)
        {
            // Check for valid frame
            if (nFrame >=0 && nFrame < this->m_nNumFrames)
            {
                // Calculate the current row and col of the frame to be copied
                int nRow = nFrame / m_nNumCols;
                int nCol = nFrame % m_nNumCols;

                // Create the src and destination rectangles for the bitblt
                SDL_Rect srcrect = { nCol * m_nFrameWidth, nRow * m_nFrameHeight, m_nFrameWidth, m_nFrameHeight };
                SDL_Rect dstrect = { x, y, m_nFrameWidth, m_nFrameHeight };

                // Copy the image to the new surface
                nRetVal = SDL_BlitSurface( m_pImage, &srcrect, pDstSurface, &dstrect );
            }
            else
            {
                // Bad frame passed in!
                SDL_assert(false);
            }
        }
        else
        {
            // We never loaded an image, so let's draw a red box to show that the image is missing
            SDL_Rect rect = {x, y, m_nFrameWidth, m_nFrameHeight};
            SDL_FillRect(pDstSurface, &rect, SDL_MapRGB(pDstSurface->format, 0xFF, 0x00, 0x00));
        }
    }

    return nRetVal;
}