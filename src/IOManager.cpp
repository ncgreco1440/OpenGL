#include "IOManager.h"

bool IOManager::readFileToBuffer(std::string& filePath, std::vector<char>& buffer)
{
    //specify that we are reading the file as raw binary
    std::ifstream file(filePath, std::ios::binary);
    if(file.fail())
    {
        perror(filePath.c_str());
        return false;
    }
    //figure out how big the file is
    file.seekg(0, std::ios::end);           //go to the end of the file
    long long fileSize = file.tellg();      //tell our variable how big the file is
    file.seekg(0, std::ios::beg);           //go back to the begining of the file
    fileSize -= file.tellg();               //get rid of extra bytes we don't need from the file
    
    buffer.resize(fileSize);
    //point to first address of buffer since that is a char *
    file.read(&(buffer[0]), fileSize);
    file.close();
    
    return true;                            //Woot
}

