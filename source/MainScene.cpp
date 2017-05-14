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
 * File:   MainScene.cpp
 * Author: BlackScorp
 * 
 * Created on 26. April 2017, 18:23
 */


#include "MainScene.h"

MainScene::MainScene(SDL_Renderer* renderer, EntityManager* entityManager) {
    this->renderer = renderer;
    this->entityManager = entityManager;
}

void MainScene::render() {

    int rendererWidth = 0, rendererHeight = 0;
    Rect *backgroundRect, *testRect;
    SDL_Color backgroundColor, color;

    SDL_GetRendererOutputSize(this->renderer, &rendererWidth, &rendererHeight);


    backgroundRect = new Rect(rendererWidth, rendererHeight);
    backgroundColor.r = 123;
    backgroundColor.g = 120;
    backgroundColor.b = 115;
    backgroundRect->setColor(backgroundColor);

    entityManager->add(backgroundRect);



    testRect = new Rect(100, 200);
    testRect->setX(100);
    testRect->setY(50);
    testRect->on("update", [testRect]() {
        int x = testRect->getX();
        x++;
        if(x > 500){
            x = 0;
        }
        testRect->setX(x);
    });

    color.r = 90;
    color.b = 0;
    color.g = 0;

    testRect->setColor(color);
    entityManager->add(testRect);
}
