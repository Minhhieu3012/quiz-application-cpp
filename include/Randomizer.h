#pragma once 
#include "Structs.h"
#include<cstdlib>
#include<ctime>

void initRandomizer();

void shuffleQuestions(CauHoi* bank, int count);

void shuffleAnswers(CauHoi& q);