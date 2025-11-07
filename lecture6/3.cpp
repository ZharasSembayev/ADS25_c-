#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int>& arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> L(n1), R(n2);
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i=0; int j=0; int k=l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k++] = L[i++];
        } else{
            arr[k++] = R[j++];
        }
    }
    while(i<n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
}

void MergeSort(vector<int>& arr, int l, int r){
    if(l<r){
        int mid = l + (r-l) / 2;
        MergeSort(arr , l, mid);
        MergeSort(arr, mid+1, r);
        Merge(arr, l , mid ,r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int el;
        cin>>el;
        arr.push_back(el);
    }
    vector<int> arr2;
    for(int i=0; i<m; i++){
        int el;
        cin >> el;
        arr2.push_back(el);
    }
    vector<int> c;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr2.size(); j++){
            if(arr2[j] == arr[i]){
                c.push_back(arr[i]);
                break;
            }
        }
    }
    MergeSort(c, 0, c.size()-1);
    for(int i=0; i<c.size(); i++){
        cout << c[i] << " ";
    }
    return 0;
}