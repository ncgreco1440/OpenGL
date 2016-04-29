#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include "TextureCache.h"
#include <string>

class ResourceManager
{
public:
    static GLTexture getTexture(const std::string& texturePath);
    //...getModels, getSound, getMusic, getWhatever....
private:
    static TextureCache _textureCache;
};

#endif