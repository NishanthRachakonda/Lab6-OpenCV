#include <stdlib.h>
#include "image.h"

Image empty_image(int h,int w, int c){

    // set image array.
    int*** array = (int***) malloc(sizeof(int**)*h);
    for(int i=0;i<h;i++){
        array[i] = (int**) malloc(sizeof(int*)*w);
        for(int j=0;j<w;j++)
            array[i][j] = (int*) malloc(sizeof(int)*c);
    }

    // set image size.
    int* size = (int*) malloc(sizeof(int)*3);
    size[0] = h;
    size[1] = w;
    size[2] = c;

    // set image.
    Image image;
    image.size = size;
    image.array = array;

    return image;
}
