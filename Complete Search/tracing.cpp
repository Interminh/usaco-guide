#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    string state;
    cin >> state;
    vector<array<int, 3>> interactions(t+10);
    for (int i = 0; i < t; i++) {
        cin >> interactions[i][0] >> interactions[i][1] >> interactions[i][2];
    }

    sort(interactions.begin(), interactions.end());
    vector<char> patient_z(101, false);
    int small_k = t + 1;
    int big_k = -1;
    bool infinite_k = false;
    for (int cow = 1; cow <= n; cow++) {
        for (int k = 0; k <= t; k++) {
            vector<char> infected(101, false);
            vector<int> k_left(101, 0);
            infected[cow] = true;
            k_left[cow] = k;
            for(auto &i : interactions) {
                int x = i[1];
                int y = i[2];
                bool x_infect = infected[x] && k_left[x] > 0;
                bool y_infect = infected[y] && k_left[y] > 0;
                int xx;
                int yy;
                if (x_infect) {
                    k_left[x]--;
                    if (!infected[y]) {
                        infected[y] = true;
                        k_left[y] = k;
                    }
                }
                if (y_infect) {
                    k_left[y]--;
                    if (!infected[x]) {
                        infected[x] = true;
                        k_left[x] = k;
                    }
                }
            }
            bool correct = true;
            for (int i = 1; i <= n; i++) {
                if (infected[i] != (state[i-1] == '1')) {
                    correct = false;
                }
            }

            if (correct) {
                patient_z[cow] = true;
                small_k = min(small_k, k);
                big_k = max(big_k, k);
                if (k == t) {
                    infinite_k = true;
                }
            }
        }
    }
    int count_z = 0;
    for (int i = 1; i <= n; i++) {
        if (patient_z[i]) {
            count_z++;
        }
    }
    cout << count_z << " ";
    cout << small_k << " ";
    if (infinite_k) {
        cout << "Infinity";
    }
    else {
        cout << big_k;
    }

}