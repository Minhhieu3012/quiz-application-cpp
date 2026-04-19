#pragma once
#include "Structs.h"
#include <string>

void saveHistory(const ThiSinh& ts, const std::string& filePath);

ThiSinh* loadHistory(const std::string& filePath, int& count);
void displayLeaderboard(ThiSinh* arr, int count, int topN);
void deleteHistory(ThiSinh*& arr); 

void reviewExam(const CauHoi* bank, int count, const ThiSinh& ts, bool onlyWrong);