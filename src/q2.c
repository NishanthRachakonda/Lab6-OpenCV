#include <stdio.h>
#include <stdlib.h>
#include "../utils/image.h"
#include "../utils/wrapper.h"

Image gaussian_blurring(Image image, int k){
    int* size = image.size;
    int h = size[0];
    int w = size[1];
    int c = size[2];

    Image blurr_image = empty_image(h-k, w-k, c);
    for(int i=0;i<h-k;i++)
        for(int j=0;j<w-k;j++)
            for(int x=0;x<c;x++){
                blurr_image.array[i][j][x] = 0;
                for(int i1=0;i1<k;i1++)
                    for(int j1=0;j1<k;j1++)
                        blurr_image.array[i][j][x] += image.array[i+i1][j+j1][x];
                blurr_image.array[i][j][x] /= (k*k);
        }
    return blurr_image;
}  

int abs(int a){
    return a > 0 ? a : -a;
}

Image edge_detection(Image image1, Image image2){
    int* size = image2.size;
    int h = size[0];
    int w = size[1];
    int c = size[2];

    Image edge_image = empty_image(h, w, c);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            for(int x=0;x<c;x++){
                edge_image.array[i][j][x] = image1.array[i][j][x]-image2.array[i][j][x];
                edge_image.array[i][j][x] = abs(edge_image.array[i][j][x]);
        }
    return edge_image;
}
int main(){
    char read_file[1000] = "pp.jpg";
    ImageIO *image_io = create_io_object();
    Image rgb_image = read_image(image_io, read_file);
    
    char write_file1[1000] = "data/pp2.png";
    Image blurr_image = gaussian_blurring(rgb_image, 10);
    write_image(image_io, write_file1, blurr_image);
    
    char write_file2[1000] = "data/pp3.png";
    Image edge_image = edge_detection(rgb_image, blurr_image);
    write_image(image_io, write_file2, edge_image);
    return 0;
}