#pragma once
#include<string>

struct CauHoi {
	std::string noiDung;
	std::string dapAn[4];
	char dapAnDung;
	int doKho; // 1 - De, 2 - TB. 3 - Kho
};

struct ThiSinh {
	std::string maThiSinh;
	std::string hoTen;

	char* dapAnDaChon;

	float diemSo; 
	int thoiGianLamBai; // tinh bang giay 
};