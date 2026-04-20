#include <iostream>
#include "include/DataManager.h"
#include "include/Randomizer.h"
#include "include/MenuLogic.h"
#include "include/TimeAndScoreManager.h"
#include "include/HistoryManager.h"

int main() {
    initRandomizer(); 
    bool isRunning = true;

    while (isRunning) {
        system("cls");
        std::cout << "========================================" << std::endl;
        std::cout << "       HE THONG THI TRAC NGHIEM C++     " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "1. Bat dau ca thi moi" << std::endl;
        std::cout << "2. Xem Bang xep hang" << std::endl;
        std::cout << "0. Thoat" << std::endl;
        std::cout << "Lua chon: ";

        int mainChoice;
        std::cin >> mainChoice;

        if (mainChoice == 1) {
            ThiSinh ts;
            inputStudentInfo(ts);

            int totalInBank = 0;
            CauHoi* fullBank = loadQuestionBank("data/QuestionBank.txt", totalInBank);

            if (!fullBank) {
                system("pause");
                continue;
            }

            std::cout << "Chon do kho (1: De, 2: TB, 3: Kho): ";
            int level; std::cin >> level;
            int examCount = 0;
            CauHoi* examBank = filterQuestionsByDifficulty(fullBank, totalInBank, level, examCount);

            if (examBank) {
                shuffleQuestions(examBank, examCount);
                for (int i = 0; i < examCount; i++) shuffleAnswers(examBank[i]);

                time_t startTime;
                startTimer(startTime);
                runQuizLoop(ts, examBank, examCount, 15, startTime); 

                gradeExam(examBank, examCount, ts);
                displayStatistics(ts, examCount, startTime);


                delete[] ts.dapAnDaChon;
                deleteQuestionBank(examBank);
            }
            deleteQuestionBank(fullBank);
            system("pause");
        }
        else if (mainChoice == 0) isRunning = false;
    }

    return 0;
}