#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void quickSort(vector<int>& arr, int l, int r){
    int p = arr[(l+r)/2];
    int i = l;
    int j = r;
    while(i<=j){
        while(arr[i]<p){
            i++;
        }
        while(arr[j]>p){
            j--;
        }
        if(i<=j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quickSort(arr,l, j);
    }
    if(i<r){
        quickSort(arr, i, r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    if(n<2){
        return 0;
    }
    quickSort(arr, 0, n-1);
    int mindiff = abs(arr[1]-arr[0]);
    for(int i=0; i<n-1; i++){
        mindiff = min(mindiff, abs(arr[i+1] - arr[i]));
    }
    for(int i=0; i<n-1; i++){
        if(abs(arr[i+1]- arr[i]) == mindiff){
            cout << arr[i] << " " << arr[i+1] << " ";
        }
    }
    cout << endl;
    return 0;
}