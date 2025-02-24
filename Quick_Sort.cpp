#include <iostream>
using namespace std;

int partition(int A[], int start, int end) {
    int pivot = A[end]; 
    int index = start - 1;

    for (int i = start; i < end; i++) {
        if (A[i] <= pivot) {
            index++;
            swap(A[i], A[index]);
        }
    }
    swap(A[index + 1], A[end]);
    return index + 1;
}

void quicksort(int A[], int start, int end) {
    if (start < end) {
        int pivot_index = partition(A, start, end);
        quicksort(A, start, pivot_index - 1);
        quicksort(A, pivot_index + 1, end);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int A[n]; 
    
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    quicksort(A, 0, n - 1); 
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
