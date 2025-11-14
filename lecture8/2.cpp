#include <iostream>
#include <vector>
#include <map>
using namespace std;

int get_hash(string s){
    int p = 29;
    int p_pow = 1;
    int h = 0;

    for(int i=0; i<s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main(){
    int n;
    cin >> n;
    vector<int> strings(n);
    map<int, vector<int>> hash_map;
    for(int i=0; i<n; i++){
        cin >> strings[i];
        int h = get_hash(strings[i]);
        hash_map[h].push_back(i);
    }
    for(auto& pair : hash_map){
        vector<int>& indx = pair.second;
        for(int i=0; i<indx.size(); i++){
            for(int j=i+1; j<indx.size(); j++){
                if(strings[i] == strings[j]){
                    cout << indx[i] << " " indx[j] << endl;
                }
            }
        }
    }
    return 0;
}