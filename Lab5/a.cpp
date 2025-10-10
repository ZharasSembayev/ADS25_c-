#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    public:
    vector<long long> v;
    int p(int i){
        return (i-1) / 2;
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
    bool empty(){
        return v.empty();
    }
    int s(){
        return v.size();
    }
    void insert(long long k){
        v.push_back(k);
        int i = v.size() - 1;
        while(i > 0 && v[i] < v[p(i)]){
            swap(v[i], v[p(i)]);
            i = p(i);
        }
    }
    void heapify(int i){
        int l = left(i), r = right(i), small = i;
        if(l < v.size() && v[l] < v[small]){
            small = l;
        }
        if (r < v.size() && v[r] < v[small]){
            small = r;
        }
        if (small != i){
            swap(v[i], v[small]);
            heapify(small);
        }
    }

    long long extractMin(){
        if(v.empty()){
            return - 1;
        }
        long long root = getMin();
        swap(v[0], v[v.size() - 1]);
        v.pop_back();
        if(!v.empty()){
            heapify(0);
        }
        return root;
    }
};

int main(){
    int n;
    cin >> n;
    MinHeap heap;
    for(int i = 0; i<n; i++){
        long long x;
        cin >> x;
        heap.insert(x);
    }
    long long total_cost = 0;
    while(heap.s() > 1){
        long long x = heap.extractMin();
        long long y = heap.extractMin();
        long long cost = x + y;
        total_cost+= cost;
        heap.insert(cost);
    }
    cout << total_cost << endl;
    return 0;
}