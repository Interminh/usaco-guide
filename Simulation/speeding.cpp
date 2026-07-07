#include <iostream>
#include <array>
#include <vector>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> limit(n);
    vector<array<int, 2>> speed(m);

    for (int i = 0; i < n; i++) {
        cin >> limit[i][0] >> limit[i][1];
    }
    for (int i = 0; i < m; i++) {
        cin >> speed[i][0] >> speed[i][1];
    }

    int over_limit = 0;
    int limit_index = 0;
    int speed_index = 0;
    int limit_left = limit[limit_index][0];
    int speed_left = speed[speed_index][0];
    int true_limit = 0;
    int true_speed = 0;

    while (limit_index < n && speed_index < m) {
        true_limit = limit[limit_index][1];
        true_speed = speed[speed_index][1];

        if (true_speed - true_limit >= over_limit) {
            over_limit = true_speed - true_limit;
        }

        int checkpoint = min(limit_left, speed_left);
        limit_left -= checkpoint;
        speed_left -= checkpoint;

        if (limit_left == 0) {
            limit_index++;
            if (limit_index < n) {
            limit_left = limit[limit_index][0];
            }
        }

        if (speed_left == 0) {
            speed_index++;
            speed_left = speed[speed_index][0];
            if (speed_index < n) {
            speed_left = speed[speed_index][0];
            }
        }

    }

        cout << over_limit;




}

/* 
3 3
40 75
50 35
10 45
40 76
20 30
40 40
*/