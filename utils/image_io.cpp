#include <stdio.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "image.h"
#include "image_io.h"

// method to read image.
Image ImageIO::readImage(char* file_name){

    // load image into a opencv matrix.    
    std::string image_path = cv::samples::findFile(file_name);
    cv::Mat image_matrix = cv::imread(image_path, cv::IMREAD_COLOR);

    // report error for empty file.
    if(image_matrix.empty()){
        printf("ERROR: Could not read the image: %s\n", file_name);
        Image image = {NULL, NULL};    
        return image;
    }

    // copy the opencv matrix into the custom image struct.
    int h = image_matrix.rows;
    int w = image_matrix.cols;
    int c = image_matrix.channels();

    Image image = empty_image(h, w, c);
    unsigned char *input = (unsigned char*)(image_matrix.data);
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            for(int k=0;k<c;k++)
                image.array[i][j][k] = input[c*(w*i+j)+k];
    return image;
}

// method to write image.
void ImageIO::writeImage(char* file_name, Image image){
    
    // initialization.
    int*** array = image.array;
    int h = image.size[0];
    int w = image.size[1];
    int c = image.size[2];

    // error checking.
    if(c != 1 && c != 3){
        printf("ERROR: Image channels should be either 1/3 not %d\n", c);
        return;
    }

    // copy given image into opencv matrix.
    unsigned char *input = new unsigned char[h*w*c];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            for(int k=0;k<c;k++)
                input[c*(w*i+j)+k] = array[i][j][k];

    // write image.
    cv::Mat image_matrix = cv::Mat(h, w, c==3 ? CV_8UC3 : CV_8UC1, input);
    cv::imwrite(file_name, image_matrix);
}
