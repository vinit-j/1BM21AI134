#include <iostream>
using namespace std;

class NumberSearch {
public:
    void searchNumber() {
        int arr[10], i, num, index;
        cout << "Enter 10 Numbers: ";
        for (i = 0; i < 10; i++)
            cin >> arr[i];
        cout << "\nEnter a Number to Search: ";
        cin >> num;
        for (i = 0; i < 10; i++) {
            if (arr[i] == num) {
                index = i;
                break;
            }
        }
        cout << "\nFound at Index No." << index << endl;
    }
};

int main() {
    NumberSearch searchObj;
    searchObj.searchNumber();
    return 0;
}
