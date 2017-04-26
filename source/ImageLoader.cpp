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
 * File:   ImageLoader.cpp
 * Author: BlackScorp
 * 
 * Created on 26. April 2017, 20:05
 */

#include "ImageLoader.h"

ImageLoader::ImageLoader() {
}

std::string ImageLoader::getCurrentWorkingDir() {
    char buffer[FILENAME_MAX];
    GetCurrentDir(buffer, FILENAME_MAX);
    std::string currentWorkingDir(buffer);
    return currentWorkingDir;
}

std::vector<std::string> ImageLoader::getFilesInFolder(std::string folderName) {
    DIR * folderHandle;
    std::vector<std::string> files;
    std::string path = getCurrentWorkingDir();
    dirent* fileHandle = NULL;

    if ("" != folderName) {
        path += DIRECTORY_SEPERATOR + folderName;
    }

    folderHandle = opendir(path.c_str());

    if (false == folderHandle) {
        return files;
    }

    while (NULL != (fileHandle = readdir(folderHandle))) {
        if ("." == std::string(fileHandle->d_name) ||
                ".." == std::string(fileHandle->d_name)) {
            continue;
        }
        files.push_back(std::string(path+DIRECTORY_SEPERATOR+fileHandle->d_name));
    }
    closedir(folderHandle);
    return files;
}

void ImageLoader::load(SDL_Renderer* renderer) {
    std::vector<std::string> files = getFilesInFolder("media/images");

    for (std::vector<std::string>::iterator iterator = files.begin(); iterator != files.end(); ++iterator) {
        std::cout << *iterator;
    }
}