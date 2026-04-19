#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream> // Thu vien de doc/ghi file

using namespace std;

// Cau truc luu thong tin thi sinh
struct ThiSinh {
	char maSV[20];
	char hoTen[50];
	int diem;
	int thoiGianLamBai; // Tinh bang giay
};

// Cau truc luu cau hoi
struct CauHoi {
	char noiDung[255];
	char dapAnA[100];
	char dapAnB[100];
	char dapAnC[100];
	char dapAnD[100];
	char dapAnDung; // 'A', 'B', 'C', 'D'
};

// Khai bao cac ham
void nhapThongTin(ThiSinh* ts);
void hienThiDashboard(char* dapAnThiSinh, int tongSocau);
void luongLamBaiThi(ThiSinh* ts, CauHoi* danhSachCauHoi, int tongSoCau, int thoiGianGioiHan);

// Khai bao ham doc file va tron de
bool docCauHoiTuFile(const char* tenFile, CauHoi*& danhSachCauHoi, int& tongSoCau);
void xaoTronDeThi(CauHoi* danhSach, int tongSoCau);

// Khai bao ham cham diem va luu lich su
void tinhDiemVaLuuLichSu(ThiSinh* ts, CauHoi* danhSachCauHoi, char* dapAnThiSinh, int tongSoCau);

#endif