#include <iostream>

using namespace std;

void sortColors(char* colors, int n) {
    int redPtr = 0;
    int orangePtr = 0;
    int bluePtr = n - 1;

    while (orangePtr <= bluePtr) {
        if (colors[orangePtr] == 'R') {
            char temp = colors[redPtr];
            colors[redPtr] = colors[orangePtr];
            colors[orangePtr] = temp;
            redPtr++;
            orangePtr++;
        } else if (colors[orangePtr] == 'O') {
            orangePtr++;
        } else {
            char temp = colors[orangePtr];
            colors[orangePtr] = colors[bluePtr];
            colors[bluePtr] = temp;
            bluePtr--;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    char* colors = new char[n];
    cout << "Enter the colors (R for red, O for orange, B for blue): ";
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    sortColors(colors, n);

    cout << "Sorted colors: ";
    for (int i = 0; i < n; ++i) {
        cout << colors[i] << " ";
    }
    cout << endl;

    delete[] colors;

    return 0;
}