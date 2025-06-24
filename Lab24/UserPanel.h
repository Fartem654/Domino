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

	//Подсчет количества встречающихся цифр
	void CountNumb(vector<int>& NumbDigit, int& NumbLoop, string Str);

	//Преобразование строки в вектор
	void ReadString(string Str, vector<string>& DominoVectorStr);

public:

	// Считывание доминоешк с консоли, возвращает вектор с объектами класса Domino
	vector<Domino*> ConsInput_(vector<int>& NumbDigits, int Len, int& NumbLoop, bool& AlreadyRule);

	// Генерация случайных доминошек, возвращает вектор с объектами класса Domino
	vector<Domino*> RandInput_(vector<int>& NumbDigits, int Len, int& NumbLoop, bool& AlreadyRule);

	// Считывание доминоешк из файла, возвращает вектор с объектами класса Domino
	vector<Domino*> FileInput_(int Len, vector<int>& NumbDigits, int& NumbLoop, bool& AlreadyRule, bool& ErrorFile, string FileName);

};


class UserPanel:public ContainerFilling
{
private:
	enum VariantsChoise { Random = 1, Console, File };

	// Вывод вектора с объектами класса Domino
	void ShowDomVec(vector<Domino*> DomVec);

public:

	// Предоставление выбора ввода данных
	vector<Domino*> InputDomino_(int Len, vector<int>& NumbDigits, int& NumbLoop, bool& AlreadyRule, string FileName);

	// Основная программа
	void Programma(string FileName);

	// Зацикливание основной программы
	void UserPanelLoop_(string FileName);
};