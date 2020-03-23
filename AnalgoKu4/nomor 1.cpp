/*
Nama Program		: Merge-Sort
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 23 Maret 2020
Deskripsi Program	: Koding program berisi merge sort dalam bahasa C++
*/

#include <iostream>
using namespace std;

int a[50];

void merge(int low,int mid,int high){
	int h,i,j,b[50],k;
	h=low;
	i=low;
	j=mid+1;
	while((h<=mid)&&(j<=high)){
		if(a[h]<=a[j]){
			b[i]=a[h]; h++;
		}
		else{
			b[i]=a[j]; j++;
		}
		i++;
	}
	
 	if(h>mid){
		for(k=j;k<=high;k++){
			b[i]=a[k]; i++;
		}
	}
	else{
		for(k=h;k<=mid;k++){
			b[i]=a[k]; i++;
		}
	}
	for(k=low;k<=high;k++)
		a[k]=b[k];
}

void merge_sort(int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}

int main(){
	int num,i;

	cout<<"Masukkan jumlah elemen yang akan diurutkan: ";cin >> num;
	cout<<endl;

	for(i=1;i<=num;i++){
		cout<<"Elemen "<<i<<" :";cin>>a[i] ;
	}
	
	merge_sort(1,num);

	cout << "\n-------------------------------------" << endl;
	cout<<"Merge Sort :"<<endl;
	cout<<endl;

	for(i=1;i<=num;i++){
		cout<<a[i]<<" ";
		cout<<endl<<endl<<endl<<endl;
	}
}
