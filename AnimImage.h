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