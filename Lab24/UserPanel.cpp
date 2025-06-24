#include "UserPanel.h"

// ContainerFilling

// PRIVATE

void  ContainerFilling::CountNumb(vector<int>& NumbDigit, int& NumbLoop, string Str) {
	string FirstSymbol = "";
	string SecondSymbol = "";

	FirstSymbol += Str[0];
	SecondSymbol += Str[1];

	if (FirstSymbol == SecondSymbol) NumbLoop++;

	NumbDigit[stoi(FirstSymbol)]++;
	NumbDigit[stoi(SecondSymbol)]++;
}

void  ContainerFilling::ReadString(string Str, vector<string>& DominoVectorStr) {
	string Formval = "";
	for (char ch : Str) {
		if (ch != ' ') {
			Formval += ch;
		}
		else {
			DominoVectorStr.push_back(Formval);
			Formval = "";
		}
	}
	if (Formval != "")
		DominoVectorStr.push_back(Formval);
}

// PUBLIC

vector<Domino*> ContainerFilling::ConsInput_(vector<int>& NumbDigits, int Len, int& NumbLoop, bool& AlreadyRule) {
	system("cls");
	string DominVal;
	vector<Domino*> DominoVector;
	cout << "Вводите числа вида XX, где 0<=X<=6. Например 00, 19, 66:" << endl;
	for (int i = 1; i <= Len; i++) {
		do {
			cout << "Введите " << i << "-ую из " << Len << "-и доминошку: ";
			cin >> DominVal;
		} while (!CheckInput().isDomino(DominVal));
		CountNumb(NumbDigits, NumbLoop, DominVal);

		if (AlreadyRule && DominoVector.size() > 0) {
			if (DominVal[0] != DominoVector.back()->getSecond_()) {
				AlreadyRule = false;
			}
		}
		Domino* Dom = new Domino(DominVal[0], DominVal[1]);
		DominoVector.push_back(Dom);
	}
	system("cls");

	return DominoVector;
}

vector<Domino*> ContainerFilling::RandInput_(vector<int>& NumbDigits, int Len, int& NumbLoop, bool& AlreadyRule) {
	system("cls");
	cout << "\033[33mГенерируются доминошки вида XX, 0<=X<=6.\033[0m" << endl;
	srand(time(0));

	vector<Domino*> DominoVector;
	string DominVal;

	for (int i = 1; i <= Len; i++) {
		DominVal = to_string(rand() % 7) + to_string(rand() % 7);
		CountNumb(NumbDigits, NumbLoop, DominVal);

		if (AlreadyRule && DominoVector.size() > 0) {
			if (DominVal[0] != DominoVector.back()->getSecond_()) {
				AlreadyRule = false;
			}
		}
		Domino* Dom = new Domino(DominVal[0], DominVal[1]);
		DominoVector.push_back(Dom);
	}

	return DominoVector;
}

vector<Domino*> ContainerFilling::FileInput_(int Len, vector<int>& NumbDigits, int& NumbLoop, bool& AlreadyRule, bool& ErrorFile, string FileName) {
	system("cls");
	cout << "\033[33mВсе элементы НЕ в формате домино будут пропущены! ( XX, 0<=X<=6)\033[0m" << endl;

	vector<Domino*> DominoVector;
	string DominVal;

	int Choise;

	bool Result = false;

	ifstream f(FileName);
	if (!f.is_open()) {
		cout << "Ошибка открыти файла!\nХотие выбрать другой способ заполнения?\n1 - Да\n2 - Нет\n";
		cin >> Choise;
		if (Choise == 1) {
			Result = true;
		}
		else {
			Result = false;
		}
		system("cls");
	}
	else {
		vector<string> DominoVectorStr;
		string Str, TempDom;
		bool Size = false;
		int i = 0;

		getline(f, Str);
		ReadString(Str, DominoVectorStr);
		while (i < DominoVectorStr.size() && !Size) {

			TempDom = DominoVectorStr[i];
			if (CheckInput().isDominoFile(TempDom)) {
				DominVal = TempDom.size() == 2 ? TempDom : "0" + TempDom;
				CountNumb(NumbDigits, NumbLoop, DominVal);

				if (AlreadyRule && DominoVector.size() > 0) {
					if (DominVal[0] != DominoVector.back()->getSecond_()) {
						AlreadyRule = false;
					}
				}
				Domino* Dom = new Domino(DominVal[0], DominVal[1]);
				DominoVector.push_back(Dom);

				if (DominoVector.size() == Len) {
					Size = true;
				}
			}
			i++;
		}
		if (DominoVector.size() < Len) {
			cout << "В файле недостаточно элементов для набора из " << Len << " доминошек. (" << DominoVector.size() << "/" << Len << ")\nВыберите другой способ заполнения." << endl;;
			cout << "Введите любой символ чтобы продолжить: ";
			string ChoiseStr;
			cin >> ChoiseStr;
			Result = true;
			NumbLoop = 0;
			vector<int> NumbDigits0(7, 0);
			NumbDigits = NumbDigits0;
		}
		else {
			Result = false;
		}
	}
	ErrorFile = Result;
	system("cls");
	return DominoVector;
}
// UserPanel

