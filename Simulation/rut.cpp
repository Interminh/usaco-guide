#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    vector<char> directions(n);
    vector<array<int, 4>> results;
    //Smaller time, Longer Time, First cow, Second Cow

    for (int i = 0; i < n; i++) {
        cin >> directions[i] >> x[i] >> y[i];
    }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (directions[i] == 'E' && directions[j] == 'N') {
                        if (y[i] >= y[j] && x[i] <= x[j]) {
                            int x_time = x[j] - x[i]; //East cow
                            int y_time = y[i] - y[j]; //North cow

                            if (x_time == y_time) {
                                continue;
                            }
                            else if (x_time < y_time) {
                                results.push_back({x_time, y_time, i, j});
                            }
                            else {
                                results.push_back({y_time, x_time, j, i});
                            }
                        }
                    }
                }
    }

    sort(results.begin(), results.end()); 
    vector<int> stuck(n, 1e9);
    for (auto result : results) {
        if (stuck[result[2]] > result[0]) {
            stuck[result[3]] = min(stuck[result[3]], result[1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (stuck[i] == 1e9) {
            cout << "Infinity" << "\n";
        }
        else {
            cout << stuck[i] << "\n";
        }
    }

}