
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

#include "functions.h"


int main(int argc, char* args[])
{
    printf("\n\t\tMake PNG grey!");
    if (argc != 4)
    {
        printf("\nERROR: Invalid arguments!\n\nUse \"./grey picture.png result.png set_[one|two|three]");
        return INV_ARGS;
    };
    
    Color set;
    int r = create_set(&set, args[3]);
    if (r != OK)
    {
        return INV_ARGS;
    }

    printf("\nSet created.\n");
    
    Image myimg;
    myimg.data = stbi_load(args[1], &myimg.width, &myimg.height, &myimg.channels, 0);
    myimg.name = args[1];

    if (!myimg.data)
    {
        printf("ERROR: unable to load %s\n", args[1]);
        return LOAD_ERROR;
    }

    printf("Loaded \"%s\" (%d x %d x %d)\n", myimg.name, myimg.width, myimg.height, myimg.channels);

    //RECOLOR
    Image gray_img = {NULL, 0, 0, 0, args[2]};
    

    make_gray(myimg, &gray_img, set);
    
    if (!gray_img.data)
    {
        printf("ERROR: unable to recolor %s\n", args[1]);
        return RECOLOR_ERROR;
    }
    printf("\n\t\tDone!\n");
    printf("\nNew size of the image: %d x %d x %d", gray_img.width, gray_img.height, gray_img.channels);
    
    
    //WRITING
    stbi_write_png(gray_img.name, gray_img.width, gray_img.height, gray_img.channels, gray_img.data, gray_img.width * gray_img.channels);
    
    //FREE
    stbi_image_free(gray_img.data);
    stbi_image_free(myimg.data);
    return 0;
}
