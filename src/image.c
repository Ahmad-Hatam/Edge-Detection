#include "image.h"

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void apply_threshold(float *img, int w, int h, int T) {
    if(img ==NULL || w <=0 || h<=0){
        return;
    }
    int size = w * h;

    for (int i = 0; i < size; i++){
        if(img[i] > T){
            img[i] = 255.0;
        }
        else
        {
            img[i] = 0.0;
        }
    
}
}


void scale_image(float *result, const float *img, int w, int h) {
    if(img ==NULL || w <=0 || h<=0 || result == NULL){
        return;
    }
    
    float min = INT_MAX;
    float max = INT_MIN;
    int size = w*h;

    for (int i = 0; i < size; i++){
        if (img[i]< min){
            min = img[i];
        }
        if (img[i]> max){
            max = img[i];
        }
    }
    for (int j=0;j< size;j++){
    if (min == max){
        result[j] = 0.0;
    }
    else{
        result[j] = ((img[j]-min)/(max - min)) * 255.0;

    }

    }
}


float get_pixel_value(const float *img, int w, int h, int x, int y) {
    if(img==NULL|| w<=0||h<=0){
        return 0.0f;
    }
    if (x>= w){
        x = (2 * w) - 1 -x;
        if (x< 0){
            return get_pixel_value(img,  w,  h, x,  y);
        }
    }
    if (y>= h){
        y= (2 * h) - 1 -y;
        if (y < 0){
            return get_pixel_value(img, w, h, x, y);
        }
    }
    if (x < 0){
        x = (-x -1);
        if (x > w){
            return get_pixel_value(img,  w,  h,  x,  y);
        }
    }
    
    if (y < 0){
        y = (-y -1);
        if (y > h){
            return get_pixel_value(img, w, h, x, y);
        }
    }
    return img[(y*w) +x];
}


float *array_init(int size) {
    
    if (size <= 0){
        return NULL;
    }
    float *array;
    array = (float *)calloc(size, sizeof(float));
    
    return array;
}

void array_destroy(float *m) {
    if (m!= NULL){
        
    free(m);
    }
    m = NULL;
    return;

}



float *read_image_from_file(const char *filename, int *w, int *h) {
    
    FILE* file;
    char buffer[100];
    file = fopen(filename, "r");
    int width, height;
    if (file == NULL){
        return NULL;
    }

    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        fclose(file);
        return NULL;
    }

    if (buffer[0] != 'P' || buffer[1] != '2') {
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "%d %d", &width, &height) != 2 || width <=0 || height <=0) {
        fclose(file);
        return NULL;
    }


    int max_pix;
    if (fscanf(file, "%d", &max_pix) != 1 || max_pix != 255) {
        fclose(file);
        return NULL;
    }

    
    float *array = array_init(width*height);
    if (array == NULL){
        fclose(file);
        return NULL;
    }
    int c;
    int i=0;
    while(fscanf(file, "%d", &c)!=EOF){
        if(c <0 || c> 255){
            array_destroy(array);
            fclose(file);
            return NULL;
        }
        if (i <width *height){

            array[i] = c;
            i+=1;
        }
        else{
            array_destroy(array);
            fclose(file);
            return NULL;
        }
    }

    if (i != width *height){
        array_destroy(array);
        fclose(file);
        return NULL;
    }
    *w = width;
    *h = height;

    fclose(file);
    return array;
}

void write_image_to_file(const float *img, int w, int h, const char *filename) {
    if (filename == NULL ||img == NULL|| w<=0 || h<=0){
        // fclose(file);
        return;
    }
    
    FILE *file = fopen(filename,"w");
    
    if (w > 0 && h > 0) {
    fprintf(file, "P2\n%d %d\n%d\n", w, h, 255);
}
    int num;
    for (int i = 0; i < w*h; i++) {
        num = img[i];
        fprintf(file, "%d ", num);  
    }
    fclose(file);
    return;
}
