#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "duomenuGeneravimas.h"
#include "duomenuNuskaitymas.h"
#include "isvedimasIFaila.h"

int main()
{
    vector<duomuo> eil_mas, vargsiukai, kietiakiai;
    skaicius sk;
    int kiek_paz, kiek;
    int gp;

    sk = duomenuGeneravimas();
    eil_mas = duomenuNuskaitymas(sk);

    kiek = eil_mas.size();
    kiek_paz = sk.kiek_paz;

    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu, arba 1 - jeigu su mediana.\n";
    cin >> gp;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    if (gp == 0) {
        for (int i = 0; i < eil_mas.size(); i++) {
            eil_mas.at(i).gp = vidurkis(eil_mas.at(i).paz);
            if (eil_mas.at(i).gp < 5.0) {
                vargsiukai.push_back(eil_mas.at(i));
            }
            else {
                kietiakiai.push_back(eil_mas.at(i));
            }
        }
    }
    else if (gp == 1) {
        for (int i = 0; i < eil_mas.size(); i++) {
            eil_mas.at(i).gp = mediana(eil_mas.at(i).paz);
            if (eil_mas.at(i).gp < 5.0) {
                vargsiukai.push_back(eil_mas.at(i));
            }
            else {
                kietiakiai.push_back(eil_mas.at(i));
            }
        }
    }

    eil_mas.clear();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << kiek << " studentu dalijimas i vargsiukus ir kietiakius trunka : " << diff.count() << " s\n";

    isvedimasIFaila(vargsiukai, kiek);
    isvedimasIFaila(kietiakiai, kiek);

}

