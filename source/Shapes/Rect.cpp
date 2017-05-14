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
 * File:   Rect.cpp
 * Author: BlackScorp
 * 
 * Created on 27. April 2017, 20:34
 */



#include "Rect.h"

Rect::Rect(int width, int height) {
    this->width = width;
    this->height = height;
    this->x = 0;
    this->y = 0;
    this->on("draw", [this](EventData * data) {
       
        this->rect.x = this->x;
        this->rect.y = this->y;
        this->rect.w = this->width;
        this->rect.h = this->height;
        SDL_SetRenderDrawColor(data->draw.renderer, this->color.r, this->color.g, this->color.b, this->color.a);
        SDL_RenderFillRect(data->draw.renderer, &this->rect);
        
    });
}

void Rect::setX(int x) {
    this->x = x;
}

void Rect::setY(int y) {
    this->y = y;
}

int Rect::getX() {
    return this->x;
}

int Rect::getY() {
    return this->y;
}

void Rect::setColor(SDL_Color &color) {
    this->color = color;
}
