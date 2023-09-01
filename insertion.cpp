#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));

    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int arr[N];
    cout << "Choose an option:\n";
    cout << "1. Manual entry of array elements\n";
    cout << "2. Random number generation for array elements\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter " << N << " array elements:\n";
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
    } else if (choice == 2) {
        cout << "Array elements generated randomly.\n";
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000; // Adjust the range as needed
        }
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    clock_t startTime = clock();
    insertionSort(arr, N);
    clock_t endTime = clock();

    cout << "Sorted array:\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken: " << timeTaken << " seconds\n";

    return 0;
}
