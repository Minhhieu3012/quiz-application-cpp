#include "functions.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Ham nhap thong tin
void nhapThongTin(ThiSinh* ts) {
	cin.ignore(); // Xoa enter ton dong
	cout << "\n--- NHAP THONG TIN THI SINH ---\n";
	cout << "Nhap Ma Sv: ";
	cin.getline(ts->maSV, 20);
	cout << "Nhap Ho Ten: ";
	cin.getline(ts->hoTen, 50);
}

// 2. Ham hien thi trang thai cau hoi
void hienThiDashboard(char* dapAnThiSinh, int tongSoCau) {
	cout << "\n=== BANG TONG QUAN BAI THI ===\n";
	for (int i = 0; i < tongSoCau; i++) {
		cout << "Cau " << (i + 1) << ": ";
		if (dapAnThiSinh[i] == ' ') cout << "[ - ]\t";
		else cout << "[" << dapAnThiSinh[i] << "]\t";

		if ((i + 1) % 5 == 0) cout << endl;
	}
	cout << "\n==============================\n";
}

// 3. Ham doc file ( Dem so dong -> cap phat mang)
bool docCauHoiTuFile(const char* tenFile, CauHoi*& danhSachCauHoi, int& tongSoCau) {
	ifstream fileIn(tenFile);
	if (!fileIn.is_open()) {
		cout << "[Loi] Khong the mo file " << tenFile << " (Chua co file hoac sai ten):\n";
		return false;
	}

	int soDong = 0;
	char temp[255];
	// Dem so dong de cap phat mang
	while (fileIn.getline(temp, 255)) soDong++;

	// Moi cau co 6 dong: 1 cau hoi  + 4 dap an + 1 dap an dung
	tongSoCau = soDong / 6;

	// Cap phat mang dong cho danh sach cau hoi
	danhSachCauHoi = new CauHoi[tongSoCau];

	// Xoa co loi va quay lai dau file
	fileIn.clear();
	fileIn.seekg(0, ios::beg);

	for (int i = 0; i < tongSoCau; i++) {
		fileIn.getline(danhSachCauHoi[i].noiDung, 255);
		fileIn.getline(danhSachCauHoi[i].dapAnA, 100);
		fileIn.getline(danhSachCauHoi[i].dapAnB, 100);
		fileIn.getline(danhSachCauHoi[i].dapAnC, 100);
		fileIn.getline(danhSachCauHoi[i].dapAnD, 100);
		fileIn >> danhSachCauHoi[i].dapAnDung; 
		fileIn.ignore(); // Xoa enter sau ki tu dap an dung
	}

	fileIn.close();
	return true;
}
// 4. Ham xao tron de thi
void xaoTronDeThi(CauHoi* danhSach, int tongSoCau) {
	for (int i = 0; i < tongSoCau; i++) {
		int j = rand() % tongSoCau; // Chon random index j
		// Thuat toan doi cho (Swap)
		CauHoi temp = danhSach[i];
		danhSach[i] = danhSach[j];
		danhSach[j] = temp;
	}
}

