#include "Canvas.h"
#include <stdio.h>
#include <stdarg.h>

Canvas::Canvas(int height,int width) {
    this->screen = new char* [height];
    for(int i = 0; i < height; i ++)
        this->screen[i] = new char[width];
    this->width = width;
    this->height = height;
}

void Canvas::set_pixel(int y, int x, char ch) {
    if(x < 0 || x >= width || y < 0 || y >= height) return;
    screen[y][x] = ch;
}

// tuples of x, y, value
void Canvas::set_pixels(int count, ...) {
    va_list Pixels;
    va_start(Pixels, count);
    for(int i = 0; i < count; i ++) {
        int x = va_arg(Pixels, int);
        int y = va_arg(Pixels, int);
        int value = va_arg(Pixels, int);
        set_pixel(x, y, (char)value);
    }
    va_end(Pixels);
}

void Canvas::print() const { //shows what was printed
    for(int i = 0; i < height; i ++)
        printf("%.*s\n", width, screen[i]);
} 
void Canvas::clear() { //clears the canvas
    for(int i = 0; i < height; i ++)
        for(int j = 0; j < width; j ++)
            this->screen[i][j] = ' ';
} 