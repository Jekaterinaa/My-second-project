#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "duomenuNuskaitymas.h"


list<duomuo> duomenuNuskaitymas(skaicius sk) {
    //vector<duomuo> eil_mas;
    //int kiek = eil_mas.size();
    list<duomuo> eil_mas;
    string pav;
    duomuo temp;
    float paz;

    pav = "studentai" + std::to_string(sk.kiek) + ".txt";

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    std::ifstream duomenys;
    duomenys.open(pav);

    if (duomenys.fail()) {
        cout << "Nepavyko atidaryti failo" << endl;
        exit(1);
    }

    while(duomenys.eof() != true) {
        duomenys >> temp.vard >> temp.pav;
        temp.paz.clear();
        for (int j = 0; j < sk.kiek_paz; j++) {
            duomenys >> paz;
            temp.paz.push_back(paz);
        }
        duomenys >> temp.egz;
        eil_mas.push_back(temp);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << sk.kiek << " duomenu nuskaitymas is failo trunka : " << diff.count() << " s\n";

    return eil_mas;
}