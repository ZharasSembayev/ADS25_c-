#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    stack<int> st;
    vector<int> v1(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && st.top() > v[i]){
            st.pop();
        }
        if (st.empty()){
            v1[i] = -1;
        } else {
            v1[i] = st.top();
        }
        st.push(v[i]);
    }
    for (int i=0; i<n; i++){
        cout << v1[i] << " ";
    }

    return 0;
}