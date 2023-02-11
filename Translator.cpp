#include <iostream>
#include <string>
#include "Model.h"
#include "Translator.h"

Translator::Translator(){}; //Translator constructor
Translator::~Translator(){}; //Translator destructor

//Methods - definition

std::string Translator::translateEnglishWord(std::string inputWord) //Translates a word into the robber language, returns a string
{
    
    std::string finalWord = ""; //String representing the original char translated from english to the robber language - declaration
    std::string tempS1 = ""; //Temporary string for each translated char in inputWord to append to
    char currentChar;
    
    Model M1 =  Model(); //Model object for using model methods

    //Cycle through the chars in inputWord
    for (int i=0; i<inputWord.size(); i++)
    {
        currentChar = inputWord[i]; //Initialize currentChar with the current character
        tempS1 = ""; //Reinitializes tempS1 with empty string

        //Chunk for uppercase characters
        if (isupper(currentChar))
        {
            switch (currentChar)
            {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                    tempS1 += M1.translateSingleVowel(currentChar); //Append translated vowel to tempS1
                    break;
                
                default:
                    tempS1 += M1.translateSingleConsonant(currentChar); //Append translated consonant to tempS1
                    break;
            }          
        }


        //Chunk for lowercase characters
        else
        {
             switch (currentChar)
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    tempS1 += M1.translateSingleVowel(currentChar); //Append translated vowel to tempS1
                    break;
                default:
                    tempS1 += M1.translateSingleConsonant(currentChar); //Append translated consonant to tempS1
                    break;
            }  
        }

        finalWord += tempS1; //Append translated char to finalWord

    }

    return finalWord;

}


std::string Translator::translateEnglishSentence(std::string inputSentence) //Translates a sentence into the robber language, returns a string
{

    std::string tempS2 = ""; //String to hold temporary word before translation
    std::string finalSentence = "";
    inputSentence += ' '; //Append space at the end of inputSentence so the last word will get translated and added to finalSentence

    //Cycle through the chars in inputSentence
    for (int i=0; i<inputSentence.size(); i++)
    {
        if (inputSentence[i] != ' ') //If the char is not a space
        {
            tempS2 += inputSentence[i]; //Append char to temporary string before translation
        }

        else //If the char is a space
        {
            finalSentence += translateEnglishWord(tempS2) + ' '; //Translate temporary string, append translated string to finalSentence, separate words with a space
            tempS2 = ""; //Reinitializes tempS2 with empty string
        }
    }

    return finalSentence;

}