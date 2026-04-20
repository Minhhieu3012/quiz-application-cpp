#pragma once
#include "Structs.h"
#include <iostream>
#include <string>
#include <vector>

void inputStudentInfo(ThiSinh& ts);

void displayDashboard(const ThiSinh& ts, int totalCount);

void runQuizLoop(ThiSinh& ts, const CauHoi* bank, int totalCount, int timeLimitMinutes, time_t startTime);