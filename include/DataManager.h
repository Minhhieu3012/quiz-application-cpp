#pragma once 
#include "Structs.h"
#include<fstream>
#include<iostream>

CauHoi* loadQuestionBank(const std::string& filePath, int& count);
CauHoi* filterQuestionsByDifficulty(CauHoi* bank, int totalCount, int difficultyLevel, int& filteredCount);		


void deleteQuestionBank(CauHoi*& bank);