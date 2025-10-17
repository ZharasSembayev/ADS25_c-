#include <iostream>
#include <vector>
using namespace std;

void bubblesort(string& s){
    int n = s.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(s[j] > s[j+1]){
                swap(s[j], s[j+1]);
            }
        }
    }
}

int main(){
    string s;
    cin >> s;
    bubblesort(s);
    cout << s << endl;
    return 0;
}