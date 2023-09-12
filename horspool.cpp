#include <iostream>
#include <vector>
using namespace std;

class PatternSearch {
public:
    PatternSearch(const string& txt, const string& pat) : txt(txt), pat(pat) {
        NO_OF_CHARS = 256;
        badchar.resize(NO_OF_CHARS, -1);
        m = pat.size();
        n = txt.size();
    }

    void badCharHeuristic() {
        for (int i = 0; i < NO_OF_CHARS; i++) {
            badchar[i] = -1;
        }

        for (int i = 0; i < m; i++) {
            badchar[static_cast<int>(pat[i])] = i;
        }
    }

    void searchPattern() {
        badCharHeuristic();
        int s = 0;
        while (s <= (n - m)) {
            int j = m - 1;
            while (j >= 0 && pat[j] == txt[s + j]) {
                j--;
            }

            if (j < 0) {
                cout << "Pattern occurs at shift = " << s << endl;
                s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
            } else {
                s += max(1, j - badchar[txt[s + j]]);
            }
        }
    }

private:
    string txt;
    string pat;
    int NO_OF_CHARS;
    vector<int> badchar;
    int m; // Size of the pattern
    int n; // Size of the text
};

int main() {
    string txt = "Hello my name is Vinit";
    string pat = "Vinit";

    PatternSearch patternSearch(txt, pat);
    patternSearch.searchPattern();

    return 0;
}
