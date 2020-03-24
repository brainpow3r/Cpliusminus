#include "geometrija.h"
#include <iostream>
#include <cmath>

double atstumasIkiKoordinaciuPradzios(const Taskas3D& taskas){
      return sqrt(taskas.x * taskas.x + taskas.y * taskas.y + taskas.z * taskas.z);
}

double atstumasTarpTasku(const Taskas3D& taskas1, const Taskas3D& taskas2){
      double dx = taskas2.x - taskas1.x;
      double dy = taskas2.y - taskas1.y;
      double dz = taskas2.z - taskas1.z;

      return sqrt(dx * dx + dy * dy + dz * dz);
}

double atkarposIlgis(const Atkarpa3D& atkarpa){
     return atstumasTarpTasku(atkarpa.a, atkarpa.b);
}

void skaitykTaska(Taskas3D& taskas){

    std::cin >> taskas.x >> taskas.y >> taskas.z;

}

void rasykTaska(const Taskas3D& taskas){
    std::cout << "(" << taskas.x << ", " <<  taskas.y << ", " << taskas.z << ")";
}

double sferosPavPlotas(const Sfera& sf){
	return 4*M_PI*sf.spindulys*sf.spindulys;
}

double sferosTuris(const Sfera &sf) {
    return ((4/3)*M_PI*pow(sf.spindulys, 3));
}

double trikampioPerimetras (const Trikampis& trikampis){
	Atkarpa3D AB{trikampis.pirmas, trikampis.antras};
	Atkarpa3D BC{trikampis.trecias, trikampis.antras};
	Atkarpa3D AC{trikampis.pirmas, trikampis.trecias};
	return atkarposIlgis(AB) + atkarposIlgis(BC) + atkarposIlgis(AC);
}

double trikampioPlotas(const Trikampis &trikampis) {
    Atkarpa3D AB{trikampis.pirmas, trikampis.antras};
    Atkarpa3D AC{trikampis.pirmas, trikampis.antras};

    return (0.5 * atkarposIlgis(AB) * atkarposIlgis(AC) * sin(trikampis.kampasTarpBriaunu));
}

double tetraedroPavirsiausPlotas(const TaisyklingasisTetraedras& tetraedras) {
    Atkarpa3D briauna{tetraedras.pirmas, tetraedras.antras};

    return (sqrt(3) * pow(atkarposIlgis(briauna), 2));
}

double tetraedroTuris(const TaisyklingasisTetraedras &tetraedras) {
    Atkarpa3D briauna{tetraedras.pirmas, tetraedras.antras};

    double turis = (double)( (sqrt(2)*pow(atkarposIlgis(briauna), 3))/12 );

    return turis;
}

Taskas3D *tetraedroCentroTaskas(const TaisyklingasisTetraedras &tetraedras) {
	
	Taskas3D pagrindoCentras{tetraedras.ketvirtas.x, 0, tetraedras.ketvirtas.z};
	Atkarpa3D aukstine{pagrindoCentras, tetraedras.ketvirtas};

	double aukstinesIlgis = atkarposIlgis(aukstine);
	std::cout << "aukstinesIlgis: " << aukstinesIlgis << std::endl;

	Taskas3D *centroTaskas = new Taskas3D();

	centroTaskas->x = pagrindoCentras.x;
	centroTaskas->y = (aukstinesIlgis/3);
	centroTaskas->z = pagrindoCentras.z;

	return centroTaskas;
};

double kuboPavirsiausPlotas(const Kubas &kubas) {
    return 6*kubas.briaunosIlgis*kubas.briaunosIlgis;
}

double kuboTuris(const Kubas &kubas) {
    return pow(kubas.briaunosIlgis, 3);
}

double kuboIstrizaine(const Kubas &kubas) {
    Atkarpa3D istrizaine{kubas.pradziosTaskas, kubas.vdv};             // kubo istrizaine: nuo pradzios tasko iki toliausiai nuo jo nutolusio tasko

    std::cout << "Istrizaines galu tasku koordinates: ";
    rasykTaska(istrizaine.a);
    rasykTaska(istrizaine.b);

    return atkarposIlgis(istrizaine);
}

Taskas3D* generuotiTaskusKubui(Taskas3D *taskai, Taskas3D pradziosTaskas, double briaunosIlgis) {

    taskai[0] = {pradziosTaskas.x+briaunosIlgis, pradziosTaskas.y, pradziosTaskas.z};                                // apatinis desinys pagrindo taskas
    taskai[1] = {pradziosTaskas.x, pradziosTaskas.y, pradziosTaskas.z+briaunosIlgis};                                // virsutinis kairys pagrindo taskas
    taskai[2] = {pradziosTaskas.x+briaunosIlgis, pradziosTaskas.y, pradziosTaskas.z+briaunosIlgis};                  // virsutinis desinys pagrindo taskas
    taskai[3] = {pradziosTaskas.x, pradziosTaskas.y+briaunosIlgis, pradziosTaskas.z};                                // apatinis kairys virsutinio pagrindo taskas
    taskai[4] = {pradziosTaskas.x+briaunosIlgis, pradziosTaskas.y+briaunosIlgis, pradziosTaskas.z};                  // apatinis desinys virsutinio pagrindo taskas
    taskai[5] = {pradziosTaskas.x, pradziosTaskas.y+briaunosIlgis, pradziosTaskas.z+briaunosIlgis};                  // virsutins kairys virsutinio pagrindo taskas
    taskai[6] = {pradziosTaskas.x+briaunosIlgis, pradziosTaskas.y+briaunosIlgis, pradziosTaskas.z+briaunosIlgis};    // virsutinis desinys virsutinio pagrindo taskas

    return taskai;
}

TaisyklingasisTetraedras *konstruotiDidesniTetraedra(const TaisyklingasisTetraedras &tetraedras/*, TaisyklingasisTetraedras &new_tetraedras*/) {

    TaisyklingasisTetraedras *new_tetraedras = new TaisyklingasisTetraedras();

    new_tetraedras->pirmas.x = tetraedras.pirmas.x*2;
    new_tetraedras->pirmas.y = tetraedras.pirmas.y*2;
    new_tetraedras->pirmas.z = tetraedras.pirmas.z*2;

    new_tetraedras->antras.x = tetraedras.antras.x*2;
    new_tetraedras->antras.y = tetraedras.antras.y*2;
    new_tetraedras->antras.z = tetraedras.antras.z*2;

    new_tetraedras->trecias.x = tetraedras.trecias.x*2;
    new_tetraedras->trecias.y = tetraedras.trecias.y*2;
    new_tetraedras->trecias.z = tetraedras.trecias.z*2;

    new_tetraedras->ketvirtas.x = tetraedras.ketvirtas.x*2;
    new_tetraedras->ketvirtas.y = tetraedras.ketvirtas.y*2;
    new_tetraedras->ketvirtas.z = tetraedras.ketvirtas.z*2;

    return new_tetraedras;
}
