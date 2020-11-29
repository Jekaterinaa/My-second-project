# Versija V1.0 (realizacija su list'u)
**Testavimo sistemos parametrai :** <br/>
CPU: i5-7200U 2.70 GHz <br/>
RAM: 8.00 GB <br/>
HDD: 237.00 GB <br/>
## Pirmos ir antros studentų dalijimo strategijų palyginimas :
| Studentų skaičius | Rūšiavimo laikas (1 strategija)  | Rūšiavimo laikas (2 strategija)  |
|-------------------|----------------------------------|----------------------------------|
|100                |0.001062 s                        |0.0015088 s                       |
|1000               |0.0078206 s                       |0.0173442 s                       |
|10000              |0.121771 s                        |0.134241 s                        |
|100000             |0.540101 s                        |0.12549 s                         |
|1000000            |5.80333 s                         |1.28885 s                         |
 
**Išvados :** <br/>
Kai programa realizuojama su list'u geriau veikia antra strategija, kur vargšiukai užrašomi į naują list'ą ir ištriname iš seno list'o, o kietieji lieka sename. 
