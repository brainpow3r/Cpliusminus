#include "Galvakunis.h"
#include <vector>

int main() {

	std::vector<Galvakunis*> objects;
	
	VardinisTaskas3D *tmp1 = new VardinisTaskas3D("T", "tmp", 4, 4, 4);

	Galvakunis *t = new Galvakunis("XUj", "KKK", tmp1, 3, 1);
	t->printEverything();

	/*for (int i = 1; i <= 4; i++) {
		VardinisTaskas3D *tmp = new VardinisTaskas3D("T", "tmp", i*2, i*2, i*2);

		objects.push_back(new Galvakunis("O", "Obj", tmp, i, i+1));

		delete tmp;
	}

	for (int i = 1; i < objects.size(); i++) {
		objects.at(i)->printEverything();
		std::cout << std::endl;
	}*/

}
