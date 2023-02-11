#include <iostream>
#include <string>
#include "Model.h"

Model::Model(){} //Model constructor
Model::~Model(){} //Model destructor

//Methods - definition

std::string Model::translateSingleConsonant(char inputConsonant) //Translates a single constant into the robber language, returns a string
{

    std::string finalConsonantString = ""; //Finalized string of consonant in robber language - declaration

    if (ispunct(inputConsonant)) //If the char is punctuation
    {
        finalConsonantString += inputConsonant;
    }

    else //If the char is a consonant
    {
        finalConsonantString += inputConsonant;
        finalConsonantString += "o";
        finalConsonantString += inputConsonant;
    }

    return finalConsonantString;

}


std::string Model::translateSingleVowel(char inputVowel) //Translates a single vowel into the robber language, returns a string
{

    std::string finalVowelString = ""; //Finalized string of vowel in robber language - declaration
    
    finalVowelString += inputVowel;

    return finalVowelString;

}