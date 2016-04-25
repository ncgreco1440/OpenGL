#ifndef IOMANAGER_H_
#define IOMANAGER_H_

#include <vector>
#include <fstream>

class IOManager
{
public:
    static bool readFileToBuffer(std::string& filePath, std::vector<char>& buffer);
};

#endif

