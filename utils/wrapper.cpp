#include "image_io.h"
#include "wrapper.h"
#include <cassert>

#ifdef __cplusplus
  extern "C" {
#endif

// create ImageIO object
ImageIO* create_io_object(){
  return new ImageIO();
}

// delete ImageIO object
void delete_io_object(ImageIO* wrapper){
  assert(wrapper);
  delete wrapper;
}

// read image
Image read_image(ImageIO* wrapper, char* file_name){
  assert(wrapper);
  return wrapper->readImage(file_name);
}

// write image
void write_image(ImageIO* wrapper, char *file_name, Image image){
  assert(wrapper);
  wrapper->writeImage(file_name, image);
}

#ifdef __cplusplus
  }
#endif