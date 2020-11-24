#include "image.h"

#ifndef __IMAGE_IO_H
    #define __IMAGE_IO_H

    // define image io class.
    class ImageIO{
        public:
        Image readImage(char* file_name);
        void writeImage(char* file_name, Image image);
    };

#endif