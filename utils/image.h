#ifndef __IMAGE_H
    #define __IMAGE_H
    
    // image struct definition.
    typedef struct Image{
        int* size;
        int*** array;
    }Image;

    // function to create empty image array.
    Image empty_image(int h,int w, int c);
#endif