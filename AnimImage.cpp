//////////////////////////////////////////////////////////////////////////////
// AnimImage Class Implementation
//////////////////////////////////////////////////////////////////////////////
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