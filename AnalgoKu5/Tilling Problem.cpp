/*
Nama Program		: Tilling Problem
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 30 Maret 2020
Deskripsi Program	: program untuk menyelesaikan problem tilling menggunakan algoritma divide & conquer yang diberikan dengan bahasa C++
*/

#include <iostream>   
using namespace std; 
  
int countWays(int n, int m){ 
	int count[n + 1]; 
	count[0] = 0;      

	for (int i = 1; i <= n; i++) { 
		// recurrence relation 
		if (i > m) {
			count[i] = count[i - 1] + count[i - m]; 
		} 
		else if (i < m){
			count[i] = 1; 
		} 
		else{
			count[i] = 2; 
		}
	}
    return count[n]; 
} 

int main(){
	int n = 4, m = 2; 
    cout << "Number of ways = " << countWays(n, m); 
	return 0; 
}