#ifndef FILE_IO_H_
#define FILE_IO_H_

#include <string>
#include <fstream>
#include <Gameconfig/config.h>

namespace utils
{
    extern std::string read_file(const char * filepath)
    {
//        Eww old C way of doing things... :P
        
//        FILE* file = fopen(filepath, "rt");
//        
//        fseek(file, 0, SEEK_END);
//        unsigned long length = ftell(file);
//        char* data = new char[length + 1];
//        memset(data, 0, length + 1);
//        fseek(file, 0, SEEK_SET);
//        fread(data, 1, length, file);
//        fclose(file);
//        
//        std::string result(data);
//        delete[] data;
//        return result;
        
        std::fstream file(filepath);
        if(file.fail())
        {
            std::string msg = "Could not open requested file \"";
                msg += filepath;
                msg += "\"";
            gcnfg::fatal_error(-1, msg);
        }
        
        std::string contents;
        std::string line;
        while(std::getline(file, line))
        {
            contents += line + '\n';
        }
        
        file.close();
        return contents;
    }
}

#endif