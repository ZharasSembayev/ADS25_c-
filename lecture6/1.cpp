#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Merge(vector<string>& arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<string> L(n1), R(n2);
    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid + 1 + j];
    }
    int i=0;
    int j=0;
    int k = l;
    while(i<n1 && j < n2){
        if(L[i].size() <= R[j].size()){
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1){
        arr[k++] = L[i++];
    }
    while(j<n2){
        arr[k++] = R[j++];
    }
}

void MergeSort(vector<string>& arr, int l, int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l , mid, r);
    }
}

int main(){
    int T;
    cin >> T;
    cin.ignore();
    for(int i=0; i<T; i++){
        string s;
        getline(cin, s);
        s += ' ';
        vector<string> vec;
        string ss = "";
        for(int j=0; j<s.length(); j++){
            if(s[j] == ' '){
                vec.push_back(ss);
                ss = "";
            } else {
                ss += s[j];
            }
        }
        MergeSort(vec, 0, vec.size()-1);
        for(int k=0; k<vec.size(); k++){
            cout << vec[k] << " ";
        }
        cout << endl;
    }
    return 0;
}