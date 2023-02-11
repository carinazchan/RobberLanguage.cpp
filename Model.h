//Model header file

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

class Model
{
    public:
        Model(); //Default constructor
        ~Model(); //Default destructor

        //Methods - declaration
        std::string translateSingleConsonant(char inputConsonant);
        std::string translateSingleVowel(char inputVowel);
};

#endif