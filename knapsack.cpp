#include <iostream>
#include <vector>
using namespace std;

class Knapsack {
public:
    Knapsack(int n, int capacity) : n(n), capacity(capacity) {
        weights.resize(n);
        values.resize(n);
        dp.resize(n + 1, vector<int>(capacity + 1, 0));
    }

    void inputItems() {
        cout << "Enter the weights of items:\n";
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }

        cout << "Enter the values of items:\n";
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
    }

    int knapsack() {
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0;
                } else if (weights[i - 1] <= w) {
                    dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][capacity];
    }

private:
    int n;
    int capacity;
    vector<int> weights;
    vector<int> values;
    vector<vector<int>> dp;
};

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    Knapsack knapsack(n, capacity);
    knapsack.inputItems();
    int maxProfit = knapsack.knapsack();
    
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
