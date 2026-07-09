#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int k, n;
    cin >> k >> n;

    int cows[10][21];
    int cow;
    //Practice session ; Cows (1 - 20)
    for (int session = 0; session < k; session++) {
        for (int level = 0; level < n; level++) {
            cin >> cow;
            cows[session][cow] = level;
        }
    }

    int pairs = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            bool aBetter = true;
            bool bBetter = true;
            for (int session = 0; session < k; session++) {
                if (cows[session][a] > cows[session][b]) {
                    aBetter = false;
                }
                else {
                    bBetter = false;
                }
            }
            if (aBetter || bBetter) {
                pairs++;
            }
        }
    }

    cout << pairs;
}