#include <iostream>
#include<fstream>
using namespace std;

void multiplex(int* aa) {
	int j = 0;
	for (int i = 1000; i <= 5000; i = i + 1000, j++) {
		aa[j] = i * 5;
	}
	return;
}

void square(float* aa) {
	int j = 0;
	for (float i = -0.5; i <= 0.5; i = i + 0.5, j++) {
		aa[j] = i * i;
	}
	return;
}

int main() {
	ofstream xx;
	int a = 1234;

	xx.open("data.bin", ios::binary | ios::out);
	if (!xx) return 6;
	xx.write((char*)&a, 4);

	int b[5];
	float c[3];


	multiplex(b);
	square(c);

	xx.write((char*)&b, sizeof(b));
	xx.write((char*)&c, sizeof(c));
	xx.close();


	ifstream yy;
	yy.open("data.bin", ios::binary | ios::in);
	if (!yy) return 66;

	int d, e[5];
	float f[3];

	yy.read((char*)&d, sizeof(int));
	yy.read((char*)e, sizeof(int) * 5);
	yy.read((char*)f, sizeof(float) * 3);
	cout << d << endl;
	for (auto i : e) {
		cout << i << endl;
	}
	for (auto i : f) {
		cout << i << endl;
	}
	yy.close();

	return 1;

	return 1;
}