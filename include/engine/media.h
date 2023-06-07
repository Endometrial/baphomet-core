#ifndef MEDIA_H
#define MEDIA_H

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <libxml/xmlreader.h>
#include <png.h>

typedef struct Image {
	uint8_t* data;
	png_uint_32 width;
	png_uint_32 height;
	int color_type;
	int bit_depth;
} Image;


char* file_load(char* filepath);
Image image_load(char* filepath);
GLuint texture_load(char* filepath, GLint texture_wrap, GLint texture_filter);



#endif
