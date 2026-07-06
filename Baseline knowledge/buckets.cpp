#include <iostream>

using namespace std;

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    int b_r, b_c, l_r, l_c, r_r, r_c;

    string row;
    for (int r = 0; r < 10; r++) {
        cin >> row;

        for (int c = 0; c < 10; c++) {
            char spot = row[c];

            if (spot == 'B') {
                b_r = r;
                b_c = c;
            }

            if (spot == 'R') {
                r_r = r;
                r_c = c;
            }

            if (spot == 'L') {
                l_r = r;
                l_c = c;
            }
        }
    }

    int distance_c = abs(b_c - l_c);
    int distance_r = abs(b_r - l_r);

    bool rock;
    if (distance_c > 0 && distance_r > 0) {
        rock = false;
    }

    else {
        if (distance_c == 0) {
            if (r_c == b_c && r_r > min(b_r, l_r) && r_r < max(b_r, l_r)) {
                rock = true;
            }
            else {
                rock = false;
        
            }
        }

        else {
            if (distance_r == 0) {
                if (r_r == b_r && r_c > min(b_c, l_c) && r_c < max(b_c, l_c)) {
                    rock = true;
                }
                else {
                    rock = false;
                }
            }
        }
    }
    
    int total_distance;
    if (rock) {
        total_distance = distance_c + distance_r + 1;
    }
    else {
        total_distance = distance_c + distance_r - 1;
    }

    cout << total_distance << endl;
}