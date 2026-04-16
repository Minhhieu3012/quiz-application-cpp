#pragma once
#include<string>

struct cauHoi {
	std::string noiDung;
	std::string dapAn[4];
	char dapAnDung;
	int doKho;
};

struct thiSinh {
	std::string maThiSinh;
	std::string hoTen;

	char* dapAnDaChon;

	float diemSo; 
	int thoiGianLamBai; 
};