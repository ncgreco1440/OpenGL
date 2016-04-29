#include "TextureCache.h"

/**********************************************************!
 * PUBLIC METHODS
 **********************************************************/
TextureCache::TextureCache()
{
    //...
}

TextureCache::~TextureCache()
{
    //...
}

GLTexture TextureCache::getTexture(std::string key)
{
    // Look up texture
    // returns std::map<std::string, GLTexture>::iterator in which we use 'auto' instead because it's neater!
    auto mit = _textureMap.find(key);
    
    // Check if not in map
    if(mit == _textureMap.end())
    {
        GLTexture newTexture = ImageLoader::loadImage(key);
        _textureMap.insert(std::pair<std::string, GLTexture>(key, newTexture));
        std::cout << "Loaded new texture!" << std::endl;
        return newTexture;
    }
    std::cout << "Loaded cached texture!" << std::endl;
    return mit->second;
}

/**********************************************************!
 * PRIVATE METHODS
 **********************************************************/
GLTexture TextureCache::setTexture(const std::string &key)
{
    // Create a new texture and store it in the map!
    GLTexture newTexture = ImageLoader::loadImage(key);
    _textureMap.insert(std::pair<std::string, GLTexture>(key, newTexture));
    std::cout << "Loaded new texture!" << std::endl;
    return _textureMap[key];
}