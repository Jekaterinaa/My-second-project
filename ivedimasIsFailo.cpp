#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "rusiavimas.h"
#include "ivedimasIsFailo.h"


vector<duomuo> ivedimasIsFailo() {
    int kiek;
    float paz;
    duomuo temp;
    vector <duomuo> eil_mas;

    std::ifstream duomenys;
    try {
        duomenys.open("kursiokai.txt");
        duomenys >> kiek;
        cout << kiek << endl;

        for (int i = 0; i < kiek && !duomenys.eof(); i++) {
            duomenys >> temp.vard;
            if (duomenys.eof()) {
                eil_mas.pop_back();
                break;
            }
            duomenys >> temp.pav;
            for (int j = 0; j < 5; j++) {
                duomenys >> paz;
                temp.paz.push_back(paz);
            }
            duomenys >> temp.egz;
            eil_mas.push_back(temp);
        }
        //duomenys.close();
    }
    catch (int e) {
        cout << "Neteisingas failo pavadinimas.\n";
        exit(1);
    }
    
    return eil_mas;
}