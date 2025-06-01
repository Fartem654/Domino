#include "CheckInput.h"

bool CheckInput::isInt() {
    bool Flag = false;
    if (cin.fail()) {
        cout << "¬веден недопустимый символ!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    return Flag;
}

bool CheckInput::isIntRange(int Val, int Min, int Max) {
    bool Flag = false;
    if (cin.fail()) {
        cout << "¬веден недопустимый символ!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Flag = true;
    }
    else if (Val<Min || Val > Max) {
        system("cls");
        cout << "„исло " << Val << " не попадает в диапазон от " << Min << " до " << Max << "!" << endl;
        Flag = true;
    }
    return Flag;
}

bool CheckInput::StrIsNumb(string Str) {
    bool Flag = false;

    for (char ch : Str) {
        if ((int)ch < 48 || (int)ch) continue;
    }
    return Flag;
}

bool CheckInput::StrIsBin(string Str) {
    for (char ch : Str)
        if (ch != '1' && ch != '0') {
            cout << "ƒвоичное число может содержать только '1' или '0'!" << endl;
            return true;
        }
    return false;
}