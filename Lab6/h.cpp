#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<char>& arr){
    int n = arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<char> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bubble(arr);
    char s;
    cin >> s;
    for(int i=0; i<n; i++){
        if(arr[i] > s){
            cout << arr[i] << endl;
            return 0;
        }
    }
    cout << arr[0];
    return 0;
}