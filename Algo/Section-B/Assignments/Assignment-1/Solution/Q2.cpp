#include <iostream>

using namespace std;

int countTails(char* tosses, int n) {
    int low = 0;
    int high = n - 1;
    int tailIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (tosses[mid] == 'T') {
            tailIndex = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (tailIndex == -1)
        return 0;

    return tailIndex + 1;
}

int main() {
    int n;
    cout << "Enter the number of tosses: ";
    cin >> n;

    char* tosses = new char[n];
    cout << "Enter the toss results (H for head, T for tail): ";
    for (int i = 0; i < n; ++i) {
        cin >> tosses[i];
    }

    int tailCount = countTails(tosses, n);
    cout << "Number of occurrences of tail: " << tailCount << endl;

    delete[] tosses;

    return 0;
}