//Translator header file

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include "Model.h"

class Translator
{
    public:
    Translator(); //Default constructor
    ~Translator(); //Default destructor

    //Methods - declaration
    std::string translateEnglishWord(std::string inputWord);
    std::string translateEnglishSentence(std::string inputSentence);
};

#endif