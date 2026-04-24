#include "../include/MenuLogic.h"
#include "../include/TimeAndScoreManager.h" 
#include <iomanip>

void inputStudentInfo(ThiSinh& ts) {
    std::cin.ignore();
    std::cout << "\n--- NHAP THONG TIN THI SINH ---" << std::endl;
    std::cout << "Ma Sinh Vien: ";
    std::getline(std::cin, ts.maThiSinh);
    std::cout << "Ho Ten: ";
    std::getline(std::cin, ts.hoTen);
}

void displayDashboard(const ThiSinh& ts, int totalCount) {
    std::cout << "\n=== BANG TONG QUAN TRANG THAI ===" << std::endl;
    for (int i = 0; i < totalCount; i++) {
        std::cout << "Cau " << (i + 1) << ": ";
        if (ts.dapAnDaChon[i] == ' ') std::cout << "[ _ ]  ";
        else std::cout << "[" << ts.dapAnDaChon[i] << "]  ";

        if ((i + 1) % 5 == 0) std::cout << std::endl;
    }
    std::cout << "\n=================================" << std::endl;
}

void runQuizLoop(ThiSinh& ts, const CauHoi* bank, int totalCount, int timeLimitMinutes, time_t startTime) {
    int currentIdx = 0;
    bool isFinished = false;

    // Khởi tạo mảng đáp án đã chọn (mảng động char*)
    ts.dapAnDaChon = new char[totalCount];
    for (int i = 0; i < totalCount; i++) ts.dapAnDaChon[i] = ' ';

    while (!isFinished) {
        system("cls");

        // Kiểm tra thời gian (Gọi từ TimeAndScoreManager)
        int elapsed = getElapsedTime(startTime);
        int remaining = (timeLimitMinutes * 60) - elapsed;

        if (remaining <= 0) {
            std::cout << "\n[!] HET GIO LAM BAI! He thong tu dong thu bai." << std::endl;
            ts.thoiGianLamBai = timeLimitMinutes * 60;
            system("pause");
            break;
        }

        // Hiển thị Header
        std::cout << "Thi sinh: " << ts.hoTen << " | Con lai: "
            << remaining / 60 << "p " << remaining % 60 << "s" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;

        // Hiển thị Câu hỏi
        std::cout << "[Cau " << (currentIdx + 1) << "/" << totalCount << "]" << std::endl;
        std::cout << bank[currentIdx].noiDung << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << (char)('A' + i) << ". " << bank[currentIdx].dapAn[i] << std::endl;
        }

        if (ts.dapAnDaChon[currentIdx] != ' ')
            std::cout << "\n=> Ban da chon: " << ts.dapAnDaChon[currentIdx] << std::endl;

        // Menu thao tác
        std::cout << "\n--- THAO TAC ---" << std::endl;
        std::cout << "1. Chon/Doi dap an | 2. Ke tiep | 3. Quay lai | 4. Dashboard | 5. NOP BAI" << std::endl;
        std::cout << "Chon (1-5): ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();            
            std::cin.ignore(10000, '\n');  // Xóa các ký tự chữ cái rác ra khỏi bộ đệm
            continue; // Ép vòng lặp chạy lại từ đầu thay vì đi tiếp vào switch           
        }

        switch (choice) {
        case 1: {
            std::cout << "Nhap dap an (A/B/C/D): ";
            char ans;
            std::cin >> ans;
            ts.dapAnDaChon[currentIdx] = toupper(ans);
            if (currentIdx < totalCount - 1) currentIdx++;
            break;
        }
        case 2:
            if (currentIdx < totalCount - 1) currentIdx++;
            break;
        case 3:
            if (currentIdx > 0) currentIdx--;
            break;
        case 4: {
            displayDashboard(ts, totalCount);
            std::cout << "Nhap STT cau muon toi (0 de huy): ";
            int jump;
            std::cin >> jump;
            if (jump > 0 && jump <= totalCount) currentIdx = jump - 1;
            break;
        }
        case 5: {
            std::cout << "Xac nhan nop bai? (1: Co / 0: Khong): ";
            int confirm;
            std::cin >> confirm;
            if (confirm == 1) {
                isFinished = true;
                ts.thoiGianLamBai = getElapsedTime(startTime);
            }
            break;
        }
        }
    }
}