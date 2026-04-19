#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

void Docdapan(char dung[], int& n) {
	ifstream file("dapan.txt");

	if (!file.is_open()) {
		cout << "khong mo duoc file!\n";
		return;
	}

	n = 0;
	while (file >> dung[n]) {
		n++;
	}

	file.close();
}

batdauthi();

time_t startTime;

void batdauthi() {
	startTime = time(NULL);
}

int thoigiandalam() {
	time_t hientai = time(NULL);
	return difftime(hientai, startTime);
}

int hetgio(int gioihan) {
	int dalam = thoigiandalam();

	if (dalam >= gioihan) {
		return 1;
	}
	return 0;
}

int chamdiem(char dung[], char user[], int n) {
	int Socaudung = 0;

	for (int i = 0; i < n; i++) {
		if (dung[i] == user[i]) {
			Socaudung++;
		}
	}

	return Socaudung;
}

float Sophantramdung(int dung, int tong) {
	return(float)dung / tong * 100;
}

void Ketqua(int dung, int tong, int Thoigian) {
	cout << "\n===== Ket Qua =====\n";
	cout << "So cau dung: " << dung << endl;
	cout << "Tong diem: " << dung << endl;

	float Phantram = Sophantramdung(dung, tong);
	cout << "Ti le dung: " << Phantram << "%" << endl;

	cout << "Tong thoi gian: " << thoigiandalam << "phut" << endl;
}
