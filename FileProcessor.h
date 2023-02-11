//FileProcessor header file

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>

class FileProcessor
{
    public:
    FileProcessor(); //Default constructor
    ~FileProcessor(); //Default destructor

    //Methods - declaration
    void processFile(std::string inputFile, std::string outputFile);
};

#endif