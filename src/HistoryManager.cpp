#include "../include/HistoryManager.h"
#include <fstream>
#include <iostream>

// LƯU OUTPUT

void saveHistory(const ThiSinh& ts, const std::string& filePath) {
    //ghi tiếp nối vào cuối file
    std::ofstream file(filePath, std::ios::app); 
    if (file.is_open()) {
        file << ts.maThiSinh << "," 
             << ts.hoTen << "," 
             << ts.diemSo << "," 
             << ts.thoiGianLamBai << "\n";
        file.close();
        std::cout << " Da luu ket qua bai thi thanh cong!\n";
    } else {
        std::cerr << "Khong the tao hoac mo file " << filePath << "\n";
    }
}

// Hàm đếm số dòng trong file history
int countHistoryLines(const std::string& filePath) {
    std::ifstream file(filePath);
    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) count++;
    }
    return count;
}

//  BẢNG XẾP HẠNG 
ThiSinh* loadHistory(const std::string& filePath, int& count) {
    count = countHistoryLines(filePath);
    if (count == 0) return nullptr;

    ThiSinh* arr = new ThiSinh[count]; 
    std::ifstream file(filePath);
    
    for (int i = 0; i < count; i++) {
        std::string diemStr, thoiGianStr;
        // Đọc từng phần cách nhau bởi dấu phẩy
        std::getline(file, arr[i].maThiSinh, ',');
        std::getline(file, arr[i].hoTen, ',');
        std::getline(file, diemStr, ',');
        std::getline(file, thoiGianStr, '\n');
        
        arr[i].diemSo = std::stof(diemStr);
        arr[i].thoiGianLamBai = std::stoi(thoiGianStr);
        arr[i].dapAnDaChon = nullptr; // Lịch sử lưu trữ file không giữ mảng đáp án
    }
    file.close();
    return arr;
}

void displayLeaderboard(ThiSinh* arr, int count, int topN) {
    if (arr == nullptr || count == 0) {
        std::cout << "Chua co du lieu lich su!\n";
        return;
    }

    // Interchange Sort sắp xếp điểm giảm dần
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i].diemSo < arr[j].diemSo) {
                ThiSinh temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    std::cout << "\n BANG XEP HANG TOP " << topN << " ===\n";
    int limit = (count < topN) ? count : topN;
    for (int i = 0; i < limit; i++) {
        std::cout << i + 1 << ". Ma: " << arr[i].maThiSinh 
                  << " | Ten: " << arr[i].hoTen 
                  << " | Diem: " << arr[i].diemSo 
                  << " | Thoi gian: " << arr[i].thoiGianLamBai << " giay\n";
    }
}

void deleteHistory(ThiSinh*& arr) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
}

//CHẾ ĐỘ XEM LẠI
void reviewExam(const CauHoi* bank, int count, const ThiSinh& ts, bool onlyWrong) {
    std::cout << "\n=== CHE DO XEM LAI BAI THI ===\n";
    if (ts.dapAnDaChon == nullptr) {
        std::cout << "Khong tim thay lich su dap an!\n";
        return;
    }

    int saiCount = 0;
    int dungCount = 0; // Thêm biến đếm số câu đúng

    for (int i = 0; i < count; i++) {
        bool isCorrect = (ts.dapAnDaChon[i] == bank[i].dapAnDung);
        
        if (isCorrect) dungCount++; // Tăng biến đếm nếu đúng
        else saiCount++;

        // Chỉ xem các câu làm sai
        if (onlyWrong && isCorrect) {
            continue; 
        }

        std::cout << "Cau " << i + 1 << ": " << bank[i].noiDung << "\n";
        char userAns = ts.dapAnDaChon[i];
        std::cout << " - Dap an cua ban: " << (userAns == ' ' ? "Bo qua (Skip)" : std::string(1, userAns)) << "\n";
        std::cout << " - Dap an dung: " << bank[i].dapAnDung << "\n";
        std::cout << " -> KET QUA: " << (isCorrect ? "DUNG" : "SAI") << "\n\n";
    }

    if (onlyWrong && saiCount == 0) {
        std::cout << "Tuyet voi! Ban khong lam sai cau nao.\n\n";
    }

    // THỐNG KÊ HIỆU SUẤT 
    if (!onlyWrong) { // Chỉ in thống kê khi xem toàn bộ bài
        std::cout << "=== THONG KE HIEU SUAT ===\n";
        
        // Tính tỷ lệ % 
        float tiLeDung = ((float)dungCount / count) * 100;
        
        // Tính thời gian trung bình 
        float tgTrungBinh = (float)ts.thoiGianLamBai / count;

        std::cout << "- Ty le tra loi dung: " << tiLeDung << "%\n";
        std::cout << "- Thoi gian lam bai trung binh: " << tgTrungBinh << " giay/cau\n";
        std::cout << "==========================\n";
    }
}