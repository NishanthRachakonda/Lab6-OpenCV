#include <stdio.h>
#include <stdlib.h>
#include "../utils/image.h"
#include "../utils/wrapper.h"

Image blend(Image image1, Image image2, float alpha){
    int* size = image1.size;
    int h = size[0];
    int w = size[1];
    int c = size[2];

    Image blend_image = empty_image(h, w, c);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            for(int x=0;x<c;x++){
                blend_image.array[i][j][x] = alpha*image1.array[i][j][x]+(1-alpha)*image2.array[i][j][x];
        }
    return blend_image;
}
int main(){
    ImageIO *image_io = create_io_object();
    char read_file1[1000] = "pp.jpg";
    Image rgb_image1 = read_image(image_io, read_file1);

    char read_file2[1000] = "rr.png";
    Image rgb_image2 = read_image(image_io, read_file2);

    char write_file1[1000] = "data/pp5.png";
    Image blend_image = blend(rgb_image1, rgb_image2, 0.5);
    write_image(image_io, write_file1, blend_image);
    return 0;
}