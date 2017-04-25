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
#include "Game.h"

Game::Game() {

}

void Game::run() {
    time_t nextGameTick;


    Game::isRunning = true;

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
            nextGameTick +=skipTicks;
            loops++;
        }
        interpolation = (float)(time(NULL) + skipTicks - nextGameTick) / (float)skipTicks;
        this->display(interpolation);
    }
}

void Game::update(){
  
}

void Game::display(float interpolation){
     
}