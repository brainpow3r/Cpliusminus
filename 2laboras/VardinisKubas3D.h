#ifndef _VARDINISKUBASD_H_
#define _VARDINISKUBASD_H_

#include "VardineAtkarpa3D.h"
#include <vector>

class VardinisKubas3D {
    private:
        char *name;
        char *info;
        std::vector<VardinisTaskas3D*> nodes;
        double vertex_length;

        void calculateCubePoints(VardinisTaskas3D *a);
    public:
        VardinisKubas3D(char *name, char *info, VardinisTaskas3D *a, double vertex_length);
        VardinisKubas3D(VardinisKubas3D &copy);

        void printEverything();
        void setName(char *newName);
        void setInfo(char *newInfo);
        void setNewPivotPoint(VardinisTaskas3D *newPoint);
        void setNewVertexLength(double newVertexLength);

        char *getName();
        char *getInfo();
        VardinisTaskas3D *getPivotPoint();
        VardinisTaskas3D *getNode(int n);
        VardinisTaskas3D *getCubeCenter();
        double getVertexLength();

        double calculateCubeArea();
        double calculateCubeVolume();
        double distanceToOther(VardinisKubas3D &other);

        ~VardinisKubas3D();
};

#endif
