#include "Canvas.h"
#include <stdio.h>

Canvas::Canvas(int width,int height) {
    this->screen = new char* [height];
    for(int i = 0; i < height; i ++)
        this->screen[i] = new char[width];
    this->width = width;
    this->height = height;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int yoffset = ray;
    for(int xoffset = 0; xoffset <= ray / 2; xoffset ++)
        if(xoffset * xoffset + yoffset * yoffset <= ray * ray) {
            if(y + yoffset >= 0 && y + yoffset < height && x + xoffset >= 0 && x + xoffset < width)
                screen[y + yoffset][x + xoffset] = ch;
            if(y - yoffset >= 0 && y - yoffset < height && x + xoffset >= 0 && x + xoffset < width)
                screen[y - yoffset][x + xoffset] = ch;
            if(y + yoffset >= 0 && y + yoffset < height && x - xoffset >= 0 && x - xoffset < width)
                screen[y + yoffset][x - xoffset] = ch;
            if(y - yoffset >= 0 && y - yoffset < height && x - xoffset >= 0 && x - xoffset < width)
                screen[y - yoffset][x - xoffset] = ch;

            if(y + xoffset >= 0 && y + xoffset < height && x + yoffset >= 0 && x + yoffset < width)
                screen[y + xoffset][x + yoffset] = ch;
            if(y - xoffset >= 0 && y - xoffset < height && x + yoffset >= 0 && x + yoffset < width)
                screen[y - xoffset][x + yoffset] = ch;
            if(y + xoffset >= 0 && y + xoffset < height && x - yoffset >= 0 && x - yoffset < width)
                screen[y + xoffset][x - yoffset] = ch;
            if(y - xoffset >= 0 && y - xoffset < height && x - yoffset >= 0 && x - yoffset < width)
                screen[y - xoffset][x - yoffset] = ch;
        } else {
            yoffset --;
            xoffset --;
        }
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(int yoffset = -ray; yoffset <= ray; yoffset ++)
        for(int xoffset = -ray; xoffset <= ray; xoffset ++)
            if((xoffset) * (xoffset) + (yoffset) * (yoffset) <= ray * ray)
                this->screen[y + yoffset][x + xoffset] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    if(left < 0) left = 0;
    if(right >= width) right = width - 1;
    if(top < 0) top = 0;
    if(bottom >= height) bottom = height - 1;

    for(int i = left; i <= right; i ++)
        screen[top][i] = screen[bottom][i] = ch;
    for(int i = top + 1; i <= bottom - 1; i ++)
        screen[i][left] = screen[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    if(left < 0) left = 0;
    if(right >= width) right = width - 1;
    if(top < 0) top = 0;
    if(bottom >= height) bottom = height - 1;

    for(int y = top; y <= bottom; y ++)
        for(int x = left; x <= right; x ++)
            screen[y][x] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {
    if(x < 0 || x >= width || y < 0 || y >= height) return;
    screen[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = x1 - x2;
    int dy = y1 - y2;

    int sx = -1, sy = 1;
    if(dx < 0) dx *= -1, sx = 1;
    if(dy > 0) dy *= -1, sy = -1;

    int err = dx + dy, err2;

    while(true) {
        if(x1 >= 0 && x1 < width && y1 >= 0 && y1 < height)
            screen[y1][x1] = ch;

        if(x1 == x2 && y1 == y2) break;

        err2 = 2 * err;
        if(err2 >= dy) {
            if(x1 == x2) break;

            err += dy;
            x1 += sx;
        }

        if(err2 <= dx) {
            if(y1 == y2) break;

            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print() { //shows what was printed
    for(int i = 0; i < height; i ++)
        printf("%.*s\n", width, screen[i]);
} 
void Canvas::Clear() { //clears the canvas
    for(int i = 0; i < height; i ++)
        for(int j = 0; j < width; j ++)
            this->screen[i][j] = ' ';
} 