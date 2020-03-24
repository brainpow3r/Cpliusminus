#ifndef _VARDINISTRIKAMPIS3D_H_
#define _VARDINISTRIKAMPIS3D_H_

#include "VardineAtkarpa3D.h"

class VardinisTrikampis3D {
    private:
        char *name;
        char *info;
        VardinisTaskas3D *a;
        VardinisTaskas3D *b;
        VardinisTaskas3D *c;
        VardinisTaskas3D *center;
    public:
        VardinisTrikampis3D(char *name, char *info, VardinisTaskas3D first, VardinisTaskas3D second, VardinisTaskas3D third);
        VardinisTrikampis3D(VardinisTrikampis3D &copy);

        void setName(char *newName);
        void setInfo(char *newInfo);
        void setPoint(VardinisTaskas3D *newPoint, int option);

        char *getName();
        char *getInfo();
        VardinisTaskas3D *getPoint(int choice);
        VardinisTaskas3D *getCenterPoint();

        void printEverything();
        void vertexLengths();
        double calculatePerimeter();
        double calculateArea();
        double distanceToAnother(VardinisTrikampis3D &other);

        ~VardinisTrikampis3D();
};


#endif