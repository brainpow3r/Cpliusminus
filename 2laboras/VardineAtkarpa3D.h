#ifndef _VARDINEATKARPA3D_H
#define _VARDINEATKARPA3D_H

#include "VardinisTaskas3D.h"

class VardineAtkarpa3D {
    private:
        VardinisTaskas3D *start;
        VardinisTaskas3D *end;
        VardinisTaskas3D *midpoint;
        char *name;
        char *info;
        double length;
    public:
        VardineAtkarpa3D(char* name, char* info, double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd);
        VardineAtkarpa3D(char* name, char* info, VardinisTaskas3D *a, VardinisTaskas3D *b);
        VardineAtkarpa3D(VardineAtkarpa3D &copy);

        void printEverything();
        double getLength();
        char *getName();
        char *getInfo();
        VardinisTaskas3D *getStartpoint();
        VardinisTaskas3D *getEndpoint();

        void setInfo(const char* newInfo);
        void setName(const char* newName);
        void setStartpoint(const VardinisTaskas3D newStartpoint);
        void setEndpoint(const VardinisTaskas3D newEndpoint);

        VardinisTaskas3D *vidurioTaskas();
        double atstumasIkiKitosAtkarpos(VardineAtkarpa3D &other);

        ~VardineAtkarpa3D();
};

#endif
