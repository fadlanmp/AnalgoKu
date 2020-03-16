/*
Nama Program		: Stable Matching Problem
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 2 Maret 2020
Deskripsi Program	: Berisikan coding program pencari jodoh
*/

#include<iostream>
using namespace std;
typedef int prefer[5];

struct orang{
    string nama;
    int pasangan;
    int preferences[5];
};
 
orang setDataOrang(string nama, prefer prefers){
	orang org;
	org.nama = nama;
	org.pasangan = -1;
	for(int i = 0; i < 5;i++){
	    org.preferences[i] = prefers[i];
	}
	return org;
}

void stableMatching(orang pria[5], orang wanita[5]){
	bool bebas = true;
	int i=0, j=0, prefSek,prefSuk;
	while(bebas){
		if(wanita[pria[i].preferences[j]].pasangan = -1){
			pria[i].pasangan = pria[i].preferences[j];
			wanita[pria[i].preferences[j]].pasangan = i;
		}
		else{
			int k = 0;
			prefSek = -1; prefSuk = -1;
			while(prefSek == -1 || prefSuk == -1){
				if(i == wanita[pria[i].preferences[j]].preferences[k]){
					prefSuk = k;
				}
				if(wanita[pria[i].preferences[j]].pasangan == wanita[pria[i].preferences[j]].preferences[k]){
					prefSek = k;
				}
				k++;
			}
			if(prefSuk<prefSek){
				pria[wanita[pria[i].preferences[j]].pasangan].pasangan = -1;
				pria[i].pasangan = pria[i].preferences[j];
				wanita[pria[i].preferences[j]].pasangan = i;
			}
			else{
				j++;
				continue;
			}
		}
		bebas = false;
		j=0;
		for(int l = 0; l < 5; l++){
			if(pria[l].pasangan == -1){
				i = l;
				bebas = true;
				break;
			}
		}
	}
}

int main(){
    orang pria[5], wanita[5];
    prefer prefers;

    //Pria
	prefers[0] = 1; prefers[1] = 0; prefers[2] = 3; prefers[3] = 4; prefers[4] = 2;
	pria[0] = setDataOrang("Victor",prefers);
	prefers[0] = 3; prefers[1] = 1; prefers[2] = 0; prefers[3] = 2; prefers[4] = 4;
	pria[1] = setDataOrang("Wyatt",prefers);
	prefers[0] = 1; prefers[1] = 4; prefers[2] = 2; prefers[3] = 3; prefers[4] = 0;
	pria[2] = setDataOrang("Xavier",prefers);
	prefers[0] = 0; prefers[1] = 3; prefers[2] = 2; prefers[3] = 1; prefers[4] = 4;
	pria[3] = setDataOrang("Yancey",prefers);
	prefers[0] = 1; prefers[1] = 3; prefers[2] = 0; prefers[3] = 4; prefers[4] = 2;
	pria[4] = setDataOrang("Zeus",prefers);
 
	//Wanita
	prefers[0] = 4; prefers[1] = 0; prefers[2] = 1; prefers[3] = 3; prefers[4] = 2;
	wanita[0] = setDataOrang("Amy",prefers);
	prefers[0] = 2; prefers[1] = 1; prefers[2] = 3; prefers[3] = 0; prefers[4] = 4;
	wanita[1] = setDataOrang("Bertha",prefers);
	prefers[0] = 1; prefers[1] = 2; prefers[2] = 3; prefers[3] = 4; prefers[4] = 0;
	wanita[2] = setDataOrang("Clare",prefers);
	prefers[0] = 0; prefers[1] = 4; prefers[2] = 3; prefers[3] = 2; prefers[4] = 1;
	wanita[3] = setDataOrang("Diane",prefers);
	prefers[0] = 3; prefers[1] = 1; prefers[2] = 4; prefers[3] = 2; prefers[4] = 0;
	wanita[4] = setDataOrang("Erika",prefers);
 
	stableMatching(pria,wanita);
    cout << "\nHasil Stable Matching :" << endl;
	cout << "-----------------" << endl;
	cout << "| Man \t Woman\t|" << endl;
	cout << "-----------------" << endl;
	
	for(int i = 0; i < 5; i++){
		cout << "|" << pria[i].nama << "\t " << wanita[pria[i].pasangan].nama << "\t|" << endl;
	}
	cout << "-----------------" << endl;
}
