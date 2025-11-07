#include <iostream>
#include <vector>
using namespace std;

bool comparator(const pair<vector<int>, int>& a, const pair<vector<int>, int>& b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

void Merge(vector<pair<vector<int>, int>>& arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<pair<vector<int>, int>> L(n1), R(n2);
    for(int i=0; i<n1; i++){
        L[i] = arr[l + i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i=0; int j=0; int k=l;

    while(i<n1 && j<n2){
        if(comparator(L[i], R[j])){
            arr[k++] = L[i++];
        } else {
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

void MergeSort(vector<pair<vector<int>, int>>& arr, int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid+1, r);
        Merge(arr, l, mid, r);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<vector<int>, int>> arr;
    for(int i=0; i<n; i++){
        int sum = 0;
        vector<int> vec;
        for(int j=0; j<m; j++){
            int el;
            cin >> el;
            sum+=el;
            vec.push_back(el);
        }
        arr.push_back({vec, sum});
    }
    MergeSort(arr, 0, arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].first.size(); j++){
            cout << arr[i].first[j] << " ";
        }
        cout << endl;
    }
    return 0;
}