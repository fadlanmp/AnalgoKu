/*
Nama Program		: Selection sort 
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 23 Maret 2020
Deskripsi Program	: Koding program untuk algoritma selection sort dengan menggunakan bahasa C++
*/

#include <iostream>

using namespace std;

int main(){
	int arr[100],n,temp;
	cout<<" Masukkan jumlah elemen yang mau diurutkan:: ";cin>>n;

	for(int i=0;i<n;++i){
		cout<<"Masukkan elemen "<<i+1<<" : ";cin>>arr[i];
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<(n-1);j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	cout<<"\nSorted Data: "<<endl;
	for(int i=0;i<n;i++){
		cout<<" "<<arr[i];
	}	
}
