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

	/// ��������� ������ ��������� �� ������ ����� � ������� �����������
	void QuickSortDominoFirst_(vector <Domino*>& Dominoes, int LeftBorder, int RightBorder);

	//��������� ������ ��������� �� ������ ����� � ������� �����������
	void QuickSortDominoSecond_(vector <Domino*>& Dominoes, int LeftBorder, int RightBorder);

	// ���� ���������� �� ������ ����� ��������� � ��������������� �������, ��� ���������� �� ������ �����
	void SearchInterval_(vector <Domino*>& Dominoes, int StartBorder, const vector <int>& NumbDigits);

	//������� ��� ����� ������ ������
	void AheadLoop_(vector <Domino*>& Dominoes, const int& NumbLoop);

	/// ����� ������ ������-������,
	/// C��������� �� ����������� ������ �� ������ �����
	/// ���������� �� ����������� ������ �� ������ ����� � �������������� ������
	void SortDominoVector_(vector <Domino*>& Dominoes, const int& NumbLoop, const vector <int>& NumbDigits);

	// ��������: �� ����� ��� 2 ����� ����������� �������� ���������� ���
	// (�� ����� ���� ������ � �������� ��������)
	bool isNoMoreThanTwoOdd_(const vector<int>& NumbDigits);

	// �������� �� ��������� ���� ��������� (������ �����)
	bool isConnect_(const vector<Domino*> Dominoes, const vector<int>& NumbDigits);

	// ���������� ����� � �������� ��������
	char FindStartDomino_(const vector<Domino*> Dominoes, const vector<int>& NumbDigits);

	/// ������ ������� ���� ������, ��� �� �������� �� ����������� ������ ���� ����������� 
	void ReplaceVertexDominoes_(DominoesRow* TempHead, DominoesRow* Temp);

	// ������� ��� �������� ������ ������
	void DeleteRow_(DominoesRow* Object);

	typedef DominoesRow* PDom;
	
public:

	DominoesRow(Domino* Dom) : DominoValue(Dom), Prev(nullptr), Next(nullptr) {}

	Domino* getDominoValue() const { return DominoValue; }
	DominoesRow* getNext() const { return Next; }

	void setPrev(DominoesRow* NewPrew) { Prev = NewPrew; }
	void setNext(DominoesRow* NewNext) { Next = NewNext; }

	// ������������ ������ ���������������� ������� ������, ���� ��� ��������
	DominoesRow* FormDominoesRow(vector<Domino*> Dominoes, const vector<int>& NumbDigits, const int& NumbLoop, DominoesRow* Head);

};
