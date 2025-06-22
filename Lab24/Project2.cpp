#include "CheckInput.h"
#include "Domino.h"

void CountNumb(vector<int>& vec, int& NumbLoop, string str) {
    string st1 = "";
    string st2 = "";

    st1 += str[0];
    st2 += str[1];

    if (st1 == st2) NumbLoop++;

    vec[stoi(st1)]++;
    vec[stoi(st2)]++;
}

void Coutvec(vector<int> NumbDigits) {
    for (int i = 0; i < 7; i++) {
        cout << i << ": " << NumbDigits[i] << endl;
    }
}

void ShowDomVec1(vector<Domino*> DomVec) {
    for (int i = 0; i < DomVec.size(); i++) {
        DomVec[i]->PrintDomino_();
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
 
    //Для заданного подмножества набора костей домино определить, можно ли их
    //выложить в ряд, не нарушая правил.Если можно, то представить один любой
    //вариант такого разложения.Например, для входных данных 31, 00, 13,
    //получаем ответ : некорректные входные данные; для входных данных 02, 04,
    //42 ответ: можно, 04, 42, 20. Использовать двухсвязный список.

    vector<int> NumbDigits(7, 0);// количество цифр от 0 до 6 в заданном наборе домино // 24 02 04 00 // 24 02 04 00 44 22 // 21 21 14 13 11//12 22 22 22 22 22//20:  01 12 23 34 45 60 06 66 62 25 01 12 23 34 45 60 06 66 62 25 01 12 23 34 45 60 06 66 62 25 01 12 23 34 45 60 06 66 62 25
    int N;
    do {
        cout << "Введите количество костей домино: ";
        cin >> N;
    } while (CheckInput().isInt());
   

    string DominVal;
    int NumbLoop = 0;
    vector<Domino*> DominoVector;
    for (int i = 1; i <= N; i++) {
        do {
            cout << "Введите " << i << "-ую доминошку: ";
            cin >> DominVal;
        } while (!CheckInput().isDomino(DominVal));
        CountNumb(NumbDigits, NumbLoop, DominVal);
        Domino* Dom = new Domino(DominVal[0], DominVal[1]);
        DominoVector.push_back(Dom);
    }

    Coutvec(NumbDigits);
    ShowDomVec1(DominoVector);

    DominoesRow* Head = nullptr,* Temp;

    Head = Head->FormDominoesRow(DominoVector, NumbDigits, NumbLoop, Head);
    Temp = Head;

    while (Temp) {
        Temp->getDominoValue()->PrintDomino_();
        Temp = Temp->getNext();
    }

}
