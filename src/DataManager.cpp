#include "../include/DataManager.h"

cauHoi* loadQuestionBank(const std::string& filePath, int& count) {
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Loi: Khong the mo file " << filePath << std::endl;
		return nullptr;
	}

	file >> count;
	file.ignore();

	cauHoi* bank = new cauHoi[count];

	for (int i = 0; i < count; i++) {
		std::getline(file, bank[i].noiDung);
		for (int j = 0; j < 4; j++) {
			std::getline(file, bank[i].dapAn[j]);
		}
		file >> bank[i].dapAnDung;
		file >> bank[i].doKho;
		file.ignore();
	}

	file.close();
	return bank;
}

void deleteQuestionBank(cauHoi*& bank) {
	if (bank != nullptr) {
		delete[] bank;
		bank = nullptr;
	}
}