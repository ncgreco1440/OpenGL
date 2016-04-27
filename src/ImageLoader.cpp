#include "ImageLoader.h"
#include "IOManager.h"
#include "picopng.h"
#include <SOIL/SOIL.h>
#include <iostream>

// picoPNG
GLTexture ImageLoader::loadPNG(const std::string& filePath)
{
    GLTexture texture = {};         //Initalize everything to 0
    std::vector<unsigned char> out_img;
    std::vector<unsigned char> in_img;
    unsigned long width;
    unsigned long height;
    
    if(IOManager::readFileToBuffer(filePath, in_img))
        std::cout << "PNG file loaded to buffer" << std::endl;
    else
    {
        std::cerr << "PNG failed to load!" << std::endl;
        exit(101);
    }
    
    int errorCode = decodePNG(out_img, width, height, &(in_img[0]), in_img.size());
    if(errorCode != 0)
    {
        std::cerr << "decodePNG failed with error: " << errorCode << std::endl;
        exit(errorCode);
    }
    
    glGenTextures(1, &(texture.id));                    // generate the texture
    
    glBindTexture(GL_TEXTURE_2D, texture.id);           // bind the texture
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out_img[0]));
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);        // inbind the current texture
    
    texture.width = width;
    texture.height = height;
    return texture;
}

// libSOIL
GLTexture ImageLoader::loadImage(const std::string &filePath)
{
    GLTexture texture = {};
    int h, w;
    unsigned char * image = SOIL_load_image(filePath.c_str(), &w, &h, 0, SOIL_LOAD_RGBA);
    
    // Generate and Bind the texture
    glGenTextures(1, &(texture.id));
    glBindTexture(GL_TEXTURE_2D, texture.id);
    
    // Set Texture wrapping to GL_REPEAT (usual basic wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);       // U
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);       // V
    
    // Set Texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    // Free up memory
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    texture.height  = h;
    texture.width = w;
    
    return texture;
}