#include <iostream>
#include <cmath>
#include <string.h>
#include "VardineSfera3D.h"

#define SEPARATOR std::cout << "-----------------------------" << std::endl

VardineSfera3D::VardineSfera3D(char *name, char *info, double radius_length, VardinisTaskas3D *center) {
    
    if( name != nullptr ){    
        int l1 = strlen(name);
        this->name = new char[l1+1];
        strcpy(this->name, name);
    } else
        this->name = nullptr;
       
    if( info != NULL ){    
        int l2 = strlen(info);
        this->info = new char[l2+1];
        strcpy(this->info, info);
    } else
        this->info = NULL;

    this->radius_length = radius_length;
    this->border_point = new VardinisTaskas3D("T", "Spindulio galas", center->getX()+radius_length, center->getY(), center->getZ());
    this->center = new VardinisTaskas3D("O", "Sphere Center", center->getX(), center->getY(), center->getZ());
    this->radius = new VardineAtkarpa3D("R", "Sphere radius", center, border_point);
}

VardineSfera3D::VardineSfera3D(VardineSfera3D & copy) {
    if( name != nullptr ){
        int l1 = strlen(name);
        this->name = new char[l1+1];
        strcpy(this->name, name);
    } else
        this->name = nullptr;

    if( info != NULL ){
        int l2 = strlen(info);
        this->info = new char[l2+1];
        strcpy(this->info, info);
    } else
        this->info = NULL;

    this->radius_length = copy.getRadiusLength();
    this->center = new VardinisTaskas3D(*copy.getCenterPoint());
    this->border_point = new VardinisTaskas3D("T", "Spindulio galas", center->getX()+radius_length, center->getY(), center->getZ());
    this->radius = new VardineAtkarpa3D("R", "Sphere radius", center, border_point);
}

void VardineSfera3D::printEverything() {
    std::cout << "Sferos informacija: " << std::endl;
    SEPARATOR;
    std::cout << "Vardas: " << this->name << std::endl;
    std::cout << "Info: " << this->info << std::endl;
    std::cout << "Spindulio ilgis: " << this->radius_length << std::endl;
    std::cout << "Centro taskas: " << std::endl;
    SEPARATOR;
    this->center->rodykTaska();
    SEPARATOR;
    std::cout << "Spindulys: " << std::endl;
    this->radius->printEverything();

}

double VardineSfera3D::sphereSurfaceArea() {
    return (4.0 * M_PI * pow(this->radius_length, 2));
}

double VardineSfera3D::sphereVolume() {
    return ((4/3) * M_PI * pow(this->radius_length, 3));
}

double VardineSfera3D::distanceToAnother(VardineSfera3D &other) {
    double dx = this->center->getX() - other.getCenterPoint()->getX();
    double dy = this->center->getY() - other.getCenterPoint()->getY();
    double dz = this->center->getZ() - other.getCenterPoint()->getZ();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

char *VardineSfera3D::getName() {
    return this->name;
}

char *VardineSfera3D::getInfo() {
    return this->info;
}

double VardineSfera3D::getRadiusLength() {
    return this->radius_length;
}

VardinisTaskas3D *VardineSfera3D::getCenterPoint() {
    return this->center;
}

VardineAtkarpa3D *VardineSfera3D::getRadius() {
    return this->radius;
}

void VardineSfera3D::setName(char *newName) {
    if( this->name != nullptr ) delete[] this->name;     
    int l = strlen(newName);
    this->name = new char[l+1];
    strcpy(this->name, newName);
}

void VardineSfera3D::setInfo(char *newInfo) {
    if( this->info != nullptr ) delete[] this->info;     
    int l = strlen(newInfo);
    this->info = new char[l+1];
    strcpy(this->info, newInfo);
}

void VardineSfera3D::setCenterPoint(VardinisTaskas3D newCenter) {
    if (this->center != nullptr) delete this->center;
    this->center = new VardinisTaskas3D("O", "Sphere Center", newCenter.getX(), newCenter.getY(), newCenter.getZ());

    if (this->border_point != nullptr) delete this->border_point;
    this->border_point = new VardinisTaskas3D("T", "Spindulio galas", this->center->getX()+this->radius_length,
                                                this->center->getY(), this->center->getZ());

    if (this->radius != nullptr) delete this->radius;
    this->radius = new VardineAtkarpa3D("R", "Sphere radius", this->center, this->border_point);
}

void VardineSfera3D::setRadius(double newRadiusLength) {
    this->radius_length = newRadiusLength;
    if (this->border_point != nullptr) delete this->border_point;

    this->border_point = new VardinisTaskas3D("T", "Spindulio galas", this->center->getX()+newRadiusLength,
                                                this->center->getY(), this->center->getZ());
                                                
    if (this->radius != nullptr) delete this->radius;
    this->radius = new VardineAtkarpa3D("R", "Sphere radius", this->center, this->border_point);
}

VardineSfera3D::~VardineSfera3D() {
    if (this->name != nullptr) delete[] this->name;
    if (this->info != nullptr) delete[] this->info;
    if (this->radius != nullptr) delete this->radius;
    if (this->border_point != nullptr) delete this->border_point;
    if (this->center != nullptr) delete this->center;
}