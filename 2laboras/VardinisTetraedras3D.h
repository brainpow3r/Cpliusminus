#ifndef _VARDINISTETRAEDRASD_H_
#define _VARDINISTETRAEDRASD_H_

#include "VardineAtkarpa3D.h"
#include <vector>

class VardinisTetraedras3D {
    private:
        char *name;
        char *info;
        std::vector<VardinisTaskas3D*> nodes;           //0, 1, 2 - pagrindo taskai; 3 - virsunes taskas
    public:

        VardinisTetraedras3D(char *name, char *info, VardinisTaskas3D *p1, VardinisTaskas3D *p2, VardinisTaskas3D *p3, VardinisTaskas3D *p4);
        VardinisTetraedras3D(VardinisTetraedras3D &copy);

        void printEverything();
        void setName(char *newName);
        void setInfo(char *newInfo);
        void setNode(VardinisTaskas3D *newNode, int n);

        char* getName();
        char* getInfo();
        VardinisTaskas3D* getNode(int n);
        VardinisTaskas3D* getCenter();
        double getVertexLength();

        double calculateTetrahedronSurfaceArea();
        double calculateTetrahedronVolume();
        double calculateTetrahedronHeight();
        double distanceToOther(VardinisTetraedras3D &other);

        ~VardinisTetraedras3D();
};

#endif