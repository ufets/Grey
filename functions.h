#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

enum ERRORS
{
    OK,
    INV_ARGS,
    LOAD_ERROR,
    RECOLOR_ERROR

};


typedef struct Color{
    float kred;
    float kgreen;
    float kblue;
}Color;


typedef struct Image{
    unsigned char* data;
    int width;
    int height;
    int channels;
    char* name;
}Image;

void recolor(Image img, Image* gray_img, Color set);
void make_gray(Image img, Image* gray_img, Color set);
int create_set(Color *set, char* flag);
void func_asm(unsigned char* img, unsigned char* gray_img, float kred, float kgreen, float kblue, int channels, int g_channels, int img_size);
void func(unsigned char* img, unsigned char* gray_img, float kred, float kgreen, float kblue, int channels, int g_channels, int img_size);