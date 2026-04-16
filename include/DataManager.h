#pragma once 
#include "Structs.h"
#include<fstream>
#include<iostream>

cauHoi* loadQuestionBank(const std::string& filePath, int& count);

void deleteQuestion(cauHoi*& bank);