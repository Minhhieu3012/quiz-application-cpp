#pragma once
#include "Structs.h"
#include <ctime>
#include <iostream>
#include <iomanip>

void startTimer(time_t& startTime);

int getElapsedTime(time_t startTime);

bool isTimeUp(time_t startTime, int limitMinutes);

void gradeExam(const CauHoi* bank, int totalCount, ThiSinh& ts);

void displayStatistics(const ThiSinh& ts, int totalCount, time_t startTime);