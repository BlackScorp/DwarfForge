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
 * File:   ImageResource.cpp
 * Author: BlackScorp
 * 
 * Created on 26. April 2017, 20:31
 */



#include "ImageResource.h"

 ImageResource::ImageResource(SDL_Renderer* _renderer, std::string _fileName){
     if(NULL == _renderer){
         return;
     }
     renderer = _renderer;
     fileName = _fileName;
     
     SDL_Surface *surface = IMG_Load(fileName.c_str());
     if(NULL == surface){
         return;
     }
     this->texture = SDL_CreateTextureFromSurface(renderer,surface);
     if(NULL == texture){
         return;
     }
     SDL_QueryTexture(texture,NULL,NULL,&width,&height);
     
     SDL_FreeSurface(surface);
     
 }
