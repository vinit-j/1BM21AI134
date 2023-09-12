#include <iostream>
#include <vector>
using namespace std;

class BinomialCoefficientCalculator {
public:
    BinomialCoefficientCalculator(int n, int k) : n(n), k(k) {
        dp.assign(n + 1, vector<int>(k + 1, -1));
    }

    int calculate() {
        return calculateBinomialCoefficient(n, k);
    }

private:
    vector<vector<int>> dp;
    int n, k;

    int calculateBinomialCoefficient(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }

        if (dp[n][k] != -1) {
            return dp[n][k];
        }

        dp[n][k] = calculateBinomialCoefficient(n - 1, k - 1) + calculateBinomialCoefficient(n - 1, k);
        return dp[n][k];
    }
};

int main() {
    int n, k;
    cout << "Enter values of n and k: ";
    cin >> n >> k;

    BinomialCoefficientCalculator calculator(n, k);
    int result = calculator.calculate();

    cout << "Binomial Coefficient C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}
