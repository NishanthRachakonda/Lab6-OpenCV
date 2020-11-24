#include <stdio.h>
#include <stdlib.h>
#include "../utils/image.h"
#include "../utils/wrapper.h"

Image downsample(Image image){
    int* size = image.size;
    int h = size[0];
    int w = size[1];
    int c = size[2];

    Image downsample_image = empty_image(h/2, w/2, c/2);
    for(int i=0;i<h;i+=2)
        for(int j=0;j<w;j+=2)
            for(int x=0;x<c;x+=2){
                downsample_image.array[i/2][j/2][x] += image.array[i][j][x];
                downsample_image.array[i/2][j/2][x] += image.array[i][j+1][x];
                downsample_image.array[i/2][j/2][x] += image.array[i+1][j][x];
                downsample_image.array[i/2][j/2][x] += image.array[i+1][j+1][x];
                downsample_image.array[i/2][j/2][x] /= 4;
        }
    return downsample_image;
}
int main()
{
    char read_file[1000] = "data/pp1.png";
    ImageIO *image_io = create_io_object();
    Image rgb_image = read_image(image_io, read_file);
    
    char write_file1[1000] = "data/pp4.png";
    Image half_image = downsample(rgb_image);
    write_image(image_io, write_file1, half_image);
    return 0;
}