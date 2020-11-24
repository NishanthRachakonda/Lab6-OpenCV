#include <stdio.h>
#include <stdlib.h>
#include "../utils/image.h"
#include "../utils/wrapper.h"

int rgb2gray(int* channel){
    return 0.3*channel[0]+0.59*channel[1]+0.11*channel[2];
}

void sort(int arr[][2], int n){  
    int i, j, min_idx;    
    for(i=0;i<n-1;i++){  
        min_idx=i;
        for(j=i+1;j<n;j++)  
        if (arr[j][0] < arr[min_idx][0])  
            min_idx = j;
        int temp[2] = {0};
        temp[0] = arr[min_idx][0];
        temp[1] = arr[min_idx][1];

        arr[min_idx][0] = arr[i][0];
        arr[min_idx][1] = arr[i][1];

        arr[i][0] = temp[0];
        arr[i][1] = temp[1];
    }
}

int main(){
    char read_file[1000] = "pp.jpg";
    ImageIO *image_io = create_io_object();
    Image rgb_image = read_image(image_io, read_file);
    int h = rgb_image.size[0];
    int w = rgb_image.size[1];
    int c = rgb_image.size[2];
    
    Image gray_image = empty_image(h, w, 1);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            gray_image.array[i][j][0] = rgb2gray(rgb_image.array[i][j]);
    char write_file[1000] = "data/pp1.png";
    write_image(image_io, write_file, gray_image);

    int histogram[256][2] = {0};
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            histogram[gray_image.array[i][j][0]][0]++;
            histogram[gray_image.array[i][j][0]][1] = gray_image.array[i][j][0];
        }
    sort(histogram, 256);
    for(int i=0;i<10;i++)
        printf("%d ", histogram[i][1]);
    printf("\n");
    return 0;
}