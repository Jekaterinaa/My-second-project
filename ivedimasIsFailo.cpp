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

        for (int i = 0; i < kiek && !duomenys.eof(); i++) {
            duomenys >> temp.vard >> temp.pav;
            for (int j = 0; j < 5; j++) {
                duomenys >> paz;
                temp.paz.push_back(paz);
            }
            duomenys >> temp.egz;
            eil_mas.push_back(temp);
        }
    }
    catch (int e) {
        cout << "Neteisingas failo pavadinimas.\n";
       
    }
    
    return eil_mas;
}