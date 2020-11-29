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

    list<duomuo> eil_mas, vargsiukai;
    list<duomuo>::iterator it;

    sk = duomenuGeneravimas();
    eil_mas = duomenuNuskaitymas(sk);

    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu, arba 1 - jeigu su mediana.\n";
    cin >> gp;


    if (gp == 0) {
        for (list<duomuo>::iterator it = eil_mas.begin(); it != eil_mas.end(); ++it) {
            duomuo& stud = *it;
            stud.gp = vidurkis(stud.paz);
        }
    }
    else if (gp == 1) {
        for (list<duomuo>::iterator it = eil_mas.begin(); it != eil_mas.end(); ++it) {
            duomuo& stud = *it;
            stud.gp = mediana(stud.paz);
        }
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

    vargsiukai.clear();
    eil_mas.clear();

}

