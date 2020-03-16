/*
Nama Program		: Selection Sort
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 9 Maret 2020
Deskripsi Program	: Berisikan coding program Selection Sort
*/

#include <iostream>
using namespace std;

//prototype fungsi Selection sort
void SelectionSort(int Array[], const int Size){
	int i, j, kecil,temp;
	for(i=0; i<Size;i++){
		kecil = i;
		for(j=i+1; j<Size; j++ ){
			if (Array[kecil]>Array[j]){
				kecil = j;
			}
		}
		temp = Array[i];
		Array[i] = Array[kecil];
		Array[kecil] = temp;
	}
}

//fungsi utama

int main(){
	//pendeklarasian variabel
	int NumList[8] = {5,34,32,25,75,42,22,2};
     
	//tampilkan data sebelum diurutkan
	cout<<"\t================================"<<endl;
	cout<<"\tPENGURUTAN DENGAN SELECTION SORT"<<endl;
	cout<<"\t================================"<<endl;
	cout<<"Data Sebelum diurutkan : \n";
	for(int d = 0; d <8; d++){
		cout<<NumList[d]<<"\t";
	}
	cout<<"\n\n";
	SelectionSort(NumList, 8);
     
	//tampilkan data setelah diurutkan
	cout<<"Data setelah diurutkan : \n";
	for(int iii = 0; iii<8; iii++)
		cout<<NumList[iii]<<"\t";
}
