#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class HeapSort {
public:
    HeapSort(int n) : N(n) {
        arr = new int[N];
    }

    ~HeapSort() {
        delete[] arr;
    }

    void inputArray() {
        cout << "Enter " << N << " array elements:\n";
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
    }

    void generateRandomArray() {
        cout << "Array elements generated randomly.\n";
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000; // Adjust the range as needed
        }
    }

    void sort() {
        for (int i = N / 2 - 1; i >= 0; i--) {
            heapify(arr, N, i);
        }

        for (int i = N - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void displaySortedArray() {
        cout << "Sorted array:\n";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    double measureTimeTaken() {
        clock_t startTime = clock();
        sort();
        clock_t endTime = clock();
        return double(endTime - startTime) / CLOCKS_PER_SEC;
    }

private:
    int* arr;
    int N;

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
};

int main() {
    srand(time(0));

    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    HeapSort heapSort(N);

    cout << "Choose an option:\n";
    cout << "1. Manual entry of array elements\n";
    cout << "2. Random number generation for array elements\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        heapSort.inputArray();
    } else if (choice == 2) {
        heapSort.generateRandomArray();
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    double timeTaken = heapSort.measureTimeTaken();

    heapSort.displaySortedArray();
    cout << "Time taken: " << timeTaken << " seconds\n";

    return 0;
}
