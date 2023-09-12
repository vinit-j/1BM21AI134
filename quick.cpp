#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class QuickSort {
public:
    QuickSort() {}

    void performSort() {
        srand(time(0));

        cout << "Enter the number of elements: ";
        cin >> N;

        if (N <= 0) {
            cout << "Invalid input. Please enter a positive number of elements." << endl;
            return;
        }

        arr = new int[N];

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
            return;
        }

        clock_t startTime = clock();
        quickSort(0, N - 1);
        clock_t endTime = clock();

        cout << "Sorted array:\n";
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
        cout << "Time taken: " << timeTaken << " seconds\n";

        delete[] arr;
    }

private:
    int *arr;
    int N;

    void quickSort(int low, int high) {
        if (low < high) {
            int pivotIndex = partition(low, high);

            quickSort(low, pivotIndex - 1);
            quickSort(pivotIndex + 1, high);
        }
    }

    int partition(int low, int high) {
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
};

int main() {
    QuickSort sorter;
    sorter.performSort();
    return 0;
}
