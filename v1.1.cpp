#include "studentas.h"

int main()
{
    vector<duomuo> studentai, vargsiukai;
    skaicius sk;
    int kiek_paz, kiek;
    int gp;

    sk = duomenuGeneravimas();
    kiek = sk.kiek;
    kiek_paz = sk.kiek_paz;
    //cout << kiek << endl << kiek_paz;
    studentai = duomenuNuskaitymas(kiek, kiek_paz);
    duomenuDalijimas(studentai, vargsiukai, kiek);

    //for (duomuo stud : vargsiukai)
      //  cout << stud.getPavarde() << " " << stud.getGP() << endl;
    isvedimasIFaila(studentai, kiek);
    isvedimasIFaila(vargsiukai, kiek);
}