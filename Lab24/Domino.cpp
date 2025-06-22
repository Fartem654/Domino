#include "Domino.h"

void ShowDomVec(vector<Domino*> DomVec) {
	for (int i = 0; i < DomVec.size(); i++) {
		DomVec[i]->PrintDomino_();
	}
}

// PRIVATE

void DominoesRow::QuickSortDominoFirst_(vector <Domino*>& Dominoes, int LeftBorder, int RightBorder) {
	int SupportElement, LeftPointer = LeftBorder, RightPointer = RightBorder;
	Domino* Temp;

	SupportElement = Dominoes[(LeftBorder + RightBorder) / 2]->getFirst_() - '0';

	do {
		while (Dominoes[LeftPointer]->getFirst_() - '0' < SupportElement)
			LeftPointer++;
		while (Dominoes[RightPointer]->getFirst_() - '0' > SupportElement)
			RightPointer--;

		if (LeftPointer <= RightPointer) {
			Temp = Dominoes[LeftPointer];
			Dominoes[LeftPointer] = Dominoes[RightPointer];
			Dominoes[RightPointer] = Temp;
			LeftPointer++;
			RightPointer--;
		}
	} while (LeftPointer < RightPointer);

	if (LeftBorder < RightPointer) QuickSortDominoFirst_(Dominoes, LeftBorder, RightPointer);
	if (LeftPointer < RightBorder) QuickSortDominoFirst_(Dominoes, LeftPointer, RightBorder);
}

void DominoesRow::QuickSortDominoSecond_(vector <Domino*>& Dominoes, int LeftBorder, int RightBorder) {
	int SupportElement, LeftPointer = LeftBorder, RightPointer = RightBorder;
	Domino* Temp;

	SupportElement = Dominoes[(LeftBorder + RightBorder) / 2]->getSecond_() - '0';

	do {
		while (Dominoes[LeftPointer]->getSecond_() - '0' < SupportElement)
			LeftPointer++;
		while (Dominoes[RightPointer]->getSecond_() - '0' > SupportElement)
			RightPointer--;

		if (LeftPointer <= RightPointer) {
			Temp = Dominoes[LeftPointer];
			Dominoes[LeftPointer] = Dominoes[RightPointer];
			Dominoes[RightPointer] = Temp;
			LeftPointer++;
			RightPointer--;
		}
	} while (LeftPointer < RightPointer);

	if (LeftBorder < RightPointer) QuickSortDominoSecond_(Dominoes, LeftBorder, RightPointer);
	if (LeftPointer < RightBorder) QuickSortDominoSecond_(Dominoes, LeftPointer, RightBorder);
}

void DominoesRow::SearchInterval_(vector <Domino*>& Dominoes, int StartBorder, const vector <int>& NumbDigits) {
	if (Dominoes.size() > 1) {
		int LeftPointer = StartBorder, RightPointer = StartBorder, j;
		bool Flag;
		for (int i = 0; i < 7; i++)
			if (Dominoes[LeftPointer]->getFirst_() - '0' == i) {
				j = LeftPointer;
				Flag = true;
				while(j < Dominoes.size() - 1 && Flag){
					if (Dominoes[j + 1]->getFirst_() - '0' == i)
						RightPointer++;
					else if (Dominoes[j + 1]->getFirst_() - '0' != i) {
						if (LeftPointer != RightPointer) QuickSortDominoSecond_(Dominoes, LeftPointer, RightPointer);
						RightPointer += 1;
						LeftPointer = RightPointer;
						Flag = false;
					}
					j++;
				}
			}
	}

}

void DominoesRow::AheadLoop_(vector <Domino*>& Dominoes, const int& NumbLoop) {
	if (NumbLoop && NumbLoop != Dominoes.size()) {
		int LeftPointer = 0, RightPointer = Dominoes.size() - 1;
		Domino* Temp;

		while (LeftPointer < NumbLoop) {

			while (Dominoes[LeftPointer]->getIsLoop_() && LeftPointer < Dominoes.size() - 1) 
				LeftPointer++;
			while (!Dominoes[RightPointer]->getIsLoop_() && LeftPointer < NumbLoop && RightPointer >= 0)
				RightPointer--;

			if (LeftPointer < RightPointer && !Dominoes[LeftPointer]->getIsLoop_() && Dominoes[RightPointer]->getIsLoop_()) {
				Temp = Dominoes[LeftPointer];
				Dominoes[LeftPointer] = Dominoes[RightPointer];
				Dominoes[RightPointer] = Temp;
				LeftPointer++;
				RightPointer--;
			}
		}
		QuickSortDominoFirst_(Dominoes, 0, LeftPointer - 1);
		QuickSortDominoFirst_(Dominoes, LeftPointer, Dominoes.size() - 1);
	}
}

void DominoesRow::SortDominoVector_(vector <Domino*>& Dominoes, const int& NumbLoop, const vector <int>& NumbDigits) {
	QuickSortDominoFirst_(Dominoes, 0, Dominoes.size() - 1);
	SearchInterval_(Dominoes, 0, NumbDigits);
	if (NumbLoop && NumbLoop != Dominoes.size()) {
		AheadLoop_(Dominoes, NumbLoop);
		SearchInterval_(Dominoes, NumbLoop, NumbDigits);
	}
	ShowDomVec(Dominoes); cout << endl;
}

