#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "rusiavimas.h"
#include "ivedimasRankomis.h"

vector<duomuo> ivedimasRankomis() {
    int kiek, l;
    float paz;
    duomuo temp;
    vector<duomuo> eil_mas;

    cout << "Iveskite studentu skaiciu.\n";
    cin >> kiek;
    cout << "Iveskite 0, jeigu norite ivesti pazymius (ir 0, kai baigete ivedineti pazymius). 1 - jeigu norite, kad jie butu atsitiktinai generuojami.\n";
    cin >> l;
    for (int j = 0; j < kiek; j++) {
        cout << "Iveskite studento duomenis (vardas, pavarde):\n";
        cin >> temp.vard >> temp.pav;
        if (l == 0) {
            cout << "Iveskite pazymi uz egzamina \n";
            cin >> temp.egz;
            do {
                cout << "Iveskite pazymi \n";
                cin >> paz;
                if (paz == 0)
                    break;
                temp.paz.push_back(paz);
            } while (temp.paz.size() <= 15);
        }
        else if (l == 1) {
            int kiek_paz;
            temp.egz = (rand() % 10) + 5;
            kiek_paz = (rand() % 10) + 1;


            for (int i = 0; i < kiek_paz; i++) {
                paz = (rand() % 10) + 1;
                temp.paz.push_back(paz);
            }
        }
        else {
            cout << "Jus ivedete neteisinga skaiciu";
        }
        eil_mas.push_back(temp);
    }
    return eil_mas;
}