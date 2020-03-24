#include <iostream>
#include "VardineAtkarpa3D.h"
#include "VardinisKubas3D.h"
#include "VardineSfera3D.h"

class Galvakunis {
	private:
		char *name;
		char *info;
		VardineSfera3D *head;
		VardinisKubas3D *body;
	public:
		Galvakunis();
		Galvakunis(char *name, char *info, VardinisTaskas3D *p1, double cubeHeight, double radius);

		void printEverything();

		double getTuris();
		double getPlotas();


		~Galvakunis();
};
