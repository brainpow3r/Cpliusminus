#include <iostream>
#include <cstring>
#include <cmath>
#include "VardinisTaskas3D.h"

VardinisTaskas3D::VardinisTaskas3D(char* vardas, char* info, double x, double y, double z):
          x_(x),y_(y),z_(z){
     #ifdef DEBUG
     std::cout << "Konstruktorius veikia ..." << std::endl;
     #endif

     if( vardas != nullptr ){
          int l1 = strlen(vardas);
          this->vardas_ = new char[l1+1];
          strcpy(this->vardas_, vardas);
     } else
          this->vardas_ = nullptr;
     if( info != nullptr ){
          int l2 = strlen(info);
          this->info_ = new char[l2+1];
          strcpy(this->info_, info);
     } else
          this->info_ = nullptr;
}

VardinisTaskas3D::VardinisTaskas3D(VardinisTaskas3D &src) {

     if( src.getName() != nullptr ){
          int l1 = strlen(src.getName());
          this->vardas_ = new char[l1+1];
          strcpy(this->vardas_, src.getName());
     } else
          this->vardas_ = nullptr;
     if( src.getInfo() != nullptr ){
          int l2 = strlen(src.getInfo());
          this->info_ = new char[l2+1];
          strcpy(this->info_, src.getInfo());
     } else
          this->info_ = nullptr;

     x_ = src.getX();
     y_ = src.getY();
     z_ = src.getZ();

}

void VardinisTaskas3D::rodykKoordinates() {
     std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")" << std::endl;
}

void  VardinisTaskas3D::rodykTaska() const{
     if( this->vardas_ != nullptr ){
          std::cout << "Vardas: " << this->vardas_ << std::endl;
     }else
          std::cout << "Vardas: <NEPRSKIRTAS> " <<  std::endl;

     if( this->info_ != nullptr ){
          std::cout << "Info: " << this->info_ << std::endl;
     }else
          std::cout << "Info: <NĖRA DUOMENŲ> " <<  std::endl;
     std::cout << "Koordinatės: (" << this->x_ << ", " << this->y_ << ", " << this->z_ << ")" << std::endl;

}

void VardinisTaskas3D::keiskVarda(const char* naujas){
     if( this->vardas_ != nullptr ) delete[] this->vardas_;
     int l = strlen(naujas);
     this->vardas_ = new char[l+1];
     strcpy(this->vardas_, naujas);
}


void VardinisTaskas3D::keiskInfo(const char* kitas){
     if( this->info_ != nullptr ) delete[] this->info_;
     int l = strlen(kitas);
     this->info_ = new char[l+1];
     strcpy(this->info_, kitas);
}

void VardinisTaskas3D::keiskVieta(const double x, const double y, const double z){
     x_ = x; y_ = y; z_ = z;
}

double VardinisTaskas3D::atstumasIkiKito(const VardinisTaskas3D& kitas) const{
     double dx = this->x_ - kitas.x_;
     double dy = this->y_ - kitas.y_;
     double dz = this->z_ - kitas.z_;
     return sqrt(dx*dx+dy*dy+dz*dz);
}

void VardinisTaskas3D::setX(double newX) {
     x_ = newX;
}

void VardinisTaskas3D::setY(double newY) {
     y_ = newY;
}

void VardinisTaskas3D::setZ(double newZ) {
     z_ = newZ;
}

double VardinisTaskas3D::getX() {
     return x_;
}

double VardinisTaskas3D::getY() {
     return y_;
}

double VardinisTaskas3D::getZ() {
     return z_;
}

char *VardinisTaskas3D::getName() {
     return this->vardas_;
}

char *VardinisTaskas3D::getInfo() {
     return this->info_;
}

VardinisTaskas3D::~VardinisTaskas3D(){
     #ifdef DEBUG
     std::cout << "Destruktorius veikia ..." << std::endl;
     #endif
     if( this->vardas_ != nullptr ) delete[] this->vardas_;
     if( this->info_ != nullptr ) delete[] this->info_;
}
