#include "CheckInput.h"

//CheckInput::

bool CheckInput::isInt() {
    bool Flag = false;
    if (cin.fail()) {
        cout << "\033[31m������ ������������ ������!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    return Flag;
}

bool CheckInput::isIntMin(int Val, int Min) {
    bool Flag = false;
    if (cin.fail()) {
        cout << "\033[31m������ ������������ ������!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    else if (Val<Min) {
        system("cls");
        cout << "\033[31m��������� ����� �� ����� ���� ������ ��� " << Min << "!\033[0m" << endl;
        Flag = true;
    }
    return Flag;
}

bool CheckInput::isIntMax(int Val, int Max) {
    bool Flag = false;
    if (cin.fail()) {
        cout << "\033[31m������ ������������ ������!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    else if (Val > Max) {
        system("cls");
        cout << "\033[31m��������� ����� �� ����� ���� ������ ��� " << Max << "!\033[0m" << endl;
        Flag = true;
    }
    return Flag;
}

bool CheckInput::isIntRange(int Val, int Min, int Max) {
    bool Flag = false;
    if (cin.fail()) {
        system("cls");
        cout << "\033[31m������ ������������ ������!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    else if (Val<Min || Val > Max) {
        system("cls");
        cout << "\033[31m����� " << Val << " �� �������� � �������� �� " << Min << " �� " << Max << "!\033[0m" << endl;
        Flag = true;
    }
    return Flag;
}

bool CheckInput::StrIsBin(string Str) {
    for (char ch : Str)
        if (ch != '1' && ch != '0') {
            cout << "\033[31m�������� ����� ����� ��������� ������ '1' ��� '0'!\033[0m" << endl;
            return true;
        }
    return false;
}

bool CheckInput::isDomino(string Str) {
    bool Flag = false;
    if (Str.size() == 2 and (Str[0] >= '0' and Str[0] <= '6') and (Str[1] >= '0' and Str[1] <= '6'))
        Flag = true;
    else {
        cout << "\033[31m��������� ������ �������� ������ �� ���� ���� �� 0 �� 6!  ( XX, 0<=X<=6)\033[0m" << endl;
    }
    return Flag;
}

bool CheckInput::isDominoFile(string Str) {
    bool Flag = false;
    if(Str.size() == 2)
        if (Str[0] >= '0' and Str[0] <= '6' and Str[1] >= '0' and Str[1] <= '6')
            Flag = true;
    if (Str.size() == 1)
        if (Str[0] >= '0' and Str[0] <= '6')
            Flag = true;
    return Flag;
}