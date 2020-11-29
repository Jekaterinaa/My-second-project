#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"

float vidurkis(vector<float> v) {
    float sum, vid;
    sum = std::accumulate(v.begin(), v.end(), 0.0);
    vid = sum / (float)v.size();
    return vid;
}

float mediana(vector<float> v) {
    if (v.size() % 2 == 0)
        return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
    else
        return (float)v[v.size() / 2];
}