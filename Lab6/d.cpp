#include <iostream>
#include <vector>
#include <string>
using namespace std;

int convertToNumber(const string &date) {
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));
    return year * 10000 + month * 100 + day;
}

void merge(vector<pair<int, string>>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<pair<int, string>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<pair<int, string>>& arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> dates(n);
    for (int i = 0; i < n; i++) {
        string date;
        cin >> date;
        dates[i] = {convertToNumber(date), date};
    }

    mergeSort(dates, 0, n - 1);

    for (auto &d : dates) {
        cout << d.second << endl;
    }

    return 0;
}
