#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "duomenuGeneravimas.h"
#include "duomenuNuskaitymas.h"
#include "isvedimasIFaila.h"

int main()
{
    vector<duomuo> eil_mas, vargsiukai;
    //kietiakiai;
    skaicius sk;
    int kiek_paz, kiek;
    int gp;

    sk = duomenuGeneravimas();
    eil_mas = duomenuNuskaitymas(sk);

    kiek = eil_mas.size();
    kiek_paz = sk.kiek_paz;

    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu, arba 1 - jeigu su mediana.\n";
    cin >> gp;

    if (gp == 0) {
        for (int i = 0; i < eil_mas.size(); i++)
            eil_mas.at(i).gp = vidurkis(eil_mas.at(i).paz);
    }
    else if (gp == 1) {
        for (int i = 0; i < eil_mas.size(); i++) 
            eil_mas.at(i).gp = mediana(eil_mas.at(i).paz);
    }

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    for (duomuo stud : eil_mas) {
        if (stud.gp < 5.0) {
            vargsiukai.push_back(stud);
        }
    }
    eil_mas.erase(std::remove_if(eil_mas.begin(), eil_mas.end(), [](duomuo stud)
        {
            return stud.gp < 5.0;
        }), eil_mas.end());

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << sk.kiek << " studentu dalijimas i vargsiukus ir kietiakius trunka : " << diff.count() << " s\n";

    isvedimasIFaila(vargsiukai, sk.kiek);
    isvedimasIFaila(eil_mas, sk.kiek);

}

