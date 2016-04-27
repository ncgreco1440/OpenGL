#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include <vector>
#include <fstream>

class IOManager
{
public:
    static bool readFileToBuffer(const std::string& filePath, std::vector<unsigned char>& buffer);
};

#endif

