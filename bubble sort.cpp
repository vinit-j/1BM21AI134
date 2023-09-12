#include <iostream>
using namespace std;

class BubbleSort {
public:
    BubbleSort(int size) : size(size) {
        arr = new int[size];
    }

    ~BubbleSort() {
        delete[] arr;
    }

    void input() {
        cout << "Enter the elements of the array: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void display() {
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int* getArray() {
        return arr;
    }

private:
    int* arr;
    int size;
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    BubbleSort sorter(size);

    sorter.input();

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << sorter.getArray()[i] << " ";
    }

    sorter.sort();

    sorter.display();

    return 0;
}