// 5. Ham vong lap thi Chinh
void luongLamBaiThi(ThiSinh* ts, CauHoi* danhSachCauHoi, int tongSoCau, int thoiGianGioiHan) {
	// Cap phat mang dong luu dap an nguoi dung
	char* dapAnThiSinh = new char[tongSoCau];
	for (int i = 0; i < tongSoCau; i++) dapAnThiSinh[i] = ' ';

	int cauHienTai = 0;
	bool dangThi = true;

	// Lay moc thoi gian bat dau (Dem nguoc)
	time_t thoiGianBatDau = time(0);

	while (dangThi) {
		system("cls");

		time_t thoiGianHienTai = time(0);
		int thoiGianDaTroiQua = thoiGianHienTai - thoiGianBatDau;
		int thoiGianConLai = thoiGianGioiHan - thoiGianDaTroiQua;

        if (thoiGianConLai <= 0) {
			cout << "\n[!] HET GIO LAM BAI! HE THONG TU DONG NOP BAI.\n";
			system("pause");
			break;
		}

		cout << "Thi sinh: " << ts->hoTen << " | Thoi gian con lai: "
			<< thoiGianConLai / 60 << " phut " << thoiGianConLai % 60 << " giay\n";
		cout << "--------------------------------------------------\n";

        cout << "[Cau " << (cauHienTai + 1) << "/" << tongSoCau << "]\n";
		cout << danhSachCauHoi[cauHienTai].noiDung << "\n";
		cout << "A. " << danhSachCauHoi[cauHienTai].dapAnA << "\n";
		cout << "B. " << danhSachCauHoi[cauHienTai].dapAnB << "\n";
		cout << "C. " << danhSachCauHoi[cauHienTai].dapAnC << "\n";
		cout << "D. " << danhSachCauHoi[cauHienTai].dapAnD << "\n";

		if (dapAnThiSinh[cauHienTai] != ' ') {
			cout << "=> Dap an ban da chon: " << dapAnThiSinh[cauHienTai] << "\n";
		}
		else {
			cout << "=> Ban chua lam cau nay.\n";
		}

		cout << "\n--- MENU THAO TAC ---\n";
		cout << "1. Chon / Thay doi dap an\n";
		cout << "2. Cau tiep theo (Skip)\n";
		cout << "3. Quay lai cau truoc\n";
		cout << "4. Xem bang tong quan (Dashboard)\n";
		cout << "5. NOPBAI\n";
		cout << "Chon thao tac (1-5): ";

		int thaoTac;
		cin >> thaoTac;

        switch (thaoTac) {
		case 1: {
			cout << "Nhap dap an cua ban (A/B/C/D): ";
			char chon;
			cin >> chon;
			dapAnThiSinh[cauHienTai] = static_cast<char>(toupper(static_cast<unsigned char>(chon))); // Tu dong in hoa ki tu
			if (cauHienTai < tongSoCau - 1) cauHienTai++;
			break;
		}
		case 2:
			if (cauHienTai < tongSoCau - 1) cauHienTai++;
			else {
				cout << "Day la cau cuoi!\n"; system("pause");
			}
			break;
		case 3:
			if (cauHienTai > 0) cauHienTai--;
			else { cout << "Day la cau dau tien!\n"; system("pause"); }
			break;
		case 4: {
			hienThiDashboard(dapAnThiSinh, tongSoCau);
			cout << "Nhap so thu tu cau muon toi (Hoac nhap 0 de huy): ";
			int denCau;
			cin >> denCau;
			if (denCau > 0 && denCau <= tongSoCau) cauHienTai = denCau - 1;
			break;
		}
		case 5: {
			cout << "Ban xac nhan muon nop bai chua? (1: Co / 0: Khong): ";
			int xacNhan;
			cin >> xacNhan;
			if (xacNhan == 1) dangThi = false;
			break;
		}
		}
	}
	// Ket thuc bai thi, tinh gio lam bai
	ts->thoiGianLamBai = time(0) - thoiGianBatDau;

	// Cham diem va luu lich su vao file
	tinhDiemVaLuuLichSu(ts, danhSachCauHoi, dapAnThiSinh, tongSoCau);

	// Giai phong bo nho dap an
	delete[] dapAnThiSinh;
}
// Ham tinh diem va luu lich su vao file history.txt
void tinhDiemVaLuuLichSu(ThiSinh* ts, CauHoi* danhSachCauHoi, char* dapAnThiSinh, int tongSoCau) {
	int soCauDung = 0;

	// Doi chieu dap an thi sinh voi dap an dung
	for (int i = 0; i < tongSoCau; i++) {
		if (dapAnThiSinh[i] == danhSachCauHoi[i].dapAnDung) {
			soCauDung++;
		}
	}

	// Tinh diem tren thanh diem 10
	ts->diem = (soCauDung * 10) / tongSoCau;

	// Hien thi bang diem ra man hinh
	system("cls");
	cout << "========================================\n";
	cout << "          KET QUA BAI THI               \n";
	cout << "========================================\n";
	cout << "Thi sinh: " << ts->hoTen << " - " << ts->maSV << "\n";
	cout << "Thoi gian lam bai: " << ts->thoiGianLamBai / 60 << " phut " << ts->thoiGianLamBai % 60 << " giay\n";
	cout << "So cau tra loi dung: " << soCauDung << "/" << tongSoCau << "\n";
	cout << "Tong diem: " << ts->diem << " / 10\n";
	cout << "========================================\n";

	// Ghi du lieu vao file history.txt
	ofstream fileOut("history.txt", ios::app); // ghi noi tiep vao cuoi file
	if (fileOut.is_open()) {
		fileOut << ts->maSV << "," << ts->hoTen << "," << ts->diem << "," << ts->thoiGianLamBai << "\n";
		fileOut.close();
		cout << "[He thong] Da luu ket qua thi vao lich su.\n";
	}
	else {
		cout << "[Loi] Khong the mo file history.txt de ghi!\n";
	}
}