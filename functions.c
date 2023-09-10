#include "functions.h"

void recolor(Image img, Image* gray_img, Color set)
{
    int img_size = img.width * img.height * img.channels;
    int gray_img_size = gray_img->width * gray_img->height * gray_img->channels;
    gray_img->data = (unsigned char*)malloc(gray_img_size);

    if (gray_img == NULL)
    {
        printf("ERROR:unable to allocate memory for the gray image.\n");
        return;
    }
    FILE *file = fopen("timing.txt", "a");
    clock_t start_time = clock();
    #ifdef ASSEMBLER
    //printf("ASSEMBLER IMPLEMENTATION...\n");
    func_asm(img.data, gray_img->data, set.kred, set.kgreen, set.kblue, img.channels, gray_img->channels, img_size);
    
    #else
    //printf("C IMPLEMENTATION...\n");
    func(img.data, gray_img->data, set.kred, set.kgreen, set.kblue, img.channels, gray_img->channels, img_size);
    #endif
    clock_t end_time = clock();
    double res_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Записываем результаты в файл
    fprintf(file, "%f\n", res_time);
    fclose(file);
}

void func(unsigned char* img, unsigned char* gray_img, float kred, float kgreen, float kblue, int channels, int g_channels, int img_size)
{
    //printf("C IMPLEMENTATION...\n");
    
    for (unsigned char *p = img,*pg = gray_img; p != img + img_size; p += channels, pg += g_channels)
    {
        *pg = (uint8_t)(*p * kred + *(p + 1) * kgreen + *(p + 2) * kblue);
        if (channels == 4)
        {
            *(pg + 1) = *(p + 3);
        }
    }
}

void make_gray(Image img, Image* gray_img, Color set)
{
    if (img.channels == 4){
        gray_img->channels = 2;
    }
    else{
        gray_img->channels = 1;
    }
    gray_img->width = img.width;
    gray_img->height = img.height;
    printf("Recoloring input picture to gray: \"%s\"...\n", gray_img->name);
    recolor(img, gray_img, set);
}


int create_set(Color *set, char* flag)
{
    if (strcmp(flag, "set_one") == 0)
    {
        set->kred = 0.3;
        set->kgreen = 0.59;
        set->kblue = 0.11;
    }
    else if (strcmp(flag, "set_two") == 0){
        set->kred = 0.299;
        set->kgreen = 0.587;
        set->kblue = 0.114;
    }
    else if(strcmp(flag, "set_three") == 0) {
        set->kred = 0.2126;
        set->kgreen = 0.7152;
        set->kblue = 0.0722;}
    else{
        printf("ERROR: Invalid arguments!\n");
        return INV_ARGS;
    }
    return OK;
}
