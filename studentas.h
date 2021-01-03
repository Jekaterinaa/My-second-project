#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <random>
#include <chrono>

#include <gtest/gtest.h>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

/// Funkcija „vidurkis“.
/// 
/// Ši funkcija apskaičiuoja studento pažymių vidurkį.

float vidurkis(vector <float>);

/// Struktūra „skaičius“
/// 
/// Šioje struktūroje saugomi du kintamieji. Kintamasis „kiek“ nurodo kiek studentų yra faile, kintamasis „kiek_paz“ nurodo kiek pažymių gavo kiekvienas studentas.

struct skaicius {
    int kiek;
    int kiek_paz;
};

/// Tėvinė klasė - „žmogus“.
/// 
/// Ši klasė yra abstrakti, yra du kintamieji - vardas bei pavardė. Kintamiesiems sukurti setteriai. Taip pat klasėje yra virtuali funkcija - spausdinti. Negalima sukurti objekto
/// „žmogus“ tipo objekto.

class zmogus {

public:
    string vardas;
    string pavarde;

    /// Virtuali funkcija.
    /// 
    /// Funkcija gali būti iškviesta tik klasėje „duomuo“.

    virtual void spausdinti() = 0;

    /// Funkcija getVardas.
    /// 
    /// Getteris vardui.
    /// Grąžina vardą.
    
    string getVardas() const
    {
        return vardas;
    }

    /// Funkcija getPavarde.
    /// 
    /// Getteris pavardei.
    /// Grąžina pavardę.
   
    string getPavarde() const
    {
        return pavarde;
    }

};

/// Išvestinė klasė - „duomuo“.
/// 
/// Šios išvestinės klasės tėvinė klasė yra klasė „žmogus“. Išvestinėje klasėje yra kintamieji „vardas“, „pavardė“, „paz“ (vektorius, kuriame saugomi studento pažymiai), 
/// „egz“ (studento pažymis už egzaminą), „gp“ (sutrumpintai galutinis pažymis).

class duomuo : public zmogus {
private:
    //string vardas;
    //string pavarde;
    vector <float> paz;
    float egz;
    float gp;

public:
    duomuo(string vardas, string pavarde, vector <float> paz, float egz)
    {
        this->vardas = vardas;
        this->pavarde = pavarde;
        this->paz = paz;
        this->egz = egz;
        this->gp = vidurkis(paz) * 0.4 + 0.6 * egz;
    }

    /// Destructor
    /// 
    /// „duomuo“ klasės destructor'ius, 

    ~duomuo() {

    }

    /// Copy constructor
    /// 
    /// Copy constructor iškviečiamas, kai sukuriamas naujas objektas, kaip jau egzistuojančio objekto kopija. 
    /// <param name="objektas"> „duomuo“ tipo objektas.

    duomuo(const duomuo& objektas) {
        vardas = objektas.vardas;
        pavarde = objektas.pavarde;
        paz = objektas.paz;
        egz = objektas.egz;
        gp = objektas.gp;
    }

    /// Assigment operator
    /// 
    /// Assignment operator iškviečiamas, kai sukurtam objektui priskiriama reikšmė iš jau egzistuojančion objekto.
    /// <param name="objektas"> „duomuo“ tipo objektas.
    /// <returns> grąžina „duomuo“ tipo objektą.

    duomuo& operator = (const duomuo& objektas) {
        vardas = objektas.vardas;
        pavarde = objektas.pavarde;
        paz = objektas.paz;
        egz = objektas.egz;
        gp = objektas.gp;
        return *this;
    }

    /// Spausdinimo funkcija
    /// 
    /// Ši funkcija išveda į ekraną žmogaus vardą bei pavardę.

    void spausdinti() {
        cout << vardas << " " << pavarde << endl;
    }

    /// Studento spausdinimo funkcija
    /// 
    /// Funkcija išveda į ekraną studento vardą, pavardę, visus pažymius iš pažymių vektoriaus „paz“ ir pažymį už egzaminą.
    /// <param name="kiek_paz"> kiek pažymių gavo studentas.

    void spausdintiStudenta(int kiek_paz) {
        cout << vardas << " " << pavarde << " ";
        for (int i = 0; i < kiek_paz; i++) {
            cout << paz.at(i) << " ";
        }
        cout << egz << endl;
    }

    /// Studento ir jo galutinio pažymio spausdinimo funkcija
    /// 
    /// Ši funkcija išveda į ekraną studento vardą, pavardę ir galutinį pažymį.

    void spausdintiSuGP() {
        cout << vardas << " " << pavarde << " " << gp << endl;
    }

    /// Gauti galutinį pažymį funkcija
    /// 
    /// Funkcija grąžina studento tipo „duomuo“ galutinį pažymį.
    
    float getGP() const
    {
        return gp;
    }

};

skaicius duomenuGeneravimas();
vector <duomuo> duomenuNuskaitymas(int, int);
void duomenuDalijimas(vector <duomuo>&, vector <duomuo>&, int);
void isvedimasIFaila(vector <duomuo>, int);
