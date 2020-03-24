#include <math.h>
#include <iostream>
#include <string.h>
#include "VardinisKubas3D.h"

#define SEPARATOR std::cout << "-----------------------------" << std::endl

VardinisKubas3D::VardinisKubas3D(char *name, char *info, VardinisTaskas3D *a, double vertex_length) {

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

    //this->nodes.push_back(*(new VardinisTaskas3D[8]));
    this->vertex_length = vertex_length;
    this->nodes.push_back(new VardinisTaskas3D("L", "Cube's pivot point", a->getX(), a->getY(), a->getZ()));
    this->nodes.push_back(new VardinisTaskas3D("M", "Cube's righ lower base point", a->getX()+vertex_length, a->getY(), a->getZ()));
    this->nodes.push_back(new VardinisTaskas3D("N", "Cube's right higher base point", a->getX()+vertex_length, a->getY(), a->getZ()+vertex_length));
    this->nodes.push_back(new VardinisTaskas3D("O", "Cube's left higher base point", a->getX(), a->getY(), a->getZ()+vertex_length));

    this->nodes.push_back(new VardinisTaskas3D("P", "Cube's left lower top point", a->getX(), a->getY()+vertex_length, a->getZ()));
    this->nodes.push_back(new VardinisTaskas3D("R", "Cube's right lower top point", a->getX()+vertex_length, a->getY()+vertex_length, a->getZ()));
    this->nodes.push_back(new VardinisTaskas3D("S", "Cube's right higher top point", a->getX()+vertex_length, a->getY()+vertex_length, a->getZ()+vertex_length));
    this->nodes.push_back(new VardinisTaskas3D("T", "Cube's left higher top point", a->getX(), a->getY()+vertex_length, a->getZ()+vertex_length));

}

VardinisKubas3D::VardinisKubas3D(VardinisKubas3D &copy) {
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

    for (int i = 0; i < 8; i++) {
        this->nodes.push_back(new VardinisTaskas3D(*copy.getNode(i)));
    }
}

void VardinisKubas3D::printEverything() {
    std::cout << "Kubo informacija: " << std::endl;
    SEPARATOR;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Info: " << this->info << std::endl;
    for (int i = 0; i < 8; i++) {
        std::cout << "----POINTS----" << std::endl;
        std::cout << "Name: " << nodes.at(i)->getName() << std::endl;
        std::cout << "Info: " << nodes.at(i)->getInfo() << std::endl;
        std::cout << "Coordinates: "; nodes.at(i)->rodykKoordinates();

    }
}

void VardinisKubas3D::setName(char *newName) {
    if( this->name != nullptr ) delete[] this->name;
    int l = strlen(newName);
    this->name = new char[l+1];
    strcpy(this->name, newName);
}

void VardinisKubas3D::setInfo(char *newInfo) {
    if( this->info != nullptr ) delete[] this->info;
    int l = strlen(newInfo);
    this->info = new char[l+1];
    strcpy(this->info, newInfo);
}

void VardinisKubas3D::setNewPivotPoint(VardinisTaskas3D *newPoint) {
    this->nodes.clear();
    this->calculateCubePoints(newPoint);
}

char* VardinisKubas3D::getName() {
    return this->name;
}

char* VardinisKubas3D::getInfo() {
    return this->info;
}

VardinisTaskas3D* VardinisKubas3D::getPivotPoint() {
    return this->nodes.at(0);
}

VardinisTaskas3D* VardinisKubas3D::getNode(int n) {
    return this->nodes.at(n);
}

VardinisTaskas3D* VardinisKubas3D::getCubeCenter() {
    double sumX = 0, sumY = 0, sumZ = 0;
    for (int i = 0; i < 8; i++) {
        sumX += this->nodes.at(i)->getX();
        sumY += this->nodes.at(i)->getY();
        sumZ += this->nodes.at(i)->getZ();
    }

    return new VardinisTaskas3D("H", "Cube Center", (double)(sumX/8), (double)(sumY/8), (double)(sumZ/8));
}

double VardinisKubas3D::getVertexLength() {
    return this->nodes.at(0)->atstumasIkiKito(*(this->nodes.at(1)));
}

void VardinisKubas3D::calculateCubePoints(VardinisTaskas3D *a) {
    nodes.push_back(new VardinisTaskas3D("L", "Cube's pivot point", a->getX(), a->getY(), a->getZ()));
    nodes.push_back(new VardinisTaskas3D("M", "Cube's righ lower base point", a->getX()+vertex_length, a->getY(), a->getZ()));
    nodes.push_back(new VardinisTaskas3D("N", "Cube's right higher base point", a->getX()+vertex_length, a->getY(), a->getZ()+vertex_length));
    nodes.push_back(new VardinisTaskas3D("O", "Cube's left higher base point", a->getX(), a->getY(), a->getZ()+vertex_length));

    nodes.push_back(new VardinisTaskas3D("P", "Cube's left lower top point", a->getX(), a->getY()+vertex_length, a->getZ()));
    nodes.push_back(new VardinisTaskas3D("R", "Cube's right lower top point", a->getX()+vertex_length, a->getY()+vertex_length, a->getZ()));
    nodes.push_back(new VardinisTaskas3D("S", "Cube's right higher top point", a->getX()+vertex_length, a->getY()+vertex_length, a->getZ()+vertex_length));
    nodes.push_back(new VardinisTaskas3D("T", "Cube's left higher top point", a->getX(), a->getY()+vertex_length, a->getZ()+vertex_length));
}

void VardinisKubas3D::setNewVertexLength(double newVertexLength) {
    nodes.erase(nodes.begin()+1, nodes.begin()+8);

    this->vertex_length = newVertexLength;
    this->calculateCubePoints(nodes.at(0));
}

double VardinisKubas3D::calculateCubeArea() {
    double vertex_length = this->nodes.at(0)->atstumasIkiKito(*(nodes.at(1)));

    return (8 * (pow(vertex_length, 2)));
}

double VardinisKubas3D::calculateCubeVolume() {
    double vertex_length = this->nodes.at(0)->atstumasIkiKito(*(nodes.at(1)));

    return (pow(vertex_length, 3));
}

double VardinisKubas3D::distanceToOther(VardinisKubas3D &other) {
    double dx = this->getCubeCenter()->getX() - other.getCubeCenter()->getX();
    double dy = this->getCubeCenter()->getY() - other.getCubeCenter()->getY();
    double dz = this->getCubeCenter()->getZ() - other.getCubeCenter()->getZ();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

VardinisKubas3D::~VardinisKubas3D() {
    if (this->name != nullptr) {
        delete[] this->name;
    }
    if (this->info != nullptr) {
        delete[] this->info;
    }

    this->nodes.clear();
}
