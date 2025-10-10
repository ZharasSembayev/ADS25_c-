#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    public:
    vector <int> v;
    int p(int i){
        return (i-1) / 2;
    }
    int left (int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    int getMax(){
        return v[0];
    }

    void insert(int k){
        v.push_back(k);
        int i = v.size() - 1;
        while (i > 0 && v[i] > v[p(i)]){
            swap(v[i], v[p(i)]);
            i = p(i);
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i), large = i;
        if (l < v.size() && v[l] > v[large]){
            large = l;
        }
        if (r < v.size() && v[r] > v[large]){
            large = r;
        }
        if(large != i){
            swap(v[i], v[large]);
            heapify(large);
        }
    }

    int extractMax(){
        int root = getMax();
        swap(v[0], v[v.size() - 1]);
        v.pop_back();
        if (v.size() > 0){
            heapify(0);
        }
        return root;
    }
    int size(){
        return v.size();
    }
    bool empty(){
        return v.empty();
    }
};
int main(){
    int n;
    cin >> n;
    MaxHeap heap;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        heap.insert(x);
    }
    while(heap.size() > 1){
        int x = heap.extractMax();
        int y = heap.extractMax();
        if(x != y){
            heap.insert(x-y);
        }
    }
    if(heap.empty()){
        cout << 0 << endl;
    }
    else {
        cout << heap.getMax() << endl; 
    }
    return 0;
}
