#ifndef TEXTURE_CACHE_H_
#define TEXTURE_CACHE_H_

#include <iostream>
#include <map>
#include <string>
#include "glTexture.h"
#include "ImageLoader.h"

class TextureCache
{
public:
    TextureCache();
    ~TextureCache();
    GLTexture getTexture(std::string key);
private:
    GLTexture setTexture(const std::string& key);
    
    std::map<std::string, GLTexture> _textureMap;
};

#endif