#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int luaChon;
    bool dangChay = true;

    // Khoi tao hat giong random cho ham tron de
    srand((unsigned)time(NULL));

    while (dangChay) {
        system("cls"); // Xoa man hinh

        cout << "========================================\n";
        cout << "       UNG DUNG THI TRAC NGHIEM         \n";
        cout << "========================================\n";
        cout << "1. Bat dau thi\n";
        cout << "2. Xem bang xep hang (Top 5) [Dang xay dung]\n";
        cout << "3/ Xem lich su thi [Dang xay dung]\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "========================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: {
            ThiSinh ts;
            ts.diem = 0;
            ts.thoiGianLamBai = 0;

            nhapThongTin(&ts);

            int doKho;
            cout << "\nChon muc do thi(1. De | 2. Trung binh | 3. Kho) : ";
            cin >> doKho;

            // --- KET NOI FILE DATA THUC TE ---
            int tongSoCau = 0;
            CauHoi* danhSachCauHoi = nullptr;

            cout << "\n[He thong] Dang tai du lieu tu ngan hang cau hoi...\n";
            // Doc file QuestionBank.txt
            if (!docCauHoiTuFile("QuestionBank.txt", danhSachCauHoi, tongSoCau)) {
                system("pause");
                break; // Loi file thi vang ra menu chinh
            }

            cout << "[He thong] Load thanh cong " << tongSoCau << " cau hoi!\n";

            // Xao tron de thi
            xaoTronDeThi(danhSachCauHoi, tongSoCau);
            cout << "[He thong] De thi da duoc xao tron ngau nhien!\n";
            system("pause");

            int thoiGianGioiHan = 15 * 60; // Gioi han 15 phut (900 giay)

            // --- BAT DAU VAO PHONG THI ---
            luongLamBaiThi(&ts, danhSachCauHoi, tongSoCau, thoiGianGioiHan);

            // Ket qua sau khi nhan Nop Bai

            system("pause");

            // Giai phong bo nho Mang dong Cau Hoi ( Bat buoc)
            delete[] danhSachCauHoi;
            break;
        }
        case 2:
        case 3:
            cout << "\n[Info] Chuc nang nay do Thanh vien khac phu trach.\n";
            system("pause");
            break;
        case 0:
            dangChay = false;
            cout << "\nCam on ban da su dung ung dung!\n";
            break;
        default:
            cout << "\nLua chon khong hop le!\n";
            system("pause");
        }
    }
    return 0;
}