# Versija V1.1 (realizacija su vektoriumi)
**Testavimo sistemos parametrai :** <br/>
CPU: i5-7200U 2.70 GHz <br/>
RAM: 8.00 GB <br/>
HDD: 237.00 GB <br/>
## Versijos V1.1 (su klase) veikimo sparta :
| Studentų skaičius | Duomenų generavimas  | Duomenų nuskaitymas | Dalijimas (2 strategija) | 
|-------------------|----------------------|---------------------|--------------------------|
|100000             |5.57489 s             |8.51528 s            | 4.70536 s                |
|1000000            |59.5849 s             |63.4079 s            | 20.5498 s                |

## Versijos V1.0 (su struktūra) veikimo sparta :
| Studentų skaičius | Duomenų generavimas  | Duomenų nuskaitymas | Dalijimas (2 strategija) | 
|-------------------|----------------------|---------------------|--------------------------|
|100000             |5.60813 s             |5.03034 s            |1.66319 s                 |
|1000000            | 65.3633 s            |55.3496 s            |21.2236 s                 |

**Išvados :** <br/>
Abi programos (ir su struktūra, ir su klase) veikimo laikas yra apytiksliai vienodas, bet duomenų nuskaitymas iš failo į klasės vektorių trunka šiek tiek ilgiau, negu į struktūrą. Duomenų dalijimas, naudojant sparčiausią (antrą) strategiją gali būti greitesnis ir programoje su struktūra, ir programoje su klase, priklauso nuo studentų skaičiaus.
