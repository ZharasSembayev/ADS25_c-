#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string vowels = "";
    string consonants = ""; 
    string v ="aeiou";

    for (char c : s){
        if (v.find(c)!=string::npos){
            vowels += c;
        } else {
           consonants += c;
        }
    }
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());
    cout << vowels + consonants << endl;
    return 0;
}