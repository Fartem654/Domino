#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "CheckInput.h"
#include "Domino.h"

using namespace std;

class ContainerFilling {
private:

	//������� ���������� ������������� ����
	void CountNumb(vector<int>& NumbDigit, int& NumbLoop, string Str);

	//�������������� ������ � ������
	void ReadString(string Str, vector<string>& DominoVectorStr);

public:

	// ���������� ��������� � �������, ���������� ������ � ��������� ������ Domino
	vector<Domino*> ConsInput_(vector<int>& NumbDigits, int Len, int& NumbLoop, bool& AlreadyRule);

	// ��������� ��������� ���������, ���������� ������ � ��������� ������ Domino
	vector<Domino*> RandInput_(vector<int>& NumbDigits, int Len, int& NumbLoop, bool& AlreadyRule);

	// ���������� ��������� �� �����, ���������� ������ � ��������� ������ Domino
	vector<Domino*> FileInput_(int Len, vector<int>& NumbDigits, int& NumbLoop, bool& AlreadyRule, bool& ErrorFile, string FileName);

};


class UserPanel:public ContainerFilling
{
private:
	enum VariantsChoise { Random = 1, Console, File };

	// ����� ������� � ��������� ������ Domino
	void ShowDomVec(vector<Domino*> DomVec);

public:

	// �������������� ������ ����� ������
	vector<Domino*> InputDomino_(int Len, vector<int>& NumbDigits, int& NumbLoop, bool& AlreadyRule, string FileName);

	// �������� ���������
	void Programma(string FileName);

	// ������������ �������� ���������
	void UserPanelLoop_(string FileName);
};