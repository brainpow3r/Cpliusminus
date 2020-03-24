#include "Galvakunis.h"
#include <string.h>

Galvakunis::Galvakunis() {

	this->name = nullptr;
	this->info = nullptr;
	this->head = nullptr;
	this->body = nullptr;

}

Galvakunis::Galvakunis(char *name, char *info, VardinisTaskas3D *p1, double cubeHeight, double sphereRadius) {

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

	if ((p1 != nullptr) && (cubeHeight > 0)) {
		this->body = new VardinisKubas3D("Body", "Object Body", p1, cubeHeight);
	}

	VardinisTaskas3D *temp = this->body->getCubeCenter();
	temp->setY((double)(cubeHeight/2 + sphereRadius));

	if (temp != nullptr) {
		this->head = new VardineSfera3D("Head", "Obj Head", sphereRadius, temp);
	}

	delete temp;

}

void Galvakunis::printEverything() {
	std::cout << "----------OBJECT INFORMATION----------" << std::endl;
	std::cout << "BODY" << std::endl;	
	this->body->getPivotPoint()->rodykTaska();
	std::cout << std::endl;
	std::cout << "HEAD" << std::endl;
	this->head->getCenterPoint()->rodykTaska();
	std::cout <<"Atstumas nuo centro iki centro: " << this->body->getCubeCenter()->atstumasIkiKito( *this->head->getCenterPoint() ) << std::endl;
	std::cout << "Plotas: " << this->getPlotas() << std::endl;
	std::cout << "Turis: " << this->getTuris() << std::endl;
}

double Galvakunis::getPlotas() {

	return (this->body->calculateCubeArea() + this->head->sphereSurfaceArea());

}

double Galvakunis::getTuris() {
	return (this->body->calculateCubeVolume() + this->head->sphereVolume());
}

Galvakunis::~Galvakunis() {
	if (this->name != nullptr) { delete this->name; }
	if (this->info != nullptr) { delete this->info; }
	if (this->head != nullptr) { delete this->head; }
	if (this->body != nullptr) { delete this->body; }
}
