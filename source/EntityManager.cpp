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
 * File:   EntityManager.cpp
 * Author: BlackScorp
 * 
 * Created on 27. April 2017, 20:19
 */




#include "EntityManager.h"

void EntityManager::add(Entity *entity) {
    int size = entites.size();

    std::ostringstream stream;
    stream << "entity" << ++size;
    std::string id = stream.str();

    entity->setId(id);
    entites[id] = entity;
}

Entity* EntityManager::get(std::string Id) {
    if (entites.find(Id) == entites.end()) return 0;
    return entites[Id];
}

void EntityManager::update() {
    for (std::map<std::string, Entity* >::iterator iterator = entites.begin(); iterator != entites.end(); ++iterator) {
        iterator->second->trigger("update");
    }
}

void EntityManager::draw(SDL_Renderer* renderer, float interpolation) {
    EventData eventData;
    
    eventData.draw.renderer = renderer;
    eventData.draw.interpolation = interpolation;
    for (std::map<std::string, Entity* >::iterator iterator = entites.begin(); iterator != entites.end(); ++iterator) {
        iterator->second->trigger("draw",&eventData);
    }
}
void EntityManager::keyDown(SDL_Keysym* keySym) {
    EventData eventData;
    
    eventData.keySym = keySym;

    for (std::map<std::string, Entity* >::iterator iterator = entites.begin(); iterator != entites.end(); ++iterator) {
        iterator->second->trigger("keyDown",&eventData);
    }
}