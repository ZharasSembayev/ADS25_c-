#include <iostream>
#include <vector>
using namespace std;

int v[1000];
void quicksort(int l, int r){
    int p = v[(l+r)/2];
    int i = l;
    int j = r;
    while(i<j){
        while(v[i]<p){
            i++;
        }
        while(v[j]>p){
            j--;
        }
        if(i<=j){
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(l, j);
    }
    if(i <r){
        quicksort(i ,r);
    }
}