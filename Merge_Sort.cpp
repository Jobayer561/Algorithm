#include <bits/stdc++.h>
using namespace std;
void merging(int a[], int b[], int low, int mid, int high)
{
    int l1, l2, i;
    for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if (a[l1] <= a[l2])
        {
            b[i] = a[l1++];
        }
        else
        {
            b[i] = a[l2++];
        }
    }
    while (l1 <= mid)
        b[i++] = a[l1++];
    while (l2 <= high)
        b[i++] = a[l2++];
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int a[], int b[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        sort(a, b, low, mid);
        sort(a, b, mid + 1, high);
        merging(a, b, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n], b[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\nArray before sorting\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    sort(a, b, 0, n - 1);

    cout << "\nArray after sorting\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
