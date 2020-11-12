#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "duomenuGeneravimas.h"
#include "duomenuNuskaitymas.h"
#include "isvedimasIFaila.h"

int main()
{
    duomuo temp;
    string pav;
    skaicius sk;
    int kiek_paz, kiek, gp;
    float paz;

    list<duomuo> eil_mas, vargsiukai, kietiakiai;

    sk = duomenuGeneravimas();
    eil_mas = duomenuNuskaitymas(sk);

    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu, arba 1 - jeigu su mediana.\n";
    cin >> gp;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    if (gp == 0) {
        for (int i = 0; i < sk.kiek; i++) {
            eil_mas.front().gp = vidurkis(eil_mas.front().paz);
            if (eil_mas.front().gp < 5.0) {
                vargsiukai.push_back(eil_mas.front());
            }
            else {
                kietiakiai.push_back(eil_mas.front());
            }

            eil_mas.pop_front();
        }
    }
    else if (gp == 1) {
        for (int i = 0; i < eil_mas.size(); i++) {
            eil_mas.front().gp = mediana(eil_mas.front().paz);
            if (eil_mas.front().gp < 5.0) {
                vargsiukai.push_back(eil_mas.front());
            }
            else {
                kietiakiai.push_back(eil_mas.front());
            }

            eil_mas.pop_front();
        }
    }

    eil_mas.clear();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << sk.kiek << " studentu dalijimas i vargsiukus ir kietiakius trunka : " << diff.count() << " s\n";

    isvedimasIFaila(vargsiukai, sk.kiek);
    isvedimasIFaila(kietiakiai, sk.kiek);

    vargsiukai.clear();
    kietiakiai.clear();

}

