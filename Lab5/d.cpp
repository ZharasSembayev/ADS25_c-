#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    public:
    vector<int> v;
    int p(int i){
        return (i-1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    int getMin(){
        return v[0];
    }
    int size(){
        return v.size();
    }

    void insert(int k){
        v.push_back(k);
        int i= v.size() - 1;
        while(i > 0 && v[i] < v[p(i)]){
            swap(v[i], v[p(i)]);
            i = p(i);
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i), smallest = i;
        if(l < v.size() && v[l] < v[smallest]){
            smallest = l;
        }
        if(r < v.size() && v[r] < v[smallest]){
            smallest = r;
        }
        if (smallest != i){
            swap(v[i], v[smallest]);
            heapify(smallest);
        }
    }

    int extractMin(){
        if (v.empty()){
            return -1;
        }
        int root = getMin();
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        if(!v.empty()){
            heapify(0);
        }
        return root;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    MinHeap heap;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        heap.insert(x);
    }
    int t = 0; 
    while (heap.size() > 0 && heap.getMin() < m) {
        if (heap.size() < 2) { 
            cout << -1;
            return 0;
        }
        int a = heap.extractMin(); 
        int b = heap.extractMin(); 
        int new_mix = a + 2 * b;  
        heap.insert(new_mix);  
        t++;               
    }

    cout << t;
    return 0;
}