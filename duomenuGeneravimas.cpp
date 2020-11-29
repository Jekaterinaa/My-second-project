#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "duomenuGeneravimas.h"

skaicius duomenuGeneravimas() {
    skaicius sk;

    std::mt19937 mt(1729);
    std::uniform_int_distribution<int> dist(1, 10);

    std::cout << "iveskite studentu skaiciu" << std::endl;
    std::cin >> sk.kiek;
    std::cout << "iveskite pazymiu skaiciu" << std::endl;
    std::cin >> sk.kiek_paz;

    string pav;
    pav = "studentai" + std::to_string(sk.kiek) + ".txt";

    //auto start = std::chrono::high_resolution_clock::now(); auto st = start;

    std::ofstream naujas(pav);
    int temp;

    for (int i = 0; i < sk.kiek; i++) {
        naujas << "Vardas" << std::to_string(i + 1) << std::setw(20) << "Pavarde" << std::to_string(i + 1);
        for (int j = 0; j < sk.kiek_paz; j++) {
            //temp = (rand() % 10) + 1;
            temp = dist(mt);
            naujas << std::setw(15) << (float)temp;
        }
        //temp = (rand() % 10) + 1;
        temp = dist(mt);
        naujas << std::setw(15) << (float)temp << std::endl;
    }
    naujas.close();

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> diff = end - start;
    //std::cout << "Failo su " << sk.kiek << " eiluciu duomenu generavimas trunka : " << diff.count() << " s\n";

    return sk;

}