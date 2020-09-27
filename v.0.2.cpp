#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

const int max_size = 10;

struct duomuo {
    string vard, pav;
    vector<float> paz;
    int num = 0, nd, egz;
    float vid = 0, gp, med;
};

float mediana(vector<float> v) {
    if (v.size() % 2 == 0)
        return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
    else
        return (float)v[v.size() / 2];
}

void rusiuoti(duomuo sar[], int n) {
    duomuo temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sar[i].vard > sar[j].vard) {
                temp = sar[i];
                sar[i] = sar[j];
                sar[j] = temp;
            }
        }
    }
}

int main()
{
    duomuo eil_mas[10];
    int k, l, gp, kiek;
    float paz;

    cout << "Iveskite 0, jeigu norite nuskaityti duomenis is failo arba 1, jeigu norite ivesti juos.\n";
    cin >> k;

    if (k == 0) {
        std::ifstream duomenys;
        duomenys.open("kursiokai.txt");

        if (duomenys.fail()) {
            cout << "Nepavyko atidaryti failo" << endl;
            exit(1);
        }

        duomenys >> kiek;

        for (int i = 0; i < kiek && !duomenys.eof(); i++) {
            duomenys >> eil_mas[i].vard >> eil_mas[i].pav;
            for (int j = 0; j < 5; j++) {
                duomenys >> paz;
                eil_mas[i].paz.push_back(paz);
                eil_mas[i].vid = eil_mas[i].vid + paz;
                eil_mas[i].num++;
            }
            duomenys >> eil_mas[i].egz;
        }
    }
    else if (k == 1) {
        cout << "Iveskite 0, jeigu norite ivesti pazymius (ir 0, kai baigete ivedineti pazymius). 1 - jeigu norite, kad jie butu atsitiktinai generuojami.\n";
        cin >> l;
        for (int j = 0; j < kiek; j++) {
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
                return 0;
            }
        }
    }
    else {
        cout << "Jus ivedete neteisinga skaiciu";
        return 0;
    }

    rusiuoti(eil_mas, kiek);
    
    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu. 1 - jeigu norite skaiciuoti su mediana." << endl;
    cin >> gp;

    if (gp == 0) {
        cout << "Vardas      " << "Pavarde       " << "Galutinis(vid.)" << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < kiek; i++) {
            eil_mas[i].vid = eil_mas[i].vid / (float)eil_mas[i].num;
            eil_mas[i].gp = eil_mas[i].vid * 0.4 + eil_mas[i].egz * 0.6;
            cout << std::left << std::setw(12) << eil_mas[i].vard << std::left << std::setw(14) << eil_mas[i].pav;
            cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas[i].gp << endl;
        }
    }
    else if (gp == 1) {
        cout << "Vardas      " << "Pavarde       " << "Galutinis(med.)" << endl;
        cout << "-------------------------------------------------" << endl;
        for (int i = 0; i < kiek; i++) {
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
