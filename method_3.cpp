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

	int b[5];
	float c[3];

	multiplex(b);
	square(c);


	xx.open("data.bin", ios::binary | ios::out);
	if (!xx) return 6;

	float* f;
	int p[9];
	p[0] = a;

	for (int i = 0; i < 5; i++) {
		p[i + 1] = b[i];
	}
	f = (float*)(p + 6);

	for (int i = 0; i < 3; i++) {
		f[i] = c[i];
	}



	xx.write((char*)p, sizeof(p));
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