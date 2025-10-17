#include <iostream>
#include <vector>
using namespace std;
int a[1000];

void quickSort(int l, int r){
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;
    while(i < j){
        while(i <= p){
            i++;
        }
        while(j > p){
            j--;
        }
        if (i<=j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j){
        quickSort(l, j);
    }
    if(i < r){
        quickSort(i, r);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    quickSort(0, n -1);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}