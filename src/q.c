#include <stdio.h>
#include <stdlib.h>
#include "../utils/image.h"
#include "../utils/wrapper.h"

int main(){
    char read_file[1000] = "data/cat.jpg";
    char write_file[1000] = "data/cat2.jpg";
    ImageIO *image_io = create_io_object();
    Image rgb_image = read_image(image_io, read_file);
    write_image(image_io, write_file, rgb_image);
    return 0;
}