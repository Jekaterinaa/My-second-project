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

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

float vidurkis(vector <float>);

struct skaicius {
    int kiek;
    int kiek_paz;
};

class duomuo {
private:
	string vardas;
	string pavarde;
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

    string getVardas()
    {
        return vardas;
    }

    string getPavarde()
    {
        return pavarde;
    }
    
    float getGP() const
    {
        return gp;
    }

};

skaicius duomenuGeneravimas();
vector <duomuo> duomenuNuskaitymas(int, int);
void duomenuDalijimas(vector <duomuo>&, vector <duomuo>&, int);
void isvedimasIFaila(vector <duomuo>, int);
