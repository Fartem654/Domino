#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Domino {
private:
	char First;
	char Second;
	bool IsLoop = First == Second;
	 
public:

	Domino(char Fir, char Sec) : First(Fir), Second(Sec) {}
	
	char getFirst_() const { return First; }
	char getSecond_() const { return Second; }
	bool getIsLoop_() const { return IsLoop;  }

	void PrintDomino_() const {
		cout << First << Second << " ";
	}

	void ReplaceValue() {
		char Temp = First;
		First = Second;
		Second = Temp;
	}

};

class DominoesRow {
private:
	Domino* DominoValue;
	DominoesRow* Prev;
	DominoesRow* Next;

	/// Сортирует список доминошек по первой цифре в порядке возрастания
	void QuickSortDominoFirst_(vector <Domino*>& Dominoes, int LeftBorder, int RightBorder);

	//Сортирует список доминошек по второй цифре в порядке возрастания
	void QuickSortDominoSecond_(vector <Domino*>& Dominoes, int LeftBorder, int RightBorder);

	// Ищет промежутки по первой цифре доминошек в отсортированном векторе, для сортировки по второй цифре
	void SearchInterval_(vector <Domino*>& Dominoes, int StartBorder, const vector <int>& NumbDigits);

	//Выносит все петли вперед списка
	void AheadLoop_(vector <Domino*>& Dominoes, const int& NumbLoop);

	/// Вынос вперед домино-петель,
	/// Cортировка по возрастанию домино по первой цифре
	/// Сортировка по возрастанию домино по второй цифре с фиксированноый первой
	void SortDominoVector_(vector <Domino*>& Dominoes, const int& NumbLoop, const vector <int>& NumbDigits);

	// Проверка: не более чем 2 цифры встречаются нечетное количество раз
	// (Не более двух вершин с нечетной степенью)
	bool isNoMoreThanTwoOdd_(const vector<int>& NumbDigits);

	// Проверка на связность цифр доминошек (вершин графа)
	bool isConnect_(const vector<Domino*> Dominoes, const vector<int>& NumbDigits);

	// Нахождение цифры с нечетной степенью
	char FindStartDomino_(const vector<Domino*> Dominoes, const vector<int>& NumbDigits);

	/// Меняет вершины двух домино, что бы значения на сопряженных концах были одинаковыми 
	void ReplaceVertexDominoes_(DominoesRow* TempHead, DominoesRow* Temp);

	// Удадяет все значения списка домино
	void DeleteRow_(DominoesRow* Object);

	typedef DominoesRow* PDom;
	
public:

	DominoesRow(Domino* Dom) : DominoValue(Dom), Prev(nullptr), Next(nullptr) {}

	Domino* getDominoValue() const { return DominoValue; }
	DominoesRow* getNext() const { return Next; }

	void setPrev(DominoesRow* NewPrew) { Prev = NewPrew; }
	void setNext(DominoesRow* NewNext) { Next = NewNext; }

	// Формирование списка удовлетворяющего условию домино, если это возможно
	DominoesRow* FormDominoesRow(vector<Domino*> Dominoes, const vector<int>& NumbDigits, const int& NumbLoop, DominoesRow* Head);

};
