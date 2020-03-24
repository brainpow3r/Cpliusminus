#include <iostream>
#include <string.h>
#include <math.h>
#include "VardinisTrikampis3D.h"

#define SEPARATOR std::cout << "-----------------------------" << std::endl

VardinisTrikampis3D::VardinisTrikampis3D(char *name, char *info, VardinisTaskas3D first, 
                                        VardinisTaskas3D second, VardinisTaskas3D third) {

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

    this->a = new VardinisTaskas3D(first);
    this->b = new VardinisTaskas3D(second);
    this->c = new VardinisTaskas3D(third);
    
    // calculate coordinates for center point
    double x = (double)((a->getX() + b->getX() + c->getX()) / 3);
    double y = (double)((a->getY() + b->getY() + c->getY()) / 3);
    double z = (double)((a->getZ() + b->getZ() + c->getZ()) / 3);
    this->center = new VardinisTaskas3D("CP", "Center Point", x, y, z);
}

VardinisTrikampis3D::VardinisTrikampis3D(VardinisTrikampis3D &copy) {
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

    this->a = new VardinisTaskas3D(*copy.getPoint(0));
    this->b = new VardinisTaskas3D(*copy.getPoint(1));
    this->c = new VardinisTaskas3D(*copy.getPoint(2));
    this->center = new VardinisTaskas3D(*copy.getPoint(3));
}

void VardinisTrikampis3D::setName(char *newName) {
    if( this->name != nullptr ) delete[] this->name;     
    int l = strlen(newName);
    this->name = new char[l+1];
    strcpy(this->name, newName);
}

void VardinisTrikampis3D::setInfo(char *newInfo) {
    if( this->info != nullptr ) delete[] this->info;     
    int l = strlen(newInfo);
    this->info = new char[l+1];
    strcpy(this->name, newInfo);
}

void VardinisTrikampis3D::setPoint(VardinisTaskas3D *newPoint, int choice) {
    switch(choice) {
        case 1:
            if (this->a != nullptr) delete this->a;
            this->a = new VardinisTaskas3D(*newPoint);
            break;
        case 2:
            if (this->b != nullptr) delete this->b;
            this->b = new VardinisTaskas3D(*newPoint);
            break;
        case 3:
            if (this->c != nullptr) delete this->c;
            this->c = new VardinisTaskas3D(*newPoint);
            break;
        default:
            std::cout << "Nera tasko su tokiu indeksu trikampyje!" << std::endl;
            break;
    }
}

char *VardinisTrikampis3D::getName() {
    return this->name;
}

char *VardinisTrikampis3D::getInfo() {
    return this->info;
}

VardinisTaskas3D *VardinisTrikampis3D::getPoint(int choice) {
    switch(choice) {
        case 0:
            return this->a;
            break;
        case 1:
            return this->b;
            break;
        case 2:
            return this->c;
            break;
        case 3:
            return this->center;
            break;
        default:
            return nullptr;
            break;
    }
}

VardinisTaskas3D *VardinisTrikampis3D::getCenterPoint() {
    return this->center;    
}

void VardinisTrikampis3D::printEverything() {
    std::cout << "Trikampio informacija: " << std::endl;
    SEPARATOR;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Info: " << this->info << std::endl;
    std::cout << "Taskai: " << std::endl;
    this->a->rodykTaska();
    this->b->rodykTaska();
    this->c->rodykTaska();
}

void VardinisTrikampis3D::vertexLengths() {
    double l1 = this->a->atstumasIkiKito(*b);
    double l2 = this->b->atstumasIkiKito(*c);
    double l3 = this->c->atstumasIkiKito(*a);

    std::cout << "Atstumai: " << std::endl;
    std::cout << "Tarp " << this->a->getName() << " ir " << this->b->getName() << ": " << l1 << std::endl;
    std::cout << "Tarp " << this->b->getName() << " ir " << this->c->getName() << ": " << l2 << std::endl;
    std::cout << "Tarp " << this->c->getName() << " ir " << this->a->getName() << ": " << l3 << std::endl;
}

double VardinisTrikampis3D::calculatePerimeter() {
    return (this->a->atstumasIkiKito(*b) + this->b->atstumasIkiKito(*c) + this->c->atstumasIkiKito(*a));
}

double VardinisTrikampis3D::calculateArea() {
    double p = calculatePerimeter() / 2;
    double l1 = this->a->atstumasIkiKito(*b);
    double l2 = this->b->atstumasIkiKito(*c);
    double l3 = this->c->atstumasIkiKito(*a);

    return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}

double VardinisTrikampis3D::distanceToAnother(VardinisTrikampis3D &other) {
    double dx = this->center->getX() - other.getCenterPoint()->getX();
    double dy = this->center->getY() - other.getCenterPoint()->getY();
    double dz = this->center->getZ() - other.getCenterPoint()->getZ();
    return sqrt(dx*dx + dy*dy + dz*dz);
}

VardinisTrikampis3D::~VardinisTrikampis3D() {
    if (this->name != nullptr) delete[] this->name;
    if (this->info != nullptr) delete[] this->info;

    if (this->a != nullptr) delete this->a;
    if (this->b != nullptr) delete this->b;
    if (this->c != nullptr) delete this->c;
}