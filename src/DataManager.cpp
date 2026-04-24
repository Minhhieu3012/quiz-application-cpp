#include "../include/DataManager.h"

// doc du lieu tu file 
CauHoi* loadQuestionBank(const std::string& filePath, int& count) {
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Loi: Khong the mo file " << filePath << std::endl;
		return nullptr;
	}

	file >> count;
	file.ignore();

	CauHoi* bank = new CauHoi[count];

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

void deleteQuestionBank(CauHoi*& bank) {
	if (bank != nullptr) {
		delete[] bank;
		bank = nullptr;
	}
}

CauHoi* filterQuestionsByDifficulty(CauHoi* bank, int totalCount, int difficultyLevel, int& filteredCount) {
	if (bank == nullptr || totalCount <= 0) {
		filteredCount = 0;
		return nullptr;
	}

	filteredCount = 0;
	for (int i = 0; i < totalCount; i++) {
		if (bank[i].doKho == difficultyLevel) {
			filteredCount++;
		}
	}

	if (filteredCount == 0) {
		return nullptr;
	}

	CauHoi* filteredBank = new CauHoi[filteredCount];
	
	int currentIndex = 0;
	for (int i = 0; i < totalCount; i++) {
		if (bank[i].doKho == difficultyLevel) {
			filteredBank[currentIndex] = bank[i];
			currentIndex++;
		}
	}
	return filteredBank;
}
