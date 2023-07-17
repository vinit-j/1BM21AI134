#include <iostream>

class SelectionSort {
private:
    int* arr;
    int size;

public:
    SelectionSort(int n) {
        size = n;
        arr = new int[size];
    }

    void inputArray() {
        std::cout << "Enter " << size << " integers:" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }

    void sortArray() {
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }

    void displayArray() {
        std::cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~SelectionSort() {
        delete[] arr;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    SelectionSort ss(n);
    ss.inputArray();
    ss.sortArray();
    ss.displayArray();

    return 0;
}

