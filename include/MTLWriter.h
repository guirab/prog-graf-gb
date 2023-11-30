#include "Includes.h"

using namespace std;

class MTLWriter {
public:
	MTLWriter() {}

	static void createMTLFile() {
		static ofstream mtlFile;
		mtlFile.open("generated-files/pista.mtl");
		mtlFile << "newmtl " << "road\n" << endl;
		mtlFile << "Kd " << 1.0 << " " << 0.5 << " " << 0 << endl;
		mtlFile << "Ka " << 1.0 << " " << 1.0 << " " << 1.0 << endl;
		mtlFile << "Tf " << 1.0 << " " << 1.0 << " " << 1.0 << endl;
		mtlFile << "map_Kd " << "textures/road.png" << endl;
		mtlFile << "Ni " << 1.0 << endl;
		mtlFile << "Ns " << 100.0 << endl;
		mtlFile << "Ks " << 1.0 << " " << 1.0 << " " << 1.0 << endl;
		mtlFile.close();
	}
};