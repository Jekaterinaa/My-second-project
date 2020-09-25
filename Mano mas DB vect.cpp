// Mano mas DB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

const int max_size = 10;

struct duomuo {
    string vard, pav;
    vector<int> paz;
    int num, nd, egz;
    float vid = 0, gp, med;
};

float mediana(vector<int> v) {
    if (v.size() % 2 == 0)
        return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
    else
        return (float)v[v.size() / 2];
}

int main()
{
    duomuo eil_mas[5];
    int k, paz, l;
    cout << "Iveskite 0, jeigu norite ivesti pazymius (ir 0, kai baigete ivedineti pazymius). 1 - jeigu norite, kad jie butu atsitiktinai generuojami.\n";
    cin >> l;
    for (int j = 0; j < 5; j++) {
        cout << "Iveskite studento duomenis (vardas, pavarde):\n";
        cin >> eil_mas[j].vard >> eil_mas[j].pav;
        if (l == 0) {
            cin >> eil_mas[j].egz;
            do {
                cin >> paz;
                if (paz == 0)
                    break;
                eil_mas[j].paz.push_back(paz);
                eil_mas[j].vid = eil_mas[j].vid + (float)paz;
                eil_mas[j].num++;
            } while (eil_mas[j].num < max_size);
        }
        else if (l == 1) {
            eil_mas[j].egz = (rand() % 10) + 5;
            eil_mas[j].num = (rand() % 10) + 1;
            for (int i = 0; i < eil_mas[j].num; i++) {
                paz = (rand() % 10) + 1;
                eil_mas[j].paz.push_back(paz);
                eil_mas[j].vid = eil_mas[j].vid + (float)paz;
            }
        }
        else {
            cout << "Jus ivedete neteisinga skaiciu";
        }
    }
    
    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu. 1 - jeigu norite skaiciuoti su mediana." << endl;
    cin >> k;

    if (k == 0) {
        cout << "Vardas      " << "Pavarde       " << "Galutinis(vid.)" << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < 5; i++) {
            eil_mas[i].vid = eil_mas[i].vid / (float)eil_mas[i].num;
            eil_mas[i].gp = eil_mas[i].vid * 0.4 + eil_mas[i].egz * 0.6;
            cout << std::left << std::setw(12) << eil_mas[i].vard << std::left << std::setw(14) << eil_mas[i].pav;
            cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas[i].gp << endl;
        }
    }
    else if (k == 1) {
        cout << "Vardas      " << "Pavarde       " << "Galutinis(med.)" << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < 5; i++) {
            sort(eil_mas[i].paz.begin(), eil_mas[i].paz.end());
            eil_mas[i].med = mediana(eil_mas[i].paz);
            eil_mas[i].gp = eil_mas[i].med * 0.4 + eil_mas[i].egz * 0.6;
            cout << std::left << std::setw(12) << eil_mas[i].vard << std::left << std::setw(14) << eil_mas[i].pav;
            cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas[i].gp << endl;
        }
    }
    else
        cout << "Jus ivedete neteisinga skaiciu, negalima apskaiciuoti GP";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
