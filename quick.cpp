#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
    quickSort(arr, 0, N - 1);
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

