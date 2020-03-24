#include "VardineAtkarpa3D.h"
#include <iostream>
#include <string.h>

VardineAtkarpa3D::VardineAtkarpa3D(char* name, char* info, double xStart, double yStart, double zStart, double xEnd, double yEnd, double zEnd) {
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

    if ((name != nullptr) && (info != nullptr)) {
        int lname = strlen(name);
        char *start_name = new char[lname+7];
        char *end_name = new char[lname+5];
        strcpy(start_name, this->name);
        strcpy(end_name, this->name);
        strcat(start_name, "_START");
        strcat(end_name, "_END");

        start = new VardinisTaskas3D(start_name, "Pradzios taskas", xStart, yStart, zStart);
        end = new VardinisTaskas3D(end_name, "Pabaigos taskas", xEnd, yEnd, zEnd);
        midpoint = this->vidurioTaskas();
    } else {
        start = new VardinisTaskas3D("Pradzia", "Pradzios taskas", xStart, yStart, zStart);
        end = new VardinisTaskas3D("Pabaiga", "pabaigos taskas", xEnd, yEnd, zEnd);
        midpoint = this->vidurioTaskas();
    }

    this->length = start->atstumasIkiKito(*end);
}

VardineAtkarpa3D::VardineAtkarpa3D(char* name, char* info, VardinisTaskas3D *a, VardinisTaskas3D *b) {

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

    start = new VardinisTaskas3D(a->getName(), "Pradzios taskas", a->getX(), a->getY(), a->getZ());
    end = new VardinisTaskas3D(b->getName(), "Pabaigos taskas", b->getX(), b->getY(), b->getZ());
    midpoint = this->vidurioTaskas();

    this->length = a->atstumasIkiKito(*b);
}

VardineAtkarpa3D::VardineAtkarpa3D(VardineAtkarpa3D &copy) {
    if( copy.getName() != nullptr ){
          int l1 = strlen(copy.getName());
          this->name = new char[l1+1];
          strcpy(this->name, copy.getName());
     } else
          this->name = nullptr;
     if( copy.getInfo() != nullptr ){
          int l2 = strlen(copy.getInfo());
          this->info = new char[l2+1];
          strcpy(this->info, copy.getInfo());
     } else
          this->info = nullptr;

    this->start = new VardinisTaskas3D(*copy.getStartpoint());
    this->end = new VardinisTaskas3D(*copy.getEndpoint());
    this->midpoint = this->vidurioTaskas();
    this->length = start->atstumasIkiKito(*end);
}

void VardineAtkarpa3D::printEverything() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Info: " << this->info << std::endl;
    std::cout << "--------------" << std::endl;
    std::cout << "Start point: ";
    std::cout << std::endl;
    start->rodykTaska();
    std::cout << "--------------" << std::endl;
    std::cout << "End point: ";
    std::cout << std::endl;
    end->rodykTaska();
    std::cout << "--------------" << std::endl;
    std::cout << "Middle point: ";
    std::cout << std::endl;
    midpoint->rodykTaska();
    std::cout << "--------------" << std::endl;
    std::cout << "Line length: " << this->length << std::endl;
}

VardinisTaskas3D *VardineAtkarpa3D::vidurioTaskas() {
    if (start != nullptr && end != nullptr) {
        double x_vid = (start->getX() + end->getX()) / 2;
        double y_vid = (start->getY() + end->getY()) / 2;
        double z_vid = (start->getZ() + end->getZ()) / 2;

        VardinisTaskas3D *vidurys = new VardinisTaskas3D("VID", "Vidurys", x_vid, y_vid, z_vid);
        return vidurys;
    } else {
        return nullptr;
    }
}

double VardineAtkarpa3D::atstumasIkiKitosAtkarpos(VardineAtkarpa3D &other) {
    return (this->midpoint->atstumasIkiKito(*other.midpoint));
}

double VardineAtkarpa3D::getLength() {
    return this->length;
}

char *VardineAtkarpa3D::getName() {
    return this->name;
}

char *VardineAtkarpa3D::getInfo() {
    return this->info;
}

VardinisTaskas3D *VardineAtkarpa3D::getStartpoint() {
    return this->start;
}

VardinisTaskas3D *VardineAtkarpa3D::getEndpoint() {
    return this->end;
}

void VardineAtkarpa3D::setInfo(const char *newInfo) {
    if( this->info != nullptr ) delete[] this->info;
    int l = strlen(newInfo);
    this->info = new char[l+1];
    strcpy(this->info, newInfo);
}

void VardineAtkarpa3D::setName(const char *newName) {
    if( this->name != nullptr ) delete[] this->name;
    int l = strlen(newName);
    this->name = new char[l+1];
    strcpy(this->name, newName);
}

void VardineAtkarpa3D::setStartpoint(VardinisTaskas3D newStartpoint) {
    if (this->start != nullptr) delete this->start;
    start = new VardinisTaskas3D(newStartpoint);
}

void VardineAtkarpa3D::setEndpoint(VardinisTaskas3D newEndpoint) {
    if (this->end != nullptr) delete this->end;
    end = new VardinisTaskas3D(newEndpoint);
}

VardineAtkarpa3D::~VardineAtkarpa3D() {
    if (this->name != nullptr) {
        delete[] this->name;
    }
    if (this->info != nullptr) {
        delete[] this->info;
    }

    if (this->start != nullptr) delete start;
    if (this->end != nullptr) delete end;
}


