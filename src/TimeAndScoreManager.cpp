#include "../include/TimeAndScoreManager.h"

void startTimer(time_t& startTime) {
    startTime = time(NULL);
}

int getElapsedTime(time_t startTime) {
    time_t currentTime = time(NULL);
    return (int)difftime(currentTime, startTime);
}

bool isTimeUp(time_t startTime, int limitMinutes) {
    int elapsedSeconds = getElapsedTime(startTime);
    return elapsedSeconds >= (limitMinutes * 60);
}

void gradeExam(const CauHoi* bank, int totalCount, ThiSinh& ts) {
    int correctCount = 0;

    for (int i = 0; i < totalCount; i++) {
        if (ts.dapAnDaChon[i] == bank[i].dapAnDung) {
            correctCount++;
        }
    }

    ts.diemSo = (float)correctCount;
}

void displayStatistics(const ThiSinh& ts, int totalCount, time_t startTime) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "          KET QUA BAI THI CHINH THUC     " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Thi sinh: " << ts.hoTen << " (MSSV: " << ts.maThiSinh << ")" << std::endl;

    char* timeString = ctime(&startTime);
    std::cout << "Thoi gian bat dau: " << timeString; // ctime tự động có sẵn dấu xuống dòng

    std::cout << "So cau tra loi dung: " << (int)ts.diemSo << "/" << totalCount << std::endl;

    float percentage = (ts.diemSo / totalCount) * 100;
    std::cout << "Ti le chinh xac: " << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;

    int mins = ts.thoiGianLamBai / 60;
    int secs = ts.thoiGianLamBai % 60;
    std::cout << "Tong thoi gian lam bai: " << mins << " phut " << secs << " giay" << std::endl;

    float avgTime = (float)ts.thoiGianLamBai / totalCount;
    std::cout << "Toc do trung binh: " << avgTime << " giay/cau" << std::endl;
    std::cout << "========================================\n" << std::endl;
}