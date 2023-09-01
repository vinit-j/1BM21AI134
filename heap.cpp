#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    heapSort(arr, N);
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

