#ifndef IMAGELOADER_H_
#define IMAGELOADER_H_

#include <glTexture.h>
#include <string>

class ImageLoader
{
public:
    // picoPNG
    static GLTexture loadPNG(const std::string& filePath);
    // SOIL
    static GLTexture loadImage(const std::string& filePath);
};

#endif