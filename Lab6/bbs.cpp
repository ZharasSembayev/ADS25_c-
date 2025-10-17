#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j = 0; j< n-i-1; j++){
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
    cout << endl;
}

int main(){
    vector<int> arr = {64,34,25,12, 22, 11, 90};
    cout << "Original array: ";
    print(arr);
    bubbleSort(arr);

    cout << "Sorted arr: ";
    print(arr);
    return 0;
}
