#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>& a, int i, int n) {
    while (true) {
        int largest = i;
        int l = (2 * i) + 1;
        int r = (2 * i) + 2;
        if (l < n && a[l] > a[largest])
            largest = l;

        if (r < n && a[r] > a[largest])
            largest = r;

        if (largest != i) {
            swap(a[i], a[largest]);
            i = largest;
        } else {
            break;
        }
    }
}
void heap_sort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, i, n);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    heap_sort(a);
    for (int x : a)
        cout << x << " ";
    cout << endl;

    return 0;
}
