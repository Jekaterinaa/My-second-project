#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "dalijimas.h"

void dalijimas(int gp, int kiek_paz, vector<duomuo> eil_mas, vector<duomuo> vargsiukai, vector<duomuo> kietiakiai) {

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    if (gp == 0) {
        for (int i = 0; i < eil_mas.size(); i++) {
            eil_mas.at(i).gp = vidurkis(eil_mas.at(i).paz);
            if (eil_mas.at(i).gp < 5.0) {
                vargsiukai.push_back(eil_mas.at(i));
                //sk_varg.kiek++;
            }
            else {
                kietiakiai.push_back(eil_mas.at(i));
                //sk_kiet.kiek++;
            }
        }
    }
    else if (gp == 1) {
        for (int i = 0; i < eil_mas.size(); i++) {
            eil_mas.at(i).gp = mediana(eil_mas.at(i).paz);
            if (eil_mas.at(i).gp < 5.0) {
                vargsiukai.push_back(eil_mas.at(i));
                //sk_varg.kiek++;
            }
            else {
                kietiakiai.push_back(eil_mas.at(i));
                //sk_kiet.kiek++;
            }
        }
    }

    eil_mas.clear();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << eil_mas.size() << " studentu dalijimas i vargsiukus ir kietiakius trunka : " << diff.count() << " s\n";
}