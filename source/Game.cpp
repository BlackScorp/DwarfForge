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
 * File:   Game.cpp
 * Author: BlackScorp
 * 
 * Created on 25. April 2017, 19:02
 */

#include <time.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.h"

Game::Game() {

}

bool Game::init() {
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        sprintf(this->error,"SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
        return false;
    }
    
    this->window = SDL_CreateWindow("Dwarf Forge",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            1024,
            768, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (NULL == this->window) {
        sprintf(this->error,"Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);

    if (NULL == this->renderer) {
        sprintf(this->error,"Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void Game::run() {
    


    Game::isRunning = true;
    time_t nextGameTick;
    int tiksPerSecond = 25;
    int skipTicks = 1000 / tiksPerSecond;
    int maxFrameSkip = 5;
    int loops;
    float interpolation;

    nextGameTick = time(NULL);

    while (Game::isRunning) {
        loops = 0;
        while (time(NULL) > nextGameTick && loops < maxFrameSkip) {
            this->update();
            nextGameTick += skipTicks;
            loops++;
        }
        interpolation = ((float) (time(NULL) + skipTicks - nextGameTick)) / ((float) skipTicks);
        this->display(interpolation);
    }
    this->close();
}

char* Game::getError() {
    return this->error;
}
void Game::close(){
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}
void Game::update() {

}

void Game::display(float interpolation) {

}