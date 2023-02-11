#include <iostream>
#include <string>
#include <fstream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"


FileProcessor::FileProcessor(){}; //Translator constructor
FileProcessor::~FileProcessor(){}; //Translator destructor

//Methods - definition
void FileProcessor::processFile(std::string inputFile, std::string outputFile) //Reads a text file, translates contents, outputs to an html file
{

    std::fstream currentFile; //File stream from text file
    std::ofstream outputStream; //File stream for outputting to an html file
    std::string fileString; //String that will be outputted to the html file

    //Reading file input, putting it into a string
    currentFile.open(inputFile, std::ios::in); //Open text file
    if (currentFile.is_open()) //If text file open
    {
        outputStream.open(outputFile, std::ios::out); //Open file stream to output to html file

        outputStream << " <!DOCTYPE html> <html> <head> <title>English to Robber Translation - CPSC 350 (Carina Chan) </title> </head> <body>"; //Start of html file

        //Output original text file contents to html file
        while (getline(currentFile, fileString)) //Reads each line from text file, outputs it to html file
        {
            if (outputStream.is_open()) //If file stream to html file is open
            {
                outputStream << "<p><b>" << fileString << "</b></p>"; //Outputs text file line directly to html file in bold
            }
        }

        currentFile.close(); //Close text file
        currentFile.open(inputFile, std::ios::in); //Reopen text file so it can be read from the start
        outputStream << "<p><br></p>"; //New line for separating original text and translated text

        //Output original text file contents to html file
        while (getline(currentFile, fileString)) //Reads each line from text file, translates it, outputs it to html file
        {
            //Translating contents
            Translator T1 = Translator(); //Translator object for using translator methods
            std::string translatedFileString;
            translatedFileString = T1.translateEnglishSentence(fileString); //Translates the line read from text file

            //Outputting to a file
            if (outputStream.is_open()) //If file stream to html file is open
            {
                outputStream << "<p><i>" << translatedFileString << "</i></p>"; //Outputs translated line to html file in italics
            }

        }

        outputStream << "</body> </html>"; //End of html file

        outputStream.close(); //Close output stream to html file
        currentFile.close(); //Close text file
    }
    
}