/*
Nama Program		: Pencarian Nilai Maksimal
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 9 Maret 2020
Deskripsi Program	: Berisikan coding program Pencarian Nilai Maksimal
*/

#include <iostream>
using namespace std;
int main() {
	
	int maksimum, jumlah, i = 2;
	cout << "Masukkan jumlah elemen: ";
	cin >> jumlah;
	int array[jumlah];
	
	for (i = 0; i < jumlah; i ++) {
		cout <<(i+1) <<": ";
		cin >> array[i];
	}
	maksimum = array[0];
	
	for(i = 0; i < jumlah; i++) {
		if (array[i] > maksimum)  {
			maksimum = array[i];
		}
	}
	
	cout << "Nilai maksimum adalah " << maksimum;
}
