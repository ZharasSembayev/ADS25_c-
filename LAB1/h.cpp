#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n < 2){
        cout << "NO" << endl;
        return 0;
    }
    bool p = true;
    for (int i = 2; i*i <= n; i++){
        if (n % i ==0){
            p = false;
           break;
        }    
    }    
    if(p){
        cout <<"YES"<<endl;
    }
    else{
        cout <<"NO" << endl;
    }
    return 0;
}


