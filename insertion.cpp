#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class InsertionSort {
public:
    InsertionSort(int n) : N(n) {
        arr = new int[N];
    }

    ~InsertionSort() {
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
        for (int i = 1; i < N; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
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
};

int main() {
    srand(time(0));

    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    InsertionSort insertionSort(N);

    cout << "Choose an option:\n";
    cout << "1. Manual entry of array elements\n";
    cout << "2. Random number generation for array elements\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        insertionSort.inputArray();
    } else if (choice == 2) {
        insertionSort.generateRandomArray();
    } else {
        cout << "Invalid choice.\n";
        return 1;
    }

    double timeTaken = insertionSort.measureTimeTaken();

    insertionSort.displaySortedArray();
    cout << "Time taken: " << timeTaken << " seconds\n";

    return 0;
}
