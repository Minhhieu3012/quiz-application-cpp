#include"../include/Randomizer.h"

void initRandomizer() {
	srand((unsigned int)time(NULL));
}

void shuffleQuestions(CauHoi* bank, int count) {
	if (bank == nullptr || count <= 1) {
		return;
	}
	for (int i = count - 1; i > 0; i--) {
		int j = rand() % (i + 1); // random 0 -> i

		// Hoan vi 
		CauHoi temp = bank[i];
		bank[i] = bank[j];
		bank[j] = temp;
	}
}

void shuffleAnswers(CauHoi& q) {
	int correctIndex = q.dapAnDung - 'A'; // A->0, B->1, C->2, D->3
	std::string correctString = q.dapAn[correctIndex]; 

	// xao tron
	for(int i = 3;i > 0;i--) { // D -> B
		int j = rand() % (i + 1);

		std::string temp = q.dapAn[i];
		q.dapAn[i] = q.dapAn[j];
		q.dapAn[j] = temp;
	}
	
	// cap nhat lai dap an dung 
	for (int i = 0; i < 4; i++) {
		if (q.dapAn[i] == correctString) {
			q.dapAnDung = 'A' + i; // cap nhat lai ky tu 
			break;
		}
	}
}