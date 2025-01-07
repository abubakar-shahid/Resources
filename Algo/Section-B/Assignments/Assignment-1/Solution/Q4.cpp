#include <iostream>

using namespace std;

int findPeakEntry(int A[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (A[mid] < A[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* A = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    int peakEntry = findPeakEntry(A, n);
    cout << "The peak entry is at index: " << peakEntry << endl;

    delete[] A;
    return 0;
}