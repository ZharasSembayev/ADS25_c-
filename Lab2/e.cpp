#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> names;
    string s = "";
    for (int i=0; i<n; i++){
        string w;
        cin >> w;
        if (w != s){
            names.push_back(w);
        }
        s = w;
    }
    cout << "All in all: " << names.size() << endl;
    cout << "Students:" << endl;
    
    for(int i=names.size() - 1; i >= 0; i--){
        cout << names[i] << endl;
    }
    return 0;
}