// PRIVATE

void UserPanel::ShowDomVec(vector<Domino*> DomVec) {
	for (int i = 0; i < DomVec.size(); i++) {
		DomVec[i]->PrintDomino_();
	}
}

// PUBLIC

vector<Domino*> UserPanel::InputDomino_(int Len, vector<int>& NumbDigits, int& NumbLoop, bool& AlreadyRule, string FileName) {
	int Choise;
	bool ErrorFile = false;
	vector<Domino*> DominoVector;

	do {
		if (!ErrorFile) {
			do {
				cout << "Выберите способ ввода набора домино из " << Len << " элементов:" << endl;
				cout << "1) Сгенерировать набор случайно.\n2) Ввести набор в консоль.\n3) Ввести набор из файла '" << FileName << "'." << endl;;
				cin >> Choise;
			} while (CheckInput().isIntRange(Choise, 1, 3));
		}
		else {
			do {
				cout << "Выберите способ ввода набора домино из " << Len << " элементов:" << endl;
				cout << "1) Сгенерировать набор случайно.\n2) Ввести набор в консоль.\n0) Выход." << endl;
				cin >> Choise;
			} while (CheckInput().isIntRange(Choise, 0, 2));
		}

		ErrorFile = false;

		switch (Choise)
		{
		case 1:
			DominoVector = RandInput_(NumbDigits, Len, NumbLoop, AlreadyRule);
			break;
		case 2:
			DominoVector = ConsInput_(NumbDigits, Len, NumbLoop, AlreadyRule);
			break;
		case 3:
			DominoVector = FileInput_(Len, NumbDigits, NumbLoop, AlreadyRule, ErrorFile, FileName);
			break;
		default:
			cout << "Завершение программы." << endl;
			ErrorFile = false;
		}
	} while (ErrorFile);
	return DominoVector;
}

void UserPanel::Programma(string FileName) {
	string DominVal;
	vector<Domino*> DominoVector;
	vector<int> NumbDigits(7, 0);
	int NumbLoop = 0, Len;
	bool AlreadyRule = true;

	do {
		cout << "Введите количество костей домино: ";
		cin >> Len;
	} while (CheckInput().isIntMin(Len, 1));

	system("cls");

	DominoVector = InputDomino_(Len, NumbDigits, NumbLoop, AlreadyRule, FileName);

	if (DominoVector.size() > 0) {
		cout << "Исходный список доминошек:" << endl;
		ShowDomVec(DominoVector); cout << endl;

		if (AlreadyRule) {
			cout << "\033[32mВходные домино уже разложены по правилу.\033[0m" << endl;
		}
		else {

			DominoesRow* Head = nullptr, * Temp;

			Head = Head->FormDominoesRow(DominoVector, NumbDigits, NumbLoop, Head);
			Temp = Head;

			if (Head) {
				cout << "\033[32mСписок домино, удовлетворяющий правилам:\033[0m" << endl;
				while (Temp) {
					Temp->getDominoValue()->PrintDomino_();
					Temp = Temp->getNext();
				}
				cout << endl;
				Head->DeleteRow_(Head);
			}
			else {
				cout << "\033[31mНекорректные входные данные.\033[0m" << endl;
			}
		}

		for (auto i : DominoVector) {
			delete i;
		}
	}
}

void UserPanel::UserPanelLoop_(string FileName) {
	bool MenuLoop;
	int Choise;
	do {
		system("cls");
		MenuLoop = false;
		Programma(FileName);
		do {
			cout << "\nВыполнить еще раз - 1\nВыход - 0" << endl;
			cin >> Choise;
		} while (CheckInput().isIntRange(Choise, 0, 1));
		if (Choise == 1) MenuLoop = true;

	} while (MenuLoop);
}