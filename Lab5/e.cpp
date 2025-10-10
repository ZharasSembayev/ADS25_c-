#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MaxHeap{
    public:
    vector<long long> v;
    int p(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    long long getMin(){
        return v[0];
    }
    int size(){
        return v.size();
    }

    void insert(int k){
        v.push_back(k);
        int i = v.size() - 1;
        while(i > 0 && v[i] < v[p(i)]){
            swap(v[i], v[p(i)]);
            i = p(i);
        }
    }
    void heapify(int i){
        int l= left(i), r = right(i), large = i;
        if(l < v.size() && v[l] < v[large]){
            large = l;
        }
        if(r < v.size() && v[r] < v[large]){
            large = r;
        }
        if (large != i){
            swap(v[i], v[large]);
            heapify(large);
        }
    }

    long long extractMin(){
        if(v.empty()){
            return - 1;
        }
        long long root = getMin();
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        if(v.size() > 0){
            heapify(0);
        }
        return root;
    }
};

int main(){
    int n,k;
    cin >> n >> k;
    MaxHeap heap;
    long long t =0;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if (s == "insert"){
            long long x;
            cin >> x;
            if(heap.size() < k){
                heap.insert(x);
                t += x;
            }
            else if(x > heap.getMin()){
                t -= heap.getMin();
                heap.extractMin();
                heap.insert(x);
                t += x;
            }
        } else if (s == "print"){
            cout << t << endl;
        }
    }

    return 0;
}