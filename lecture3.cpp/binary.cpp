#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int>& arr, int x){
    int l = 0; int r = arr.size() - 1;
    while(l<=r){
        int mid =  l+ (r-l)/2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] < x){
            l = mid + 1;
        } else {
            r = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 7;
    int i = binarysearch(arr, x);
    cout << i << endl;
    return 0;
}