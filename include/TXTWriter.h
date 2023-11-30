#include "Includes.h"

using namespace std;

class TXTWriter {
public:
	ofstream TXTFile;

	TXTWriter() {}

	void createTXTFile() {
		TXTFile.open("generated-files/pista.txt");
	}

	void addPoint(float x, float y, float z){	
		TXTFile << "v " << x << " " << z << " " << y << endl;
	}

	void closeTXTFile() {
		TXTFile.close();
	}
};