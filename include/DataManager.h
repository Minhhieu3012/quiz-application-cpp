#pragma once 
#include "Structs.h"
#include<fstream>
#include<iostream>

CauHoi* loadQuestionBank(const std::string& filePath, int& count);

void deleteQuestionBank(CauHoi*& bank);