#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "rusiavimas.h"

bool palyginimas(duomuo d1, duomuo d2)
{
    return d1.vard < d2.vard;
}

vector<duomuo> rusiuoti(vector<duomuo>  sar)
{
    sort(sar.begin(), sar.end(), palyginimas);
    return sar;
}
