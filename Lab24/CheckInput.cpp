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

bool CheckInput::isIntRange(int Val, int Min, int Max) {
    bool Flag = false;
    if (cin.fail()) {
        cout << "\033[31m������ ������������ ������!\033[0m" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    else if (Val<Min || Val > Max) {
        system("cls");
        cout << "����� " << Val << " �� �������� � �������� �� " << Min << " �� " << Max << "!" << endl;
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
        cout << "\033[31m��������� ������ �������� ������ �� ���� ���� �� 0 �� 6!\033[0m" << endl;

    }
    return Flag;
}
