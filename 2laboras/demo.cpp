//#include "VardineAtkarpa3D.h"
#include "VardineSfera3D.h"
#include "VardinisTrikampis3D.h"
#include "VardinisKubas3D.h"
#include "VardinisTetraedras3D.h"
#include <iostream>
#include <math.h>
#define NEWLINE std::cout << std::endl
#define LOG(x) std::cout << x << std::endl

/*
    kompiliuoti su komanda:
    g++ demo.cpp VardinisTaskas3D.cpp VardineAtkarpa3D.cpp VardineSfera3D.cpp VardinisTrikampis3D.cpp VardinisKubas3D.cpp VardinisTetraedras3D.cpp -o demo -std=c++11 -w
*/

int main() {
    VardinisTaskas3D *taskas1 = new VardinisTaskas3D("A", "Taskas1", 0, 12, 0);
    VardinisTaskas3D *taskas2 = new VardinisTaskas3D("B", "Taskas2", 6, 12, 3);
    VardinisTaskas3D *taskas3 = new VardinisTaskas3D("C", "Taskas3", 66, 17, -9);
    LOG("Tasko informacija: ");
    taskas1->rodykTaska();
    NEWLINE;

    VardineAtkarpa3D *atkarpa1 = new VardineAtkarpa3D("Atkarpa1", "Pirmoji atkarpa", 1, 1, 1, 3, 6, 9);
    VardineAtkarpa3D *atkarpa2 = new VardineAtkarpa3D("Atkarpa2", "Antroji atkarpa", taskas1, taskas2);
    LOG("Atkarpos informacija: ");
    atkarpa1->printEverything();
    NEWLINE;
    LOG("Atstumas tarp atkarpa1 ir atkarpa2: ");
    std::cout << atkarpa1->atstumasIkiKitosAtkarpos(*atkarpa2) << std::endl;
    NEWLINE;
    
    VardineSfera3D *sfera1 = new VardineSfera3D("O", "Sfera1", 3.4, taskas1);
    sfera1->printEverything();
    LOG("Sferos pavirsiaus plotas ir turis: ");
    std::cout << sfera1->sphereSurfaceArea() << " , " << sfera1->sphereVolume() << std::endl;

    VardineSfera3D *sfera2 = new VardineSfera3D(*sfera1);
    sfera2->setCenterPoint(*taskas3);
    sfera1->setRadius(8);
    LOG("Atstumas tarp sfera1 ir sfera2: ");
    std::cout << sfera1->distanceToAnother(*sfera2) << std::endl;
    NEWLINE;

    VardinisTrikampis3D *trikampis1 = new VardinisTrikampis3D("ABC", "Trikampis 1", *taskas1, *taskas2, *taskas3);
    trikampis1->printEverything();
    NEWLINE;
    trikampis1->vertexLengths();
    LOG("Trikampio centras: ");
    std::cout << "( " << trikampis1->getCenterPoint()->getX() << ", " << trikampis1->getCenterPoint()->getY() << ", " << trikampis1->getCenterPoint()->getZ() << " )" << std::endl;
    NEWLINE;
    LOG("Trikampio perimetras ir plotas: ");
    std::cout << "P = " << trikampis1->calculatePerimeter() << " S = " << trikampis1->calculateArea() << std::endl;
    NEWLINE;

    VardinisKubas3D *kubas1 = new VardinisKubas3D("W", "Pirmas Kubas", taskas3, 10);
    kubas1->printEverything();
    LOG("Kubo pavirsiaus plotas ir turis: ");
    std::cout << kubas1->calculateCubeArea() << ", " << kubas1->calculateCubeVolume() << std::endl;
    VardinisKubas3D *kubas2 = new VardinisKubas3D(*kubas1);
    kubas2->setNewPivotPoint(taskas1);
    kubas2->setNewVertexLength(2);
    LOG("Atstumas tarp kubas1 ir kubas2: ");
    std::cout << kubas1->distanceToOther(*kubas2) << std::endl;
    NEWLINE;

    VardinisTaskas3D *tp1 = new VardinisTaskas3D("T1", "Pirmas tetr. taskas", 0, 0, 0);
    VardinisTaskas3D *tp2 = new VardinisTaskas3D("T2", "Pirmas tetr. taskas", 0, 1, 0);
    VardinisTaskas3D *tp3 = new VardinisTaskas3D("T3", "Pirmas tetr. taskas", sqrt(3)/2, 0.5, 0);
    VardinisTaskas3D *tp4 = new VardinisTaskas3D("T4", "Pirmas tetr. taskas", sqrt(3)/6, 0.5, sqrt(6)/3);

    VardinisTetraedras3D *tetr1 = new VardinisTetraedras3D("OBJ", "Tetraedras", tp1, tp2, tp3, tp4);
    tetr1->printEverything();
    NEWLINE;
    LOG("Tetraedro pavirsiaus plotas ir turis: ");
    std::cout << tetr1->calculateTetrahedronSurfaceArea() << ", " << tetr1->calculateTetrahedronVolume() << std::endl;
    LOG("Tetraedro briaunos ilgis: ");
    std::cout << tetr1->getVertexLength() << std::endl;
    LOG("Tetraedro aukstis: ");
    std::cout << tetr1->calculateTetrahedronHeight() << std::endl;
    NEWLINE;
}