# Versija V1.0 (realizacija su vektoriumi)
**Testavimo sistemos parametrai :** <br/>
CPU: i5-7200U 2.70 GHz <br/>
RAM: 8.00 GB <br/>
HDD: 237.00 GB <br/>
## Pirmos ir antros studentų dalijimo strategijų palyginimas :
| Studentų skaičius | Rūšiavimo laikas (1 strategija)  | Rūšiavimo laikas (2 strategija) |
|-------------------|----------------------------------|---------------------------------|
|100                |0.0036754 s                       |0.0026866 s                      |
|1000               |0.0213979 s                       |0.0155031 s                      |
|10000              |0.201508 s                        |0.151721 s                       |
|100000             |1.71521 s                         |0.156334 s                       |
|1000000            |18.7877 s                         |1.5931 s                         |

**Išvados :** <br/>
Realizacijoje su vektoriumi (kaip ir realizacijoje su list'u) geriau veikia antra strategija. Programoje sukuriamas failas su studentų ir jų pažymių skaičiumi, kuriuos įveda vartotojas. Duomenys iš jo nuskaitomi ir įrašomi į duomenų struktūros "duomuo" vektorių. Studentai rūšiuojami, naudojant antrą strategiją - studentai, kurių galutinis pažymys žemesnis negu 5 balai įrašomas į naują vektorių - "vargšiukai", o iš seno ištrinamas. O tie, kurųi galutinia pažymiai yra aukštesni negu 5 balai lieka sename vektoriuje. Pabaigoje sukuriami du nauji failai - protingų ir kvailų studentų, kur išvedami vardai, pavardės ir galutiniai pažymiai. 
