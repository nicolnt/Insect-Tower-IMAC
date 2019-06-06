#include "ppm-loader.h"


int ppm_checkValidType(char buffer[])
{
  //printf("buffer : %s %c%c%d\n", buffer, buffer[0], buffer[1], buffer[2]);
  if (buffer[0] != 'P' || buffer[1] != '6' || buffer[2] != '\0') {
    return 0;
  }
  else {
    return 1;
  }
}

void ppm_gotoEndOfLine(FILE* image)
{
  char crtChar = (char) fgetc(image);
  while(crtChar != '\n' && crtChar != EOF) {
    crtChar = fgetc(image);
  }
}

void ppm_handleComments(FILE *image)
{
  char buffer[100];
  int current_position = ftell(image);

  fscanf(image, "%s", buffer);
  //printf("comment character :%c\n", buffer[0]);
  if (buffer[0] == '#') {
    //printf("skipping one comment\n");
    ppm_gotoEndOfLine(image);
    ppm_handleComments(image);
  }
  else {
    fseek(image, current_position, SEEK_SET);
  }
}

char* ppm_load()
{

  int width, height, color_value;

  FILE* image = fopen(mapData->mapFile, "rb");
  
  if (!image) {
    printf("Image couldn't be loaded, interupting program\n");
    return EXIT_FAILURE;
  }

  char buffer[100];

  //Read type
  fscanf(image, "%s", buffer);
  if (ppm_checkValidType(buffer) == 0) {
    printf("Invalid PPM type\n");
    return EXIT_FAILURE;
  }

  //Read data loop
  ppm_handleComments(image);
  fscanf(image, "%d", &width);
  ppm_handleComments(image);
  fscanf(image, "%d", &height);
  ppm_handleComments(image);
  fscanf(image, "%d", &color_value);

  //Read actual image data
  unsigned char* pixel_data = malloc(sizeof(unsigned char)*3*width*height);
  if (!pixel_data) {
    printf("ERROR ALLOC : pixel_data");
    exit(CHK_ERROR_ALLOC);
  }

  ppm_gotoEndOfLine(image);

  fread(pixel_data, 3*width, height, image);
  
  mapData->Xsplit = width;
  mapData->Ysplit = height;

  return pixel_data;

}
