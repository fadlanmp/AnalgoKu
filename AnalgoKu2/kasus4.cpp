/*
Nama Program		: Insertion Sort
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 9 Maret 2020
Deskripsi Program	: Berisikan coding program Insertion Sort
*/

#include <iostream>
using namespace std;

//fungsi Insertion Sort Descending

void insertion (int data[]){
	int temp, j;
	for(int i=1; i<6; i++){
		temp = data[i];
		j = i - 1;
		while(data[j]<temp && j>=0){
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = temp;
	}
}

int main(){
	
	//deklarasi variabel
	
	int data [] = {11,10,15,3,20,2};
	cout<<"INSERTION SORT"<<endl;
	cout<<"=============="<<endl;
	cout<<"\nDATA ->\n";
	for(int n = 0; n<6;n++)
		cout<<data[n]<<"\t";
		cout<<endl;
		cout<<"\nDATA SETELAH DIURUTKAN\n";
		cout<<"------------------------\n";
		insertion(data);
		for(int x = 0; x<6;x++)
            cout<<data[x]<<"\t";
			cout<<endl;
}
