#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
    public:
    vector<int> v;

    int parent(int i){
        return (i - 1) / 2;
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

    void insert(int k){
        v.push_back(k);
        int ind = v.size() - 1;
        while (ind > 0 && v[ind] < v[parent(ind)]){
            swap(v[ind], v[parent(ind)]);
            ind = parent(ind);
        } 
    }

    void heapify(int i){
        if (left(i) > v.size() - 1){
            return;
        }
        int j = left(i);
        if(right(i) < v.size() && v[right(i)] < v[left(i)]){
            j = right(i);
        }

        if(v[i] > v[j]){
            swap(v[i], v[j]);
            heapify(j);
        }
    }

    int extractMin() {
        int root = getMin();
        swap(v[0], v[v.size() - 1]);
        v.pop_back();

        if(v.size() > 0){
            heapify(0);
        }
        return root;
    }
};

int main(){
    int n, x;
    cin >> n;
    MinHeap* heap = new MinHeap();
    for(int i=0; i<n; i++){
        cin >> x;
        heap->insert(x);

    }

    for(int i=0; i<n; i++){
        cout << heap->extractMin() << " ";
    }
    return 0;
}