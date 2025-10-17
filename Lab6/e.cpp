#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int>& arr, int l, int r){
    int p = arr[(l+r)/2];
    int i=l;
    int j=r;
    while(i<=j){
        while(arr[i]>p){
            i++;
        }
        while(arr[j] < p){
            j--;
        }
        if(i<=j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if(l<j){
        quicksort(arr, l, j);
    }
    if(i<r){
        quicksort(arr, i, r);
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
        cin >> arr[i][j];
        }
    }
    for(int col = 0; col < m; col++){
        vector<int> temp;
        for(int row=0; row<n; row++){
            temp.push_back(arr[row][col]);
        }
        quicksort(temp, 0, n-1);
        for(int row =0; row<n; row++){
            arr[row][col] = temp[row];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}