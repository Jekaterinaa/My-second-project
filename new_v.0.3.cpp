#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "rusiavimas.h"
#include "ivedimasIsFailo.h"
#include "ivedimasRankomis.h"
#include "isvedimas.h"

int main()
{
    vector<duomuo> eil_mas;
    int k, l, gp, kiek;
    float paz;
    duomuo temp;

    cout << "Iveskite 0, jeigu norite nuskaityti duomenis is failo arba 1, jeigu norite ivesti juos.\n";
    cin >> k;

    try {
        if (k == 0) {
            eil_mas = ivedimasIsFailo();
        }
        else if (k == 1) {
            eil_mas = ivedimasRankomis();
        }
        else {
            throw(k);
        }
    }
    catch (int e) {
        cout << "Jus ivedete neteisinga skaiciu.\n";
    }

    eil_mas = rusiuoti(eil_mas);

    cout << "Iveskite 0, jeigu norite skaiciuoti GP su vidurkiu. 1 - jeigu norite skaiciuoti su mediana." << endl;
    cin >> gp;

    isvedimas(eil_mas, gp);
}
