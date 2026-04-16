#pragma once
#include<string>

struct CauHoi {
	std::string noiDung;
	std::string dapAn[4];
	char dapAnDung;
	int doKho;
};

struct ThiSinh {
	std::string maThiSinh;
	std::string hoTen;

	char* dapAnDaChon;

	float diemSo; 
	int thoiGianLamBai; 
};