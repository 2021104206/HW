//method 1
#include <iostream>
#include<fstream>
using namespace std;

int multiplex(int ii) {
	ii *= 5;
	return ii;
}

float square(float jj) {
	jj = pow(jj, 2);
	return jj;
}

int main() {
	ofstream xx;
	int a = 1234, b;
	float c;
	xx.open("data.bin", ios::binary | ios::out);
	if (!xx) return 6;
	xx.write((char*)&a, 4);
	for (int i = 1000; i <= 5000; i = i + 1000) {
		b = multiplex(i);
		xx.write((char*)&b, sizeof(int));
	}
	for (float i = -0.5; i <= 0.5; i = i + 0.5) {
		c = square(i);
		xx.write((char*)&c, sizeof(float));
	}

	xx.close();

	ifstream yy;
	yy.open("data.bin", ios::binary | ios::in);
	if (!yy) return 66;
	int q, w[5];
	float e[3];

	yy.read((char*)&q, sizeof(int));
	yy.read((char*)w, sizeof(int) * 5);
	yy.read((char*)e, sizeof(float) * 3);
	cout << q << endl;
	for (auto i : w) {
		cout << i << endl;
	}
	for (auto i : e) {
		cout << i << endl;
	}
	yy.close();

	return 1;
}