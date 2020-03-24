#ifndef _GEOMETRIJA3D_H_
#define _GEOMETRIJA3D_H_

struct Taskas3D{
   double x;
   double y;
   double z;
};

struct Atkarpa3D{
   Taskas3D a;
   Taskas3D b;
};

struct Sfera{
	Taskas3D centras;
	double spindulys;
};

struct Trikampis{
	Taskas3D pirmas;
	Taskas3D antras;
	Taskas3D trecias;
	double kampasTarpBriaunu;           // kampas tarp briaunu, turinciu bendra taska
};

struct Kubas {
    double briaunosIlgis;
    Taskas3D pradziosTaskas;                                                                                   // kubo kairys apatinis taskas
    Taskas3D adp;                       // apatinis desinys pagrindo taskas
    Taskas3D vkp;                       // virsutinis kairys pagrindo taskas
    Taskas3D vdp;                       // virsutinis desinys pagrindo taskas
    Taskas3D akv;                       // apatinis kairys virsutinio pagrindo taskas
    Taskas3D adv;                       // apatinis desinys virsutinio pagrindo taskas
    Taskas3D vkv;                       // virsutins kairys virsutinio pagrindo taskas
    Taskas3D vdv;                       // virsutinis desinys virsutinio pagrindo taskas
};

struct TaisyklingasisTetraedras {
    Taskas3D pirmas;                    //pirmis trys taskai - vienos sienos koordinates
    Taskas3D antras;
    Taskas3D trecias;
    Taskas3D ketvirtas;                 // paskutinis taskas - tetraedro virsune, nepatenka i siena apibrezta pirmais 3 taskais
    Trikampis siena;                    // tetraedro siena - apibrezta pirmais trim taskais
};

double atstumasIkiKoordinaciuPradzios(const Taskas3D &taskas);
double atstumasTarpTasku(const Taskas3D& taskas1, const Taskas3D &taskas2);
double atkarposIlgis(const Atkarpa3D &atkarpa);
void skaitykTaska(Taskas3D &taskas);
void rasykTaska(const Taskas3D &taskas);

double sferosPavPlotas(const Sfera &sf);
double sferosTuris(const Sfera &sf);                                                // GS 190217

double trikampioPerimetras (const Trikampis &trikampis);
double trikampioPlotas (const Trikampis &trikampis);                                // GS 190217

double tetraedroPavirsiausPlotas(const TaisyklingasisTetraedras &tetraedras);       // GS 190217
double tetraedroTuris(const TaisyklingasisTetraedras &tetraedras);                  // GS 190217
TaisyklingasTetraedras *kurtiTetraedra(const TaisyklingasisTetraedras &tetraedras); // GS 190217

double kuboPavirsiausPlotas(const Kubas &kubas);                                    // GS 190217
double kuboTuris(const Kubas &kubas);                                               // GS 190217
double kuboIstrizaine(const Kubas &kubas);                                          // GS 190217
Taskas3D* generuotiTaskusKubui(Taskas3D *taskai, Taskas3D pradziosTaskas, double briaunosIlgis);     // GS 190217

#endif
