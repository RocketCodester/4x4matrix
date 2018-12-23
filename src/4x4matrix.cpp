//============================================================================
// Name        : 4x4matrix.cpp
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void multiplyMatrices() {
	int r1 = 4;
	int c1 = 4;
	int r2 = 4;
	int c2 = 4;
	float i[r1 * c1] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
	float j[r2 * c2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	float k[r1 * c2];

	for (int x = 0; x < r1; x++) { // row number of output
		for (int y = 0; y < c2; y++) { // column number of output
			k[c2 * x + y] = 0;
			for (int z = 0; z < c2; z++) { // four elements are added for this output
				k[c2 * x + y] += i[c1 * x + z] * j[r2 * z + y];
			}
		}
	}
	for (int i = 0; i < r1 * c2; i++) {
		cout << k[i] << " ";
	}
}

float* multMatrices(int r1, int c1, int r2, int c2, float i[], float j[]) {
	float prod[r1 * c2];
	for (int x = 0; x < r1; x++) { // row number of output
		for (int y = 0; y < c2; y++) { // column number of output
			prod[c2 * x + y] = 0;
			for (int z = 0; z < c2; z++) { // four elements are added for this output
				prod[c2 * x + y] += i[c1 * x + z] * j[r2 * z + y];
			}
		}
	}
	for (int i = 0; i < r1 * c2; i++) {
		cout << prod[i] << " ";
	}
	return prod;
}

int main() {
	int r1 = 1;
	int c1 = 4;
	int r2 = 4;
	int c2 = 4;
	int r3 = 4;
	int c3 = 3;
	float i[r1*c1] = { 1, 1, 1, 1 };
	float j[r2*c2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	float k[r3*c3] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 };
	multMatrices(1, 4, 4, 4, i, j);
	multMatrices(1, 4, 4, 3, j, k);
}
