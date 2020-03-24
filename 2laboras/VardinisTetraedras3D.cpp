#include "VardinisTetraedras3D.h"
#include "VardinisTrikampis3D.h"
#include <string.h>
#include <math.h>
#include <iostream>

#define SEPARATOR std::cout << "-----------------------------" << std::endl

VardinisTetraedras3D::VardinisTetraedras3D(char *name, char *info, VardinisTaskas3D *p1, VardinisTaskas3D *p2, VardinisTaskas3D *p3, VardinisTaskas3D *p4) {
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

    this->nodes.push_back(new VardinisTaskas3D(*p1));
    this->nodes.push_back(new VardinisTaskas3D(*p2));
    this->nodes.push_back(new VardinisTaskas3D(*p3));
    this->nodes.push_back(new VardinisTaskas3D(*p4));
}

VardinisTetraedras3D::VardinisTetraedras3D(VardinisTetraedras3D & copy) {
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

    for (int i = 0; i < 4; i++) {
        this->nodes.push_back(new VardinisTaskas3D(*copy.getNode(i)));
    }
}

void VardinisTetraedras3D::printEverything() {
    std::cout << "Tetraedro informacija: " << std::endl;
    SEPARATOR;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Info: " << this->info << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "----POINTS----" << std::endl;
        std::cout << "Name: " << nodes.at(i)->getName() << std::endl;
        std::cout << "Info: " << nodes.at(i)->getInfo() << std::endl;
        std::cout << "Coordinates: "; nodes.at(i)->rodykKoordinates();

    }
}

void VardinisTetraedras3D::setName(char *newName) {
    if( this->name != nullptr ) delete[] this->name;
    int l = strlen(newName);
    this->name = new char[l+1];
    strcpy(this->name, newName);
}

void VardinisTetraedras3D::setInfo(char *newInfo) {
    if( this->info != nullptr ) delete[] this->info;
    int l = strlen(newInfo);
    this->info = new char[l+1];
    strcpy(this->info, newInfo);
}

void VardinisTetraedras3D::setNode(VardinisTaskas3D *newNode, int n) {
    if ((n >= 0) && (n < 4)) {
        if (this->nodes.at(n) != nullptr) {
            delete this->nodes.at(n);
            this->nodes.at(n) = new VardinisTaskas3D(*newNode);
        }    
    }
}

char* VardinisTetraedras3D::getName() {
    return this->name;
}

char* VardinisTetraedras3D::getInfo() {
    return this->info;
}

VardinisTaskas3D* VardinisTetraedras3D::getNode(int n) {
    return this->nodes.at(n);
}

VardinisTaskas3D* VardinisTetraedras3D::getCenter() {
    double sumX = 0, sumY = 0, sumZ = 0;
    
    for (int i = 0; i < 4; i++) {
        sumX += this->nodes.at(i)->getX();
        sumY += this->nodes.at(i)->getY();
        sumZ += this->nodes.at(i)->getZ();
    }

    return (new VardinisTaskas3D("Z", "Centroid of tetrahedron", (double)(sumX/4), (double)(sumY/4), (double)(sumZ/4)));
}

double VardinisTetraedras3D::getVertexLength() {
    return this->nodes.at(0)->atstumasIkiKito(*(this->nodes.at(1)));
}

double VardinisTetraedras3D::calculateTetrahedronSurfaceArea() {
    return (sqrt(3) * pow(this->getVertexLength(), 2));
}

double VardinisTetraedras3D::calculateTetrahedronVolume() {
    return (pow(this->getVertexLength(), 3) / (6 * sqrt(2)));
}

double VardinisTetraedras3D::calculateTetrahedronHeight() {
    return (sqrt((double)2/3) * this->getVertexLength());
}

double VardinisTetraedras3D::distanceToOther(VardinisTetraedras3D &other) {
    double dx = this->getCenter()->getX() - other.getCenter()->getX();
    double dy = this->getCenter()->getY() - other.getCenter()->getY();
    double dz = this->getCenter()->getZ() - other.getCenter()->getZ();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

VardinisTetraedras3D::~VardinisTetraedras3D() {
    if (this->name != nullptr) {
        delete[] this->name;
    }
    if (this->info != nullptr) {
        delete[] this->info;
    }

    this->nodes.clear();
}
