#ifndef _VARDINESFERA3D_H_
#define _VARDINESFERA3D_H_

#include "VardineAtkarpa3D.h"

class VardineSfera3D {
    private:
        char *name;
        char *info;
        double radius_length;
        VardinisTaskas3D *center;
        VardinisTaskas3D *border_point;
        VardineAtkarpa3D *radius;
    public:
        VardineSfera3D(char *name, char *info, double radius, VardinisTaskas3D *center);
        VardineSfera3D(VardineSfera3D &copy);

        void printEverything();
        double sphereSurfaceArea();
        double sphereVolume();
        double distanceToAnother(VardineSfera3D &other); 

        char *getName();
        char *getInfo();
        double getRadiusLength();
        VardinisTaskas3D *getCenterPoint();
        VardineAtkarpa3D *getRadius();

        void setName(char *newName);
        void setInfo(char *newInfo);
        void setCenterPoint(VardinisTaskas3D newCenter);
        void setRadius(double newRadiusLength);

        ~VardineSfera3D();
};

#endif