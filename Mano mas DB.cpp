#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>


using std::cout;
using std::cin;
using std::string;
using std::endl;

const int max_size = 10;

struct duomuo {
    string vard, pav;
    float vid = 0, gp, med, paz[max_size], egz;
    int num;
};

void insertionSort(float mas[], int n) {
    int i, j, elem;

    for (i = 1; i < n; i++) {
        elem = mas[i];
        j = i - 1;

        while (j >= 0 && mas[j] > elem) {
            mas[j + 1] = mas[j];
            j -= 1;
        }

        mas[j + 1] = elem;
    }
}

float mediana(float mas[], int n) {
    if (n % 2 == 0)
        return (mas[n / 2] + mas[n / 2 - 1]) / 2.0;
    else
        return (float)mas[n / 2];
}

int main()
{
    int k, l, stud, n;
    float paz;
    cout << "Iveskite studentu skaiciu\n";
    cin >> stud;
    duomuo* eil_mas = new duomuo[stud];
    for (int j = 0; j < stud; j++) {
        n = 0;
        cout << "Iveskite studento duomenis (vardas, pavarde):\n";
        cin >> eil_mas[j].vard >> eil_mas[j].pav;
        cout << "Iveskite 0, jeigu norite ivesti pazymius (ir 0, kai baigete ivedineti pazymius). 1 - jeigu norite, kad jie butu atsitiktinai generuojami.\n";
        cin >> l;
        if (l == 0) {
            cin >> eil_mas[j].egz;
            do {
                cin >> paz;
                if (paz == 0)
                    break;
                eil_mas[j].paz[n] = paz;
                eil_mas[j].vid = eil_mas[j].vid + paz;
                n++;
            } while (n < max_size);
            eil_mas[j].num = n;
        }
        else if (l == 1) {
            eil_mas[j].egz = (rand() % 10) + 5;
            eil_mas[j].num = (rand() % 10) + 1;
            for (int i = 0; i < eil_mas[j].num; i++) {
                eil_mas[j].paz[i] = (rand() % 10) + 1;
                eil_mas[j].vid = eil_mas[j].vid + eil_mas[j].paz[i];
            }
        }
        else {
            cout << "Jus ivedete neteisinga skaiciu";
        }
    }

    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu. 1 - jeigu norite skaiciuoti su mediana.";
    cin >> k;

    if (k == 0) {
        cout << "Vardas      " << "Pavarde       " << "Galutinis(vid.)" << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < stud; i++) {
            eil_mas[i].vid = eil_mas[i].vid / (float)eil_mas[i].num;
            eil_mas[i].gp = eil_mas[i].vid * 0.4 + eil_mas[i].egz * 0.6;
            cout << std::left << std::setw(12) << eil_mas[i].vard << std::left << std::setw(14) << eil_mas[i].pav;
            cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas[i].gp << endl;
        }
    }
    else if (k == 1) {
        cout << "Vardas      " << "Pavarde       " << "Galutinis(med.)" << endl;
        cout << "------------------------------------------------" << endl;
        for (int i = 0; i < stud; i++) {
            insertionSort(eil_mas[i].paz, eil_mas[i].num);
            eil_mas[i].med = mediana(eil_mas[i].paz, eil_mas[i].num);
            eil_mas[i].gp = eil_mas[i].med * 0.4 + eil_mas[i].egz * 0.6;
            cout << std::left << std::setw(12) << eil_mas[i].vard << std::left << std::setw(14) << eil_mas[i].pav;
            cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas[i].gp << endl;
        }
    }
    else {
        cout << "Jus ivedete neteisinga skaiciu, negalima apskaiciuoti GP";
    }
}
