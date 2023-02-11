#include <iostream>
#include <string>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"

int main()
{
    FileProcessor FP1 = FileProcessor();
    FP1.processFile("original.txt", "Translation.html");
}

