#include <iostream>
#include <vector>
using namespace std;


long long binpow(long long a, long long b){
    long long res = 1;
    while(b>0){
        if(b % 2 == 1){
            res *= a;
        }
        a *= a;
        b/=2;
    }
    return res;
}
// Sieve of Eratosthenes:
void sieve(int n){
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;
    for(int i=2; i*i<=n; i++){
        if(isprime[i]){
            for(int j = i*i; j<=n; j+=i){
                isprime[j] = false;
            }
        }

    }
    cout << "Prime nums up to " << n << ": ";
    for(int i=2; i<=n; i++){
        if(isprime[i]){
            cout << i << " ";
        }
    }
}
void primeFactor(int n){
    for(int i=2; i*i<=n; i++){
        while(n%2 == 0){
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1){
        cout << n << endl;
    }
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
    return 0;
}

