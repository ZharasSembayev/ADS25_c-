#include <iostream>
#include <vector>
using namespace std;

int arr[1000];

void quicksort(int left, int right){
    int p = arr[(left + right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(arr[i] < p){
            i++;
        }
        while(arr[j] > p){
            j--;
        }
        if(i<=j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j){
        quicksort(left , j);
    }
    if (i < right){
        quicksort(i, right);
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    quicksort(0, n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}