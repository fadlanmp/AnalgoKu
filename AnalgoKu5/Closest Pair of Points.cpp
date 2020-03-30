/*
Nama Program		: Closest Pair of Points
Nama			: Fadlan Mulya Priatna
NPM			: 140810180041
Tanggal Pembuatan	: 30 Maret 2020
Deskripsi Program	: Program untuk menyelesaikan problem closest pair of points menggunakan algoritma divide & conquer yang diberikan dengan bahasa C++
*/

#include <iostream>
#include <cfloat>

using namespace std;

struct point{
    double x, y;
};

int compareX(const void* a, const void* b){
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b){
    point *p1 = (point *)a, *p2 = (point *)b;
    return (p1->y - p2->y);
}

float dist(point p1, point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

 float small_dist(point P[], int n){
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
        }
    }
    return min;
}

float stripClosest(point strip[], int size, float d){
    float min = d;
    for (int i = 0; i < size; ++i){
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j){
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
        }
    }
    return min;
}

float closestUtil(point Px[], point Py[], int n){
    if (n <= 3)
        return small_dist(Px, n);
    int mid = n / 2;
    point midPoint = Px[mid];
    point Pyl[mid + 1];
    point Pyr[n - mid - 1];
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++){
        if (Py[i].x <= midPoint.x)
            Pyl[li++] = Py[i];
        else
            Pyr[ri++] = Py[i];
    }
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
    float d = min(dl, dr);
    point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++){
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
    }
    return min(d, stripClosest(strip, j, d));
}

float closest(point P[], int n){
    point Px[n];
    point Py[n];
    for (int i = 0; i < n; i++){
        Px[i] = P[i];
        Py[i] = P[i];
    }
    qsort(Px, n, sizeof(point), compareX);
    qsort(Py, n, sizeof(point), compareY);
    return closestUtil(Px, Py, n);
}

int main(){
    point P[] = {{2, 5}, {15, 30}, {42, 50}, {5, 2}, {12, 13}, {3, 7}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "Jarak point terdekat adalah : " << closest(P, n);
    return 0;
}
