#include "image.h"

#ifndef __WRAPPER_H
    #define __WRAPPER_H

    #ifdef __cplusplus
        extern "C" {
    #endif
    
    // define wrapper.
    typedef struct ImageIO ImageIO;

    // define struct functions.
    ImageIO* create_io_object();
    void delete_io_object(ImageIO* image_io);
    Image read_image(ImageIO* image_io, char *file_name);
    void write_image(ImageIO* image_io, char *file_name, Image image_type);

    #ifdef __cplusplus
        }
    #endif
#endif