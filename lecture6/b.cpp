#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> & arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        bool swapped = false;
        for(int j=0; j<n; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }

}

void print(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    bubbleSort(arr);
    print(arr);
}