#include "geometrija.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(){

    Taskas3D pA{1,1,1};
    Taskas3D pB;
    Taskas3D pC{1,0,0};

    skaitykTaska(pB);
    cout << "Taskas pA: ";
    rasykTaska(pA);
    cout << endl;
    cout << "Taskas pB: ";
    rasykTaska(pB);
    cout << endl;

    cout << "Atstumas nuo pB iki k. centro: " << atstumasIkiKoordinaciuPradzios(pB) << endl;

    Atkarpa3D atkAB{pA, pB};
    cout << "Atkarpos AB ilgis: " << atkarposIlgis(atkAB) << endl;

    Sfera sf{pA, 5};
    cout << "Sferos pavirsiaus plotas " << sferosPavPlotas(sf) << endl;
    cout << "Sferos turis: " << sferosTuris(sf) << endl;

    Trikampis trikampis{pA, pB, pC, 45};
	cout << "Trikampio perimetras: "<< trikampioPerimetras(trikampis) << endl;
	cout << "Trikampio plotas: " << trikampioPlotas(trikampis) << endl;

    // tokiomis koordinatemis apibrezti taskai sudaro taisyklinga tetraedra kurio briaunos ilgis = 1
    Taskas3D tA{0, 0, 0};
    Taskas3D tB{0,1,0};
    Taskas3D tC{sqrt(3)/2, 0.5, 0};
    Taskas3D tD{sqrt(3)/6, 0.5, sqrt(6)/3};
    Trikampis siena{tA, tB, tC};
    TaisyklingasisTetraedras tetraedras{tA, tB, tC, tD, siena};
    cout << "Taisyklingojo tetraedro briaunos ilgis: " << atstumasTarpTasku(tetraedras.pirmas, tetraedras.antras) << endl;
    cout << "Taisyklingojo tetraedro pavirsiaus plotas: " << tetraedroPavirsiausPlotas(tetraedras) << endl;
    cout << "Taisyklingojo tetraedro turis: " << tetraedroTuris(tetraedras) << endl;

    // kubas kurio briaunos ilgis = 3
    Taskas3D pradziosTaskas{0, 0, 0};
    Taskas3D kuboTaskai[7] = {};
    generuotiTaskusKubui(kuboTaskai, pradziosTaskas, 3.0);
    Kubas kubas{3.0, pradziosTaskas, kuboTaskai[0], kuboTaskai[1], kuboTaskai[2], kuboTaskai[3], kuboTaskai[4], kuboTaskai[5], kuboTaskai[6]};
    cout << "Kubo pavirsiaus plotas: " << kuboPavirsiausPlotas(kubas) << std::endl;
    cout << "Kubo turis: " << kuboTuris(kubas) << std::endl;
    kuboIstrizaine(kubas);

    return 0;



}
