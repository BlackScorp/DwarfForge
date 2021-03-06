/*
 * The MIT License
 *
 * Copyright 2017 BlackScorp.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   Rect.h
 * Author: BlackScorp
 *
 * Created on 27. April 2017, 20:34
 */

#ifndef RECT_H
#define RECT_H

#include <SDL_rect.h>
#include <SDL_pixels.h>
#include <SDL_render.h>
#include "../Entity.h"

class Rect : public Entity {
public:
    Rect(int width, int height);
    void onDraw(SDL_Renderer* renderer, float interpolation);
    void setColor(SDL_Color &color);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
private:
    void updateTexture();
    SDL_Rect rect;
    SDL_Color color;
    int x;
    int y;
    int z;
    int width;
    int height;
};

#endif /* RECT_H */

