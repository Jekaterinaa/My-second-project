#include "biblioteka1.h"
#include "struktura.h"
#include "vid_med.h"
#include "duomenuGeneravimas.h"
#include "duomenuNuskaitymas.h"

void isvedimasIFaila(list<duomuo> sar, int kiek) {
	string pav, zodis;
	int ilgis = sar.size();

	if (!sar.empty()) {
		//auto start = std::chrono::high_resolution_clock::now(); auto st = start;

		if (sar.front().gp < 5.0) {
			pav = "vargsiukai" + std::to_string(kiek) + ".txt";
			zodis = "Vargsiuku";
		}
		else {
			pav = "kietiakiai" + std::to_string(kiek) + ".txt";
			zodis = "Kietiakiu";
		}
		std::ofstream failas(pav);

		for (int i = 0; i < ilgis; i++) {
			//failas << sar.at(i).vard << std::setw(20) << sar.at(i).pav << std::setw(15) << sar.at(i).gp << endl;
			failas << sar.front().vard << std::setw(20) << sar.front().pav << std::setw(15) << sar.front().gp << endl;
			sar.pop_front();
		}
		failas.close();

		//auto end = std::chrono::high_resolution_clock::now();
		//std::chrono::duration<double> diff = end - start;
		//std::cout << zodis << " isvedimas i faila trunka : " << diff.count() << " s\n";
	}
	else {
		return;
	}
}