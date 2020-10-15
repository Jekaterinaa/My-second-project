#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "rusiavimas.h"
#include "isvedimas.h"

void isvedimas(vector<duomuo> eil_mas, int gp) {
    try {
        if (gp == 0) {
            cout << "Vardas      " << "Pavarde       " << "Galutinis(vid.)" << endl;
            cout << "-------------------------------------------------" << endl;
            for (int i = 0; i < eil_mas.size(); i++) {
                eil_mas.at(i).vid = vidurkis(eil_mas.at(i).paz);
                eil_mas.at(i).gp = eil_mas.at(i).vid * 0.4 + eil_mas.at(i).egz * 0.6;
                cout << std::left << std::setw(12) << eil_mas.at(i).vard << std::left << std::setw(14) << eil_mas.at(i).pav;
                cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas.at(i).gp << endl;
            }
        }
        else if (gp == 1) {
            cout << "Vardas      " << "Pavarde       " << "Galutinis(med.)" << endl;
            cout << "-------------------------------------------------" << endl;
            for (int i = 0; i < eil_mas.size(); i++) {
                sort(eil_mas.at(i).paz.begin(), eil_mas.at(i).paz.end());
                eil_mas.at(i).med = mediana(eil_mas.at(i).paz);
                eil_mas.at(i).gp = eil_mas.at(i).med * 0.4 + eil_mas.at(i).egz * 0.6;
                cout << std::left << std::setw(12) << eil_mas.at(i).vard << std::left << std::setw(14) << eil_mas.at(i).pav;
                cout << std::left << std::setw(5) << std::setprecision(3) << eil_mas.at(i).gp << endl;
            }
        }
        else {
            throw(gp);
        }
    }
    catch (int e) {
        cout << "Jus ivedete neteisinga skaiciu.\n";
    }
}
