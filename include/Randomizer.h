#pragma once 
#include "Structs.h"
#include<cstdlib> // rand() - srand()
#include<ctime> // time()

void initRandomizer();

void shuffleQuestions(CauHoi* bank, int count);

void shuffleAnswers(CauHoi& q);