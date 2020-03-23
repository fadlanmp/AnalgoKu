/*
Nama Program		: Insertion sort 
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 23 Maret 2020
Deskripsi Program	: Koding program untuk algoritma insertion sort dengan menggunakan bahasa C++
*/
#include <iostream>

using namespace std;

int data[100],data2[100],n;

void insertion_sort(){
	int temp,i,j;
	for(i=1;i<=n;i++){
	    temp = data[i];
		j = i -1;
	    while(data[j]>temp && j>=0){
			data[j+1] = data[j];
	   	    j--;
	    }
	    data[j+1] = temp;
	}
}

int main(){
	cout<<"Masukkan jumlah elemen yang mau diurutkan: "; cin>>n;
	cout<<endl;
	
	for(int i=1;i<=n;i++){
	  cout<<"masukkan elemen "<<i<<": ";
	  cin>>data[i];
	  data2[i]=data[i];
	}

	insertion_sort();
	cout<<"\nSorted Data: "<<endl;
	for(int i=1; i<=n; i++){
	  cout<<data[i]<<" ";
	}
}