bool DominoesRow::isNoMoreThanTwoOdd_(const vector<int>& NumbDigits) {
	int Count = 0;
	bool Flag = true;
	for (int i = 0; i < 7; i++)
		if (NumbDigits[i] % 2 != 0)
			Count++;

	if (Count > 2)
		Flag = false;

	return Flag;
}

bool  DominoesRow::isConnect_(const vector<Domino*> Dominoes, const vector<int>& NumbDigits) {
	bool Flag = true;

	vector<bool> Visited(7, false);
	int Start = -1;

	int i = 0;
	while(i < 7 && Start == -1) {
		if (NumbDigits[i] > 0) {
			Start = i;
		}
		i++;
	}

	if (Start != -1) {

		Visited[Start] = true;

		bool Changed;
		do {
			Changed = false;
			for (Domino* Domin : Dominoes) {
				int First = Domin->getFirst_() - '0';
				int Second = Domin->getSecond_() - '0';

				if (Visited[First] && !Visited[Second] && NumbDigits[Second] > 0) {
					Visited[Second] = true;
					Changed = true;
				}
				else if (Visited[Second] && !Visited[First] && NumbDigits[First] > 0) {
					Visited[First] = true;
					Changed = true;
				}
			}
		} while (Changed);

		for (int i = 0; i < 7; i++) {
			if (NumbDigits[i] > 0 && !Visited[i])
				Flag = false;
		}
	}
	else {
		cout << "ПУСТО!" << endl;
		Flag = false;
	}

	return Flag;
}

char DominoesRow::FindStartDomino_(const vector<Domino*> Dominoes, const vector<int>& NumbDigits) {
	char StartDomino = Dominoes[0]->getFirst_();
	int i = 0;
	bool Flag = true;

	while (i < 7 && Flag) {
		if (NumbDigits[i] % 2 != 0) {
			StartDomino = '0' + i;
			Flag = false;
		}
		i++;
	}

	return StartDomino;
}



void DominoesRow::ReplaceVertexDominoes_(DominoesRow* TempHead, DominoesRow* Temp) {
	if (TempHead->getDominoValue()->getSecond_() != Temp->getDominoValue()->getFirst_()) {
		Temp->getDominoValue()->ReplaceValue();
	}
	if (TempHead->getDominoValue()->getSecond_() != Temp->getDominoValue()->getFirst_()) {
		TempHead->getDominoValue()->ReplaceValue();
	}
}

void DominoesRow::DeleteRow_(DominoesRow* Object) {
	if (Object) {
		DeleteRow_(Object->Next);
		delete Object;
	}
}

// PUBLIC

DominoesRow* DominoesRow::FormDominoesRow(vector<Domino*> Dominoes, const vector<int>& NumbDigits, const int& NumbLoop, DominoesRow* Head) {
	char StartDom = Dominoes[0]->getFirst_();
	if(Dominoes.size() == 1){
		Head = new DominoesRow(Dominoes[0]);
	}
	else if (isNoMoreThanTwoOdd_(NumbDigits) && isConnect_(Dominoes, NumbDigits)) {
		vector<bool> UsedDef(Dominoes.size(), false), Used = UsedDef;

		char CurDomino = FindStartDomino_(Dominoes, NumbDigits);
		int UsedDominoes = 0;
		int MovementMultiplier = 0; 

		bool Flag;

		DominoesRow* TempHead = Head;
		Domino* TempDomino;

		SortDominoVector_(Dominoes, NumbLoop, NumbDigits);

		while (UsedDominoes < Dominoes.size()) {
			int i = 0;
			while (i < Dominoes.size()) {
				if (!Used[i]) {
					TempDomino = Dominoes[i];
					if (TempDomino->getFirst_() == CurDomino || TempDomino->getSecond_() == CurDomino) {
						if (!Head) {
							Head = new DominoesRow(TempDomino);
							TempHead = Head;
							Used[i] = true;
							UsedDominoes++;
						}
						else {
							DominoesRow* Temp = new DominoesRow(TempDomino);
							
							ReplaceVertexDominoes_(TempHead, Temp);

							TempHead->setNext(Temp);
							Temp->setPrev(TempHead);
							TempHead = Temp;

							Used[i] = true;
							UsedDominoes++;
						}

						if (TempDomino->getFirst_() == CurDomino)
							CurDomino = TempDomino->getSecond_();
						else
							CurDomino = TempDomino->getFirst_();

						break;
					}
				}
				i++;
			}

			if (i == Dominoes.size() && MovementMultiplier + 1 < Dominoes.size()) {
				DeleteRow_(Head);
				Head = nullptr;
				UsedDominoes = 0;

				Domino* TempEnd = Dominoes[Dominoes.size() - 1 - MovementMultiplier];
				Dominoes[Dominoes.size() - 1 - MovementMultiplier] = Dominoes[Dominoes.size() - 2 - MovementMultiplier];
				Dominoes[Dominoes.size() - 2 - MovementMultiplier] = TempEnd;

				CurDomino = FindStartDomino_(Dominoes, NumbDigits);
				MovementMultiplier++;
				Used = UsedDef;
			}
			if (MovementMultiplier + 1 == Dominoes.size())
				MovementMultiplier = 0;

		}
	}
	else {
		cout << "Неверные входные данные." << endl;
		Head = nullptr;
	}

	return Head;
}