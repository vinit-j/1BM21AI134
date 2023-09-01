#include <iostream>
#include <vector>

using namespace std;

void sumOfSubsets(vector<int>& set, vector<int>& subset, int sum, int currentIdx, int targetSum) {
    if (sum == targetSum) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    if (currentIdx >= set.size() || sum > targetSum) {
        return;
    }

    subset.push_back(set[currentIdx]);
    sumOfSubsets(set, subset, sum + set[currentIdx], currentIdx + 1, targetSum);
    subset.pop_back();
    sumOfSubsets(set, subset, sum, currentIdx + 1, targetSum);
}

int main() {
    int n, targetSum;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> subset;
    sumOfSubsets(set, subset, 0, 0, targetSum);

    return 0;
}
