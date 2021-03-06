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
 * File:   Entity.cpp
 * Author: BlackScorp
 * 
 * Created on 27. April 2017, 20:25
 */


#include "Entity.h"

std::string Entity::getId() {
    return this->id;
}

void Entity::setId(std::string id) {
    this->id = id;
}
void Entity::on(std::string eventName, std::function<void(EventData *data) > callback) {
    this->bindings[eventName] = callback;
}

void Entity::trigger(std::string eventName, EventData *data) {
    if (this->bindings.find(eventName) != this->bindings.end()) {
        this->bindings[eventName](data);
    };
}