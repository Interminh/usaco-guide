#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main () {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    vector<array<int, 3>> game(n);
    for (int i = 0; i < n; i++) {
        cin >> game[i][0];
        cin >> game[i][1];
        cin >> game[i][2];
    }

    int highest = 0;
    for (int i = 1; i <= 3; i++) {
        int score = 0;
        int pebble = i;

        for (int i = 0; i < n; i++) {
            int a = game[i][0];
            int b = game[i][1];
            int c = game[i][2];

            if (a == pebble) {
                pebble = b;
            }
            else if (b == pebble) {
                pebble = a;
            }

            if (c == pebble) {
                score++;
            }
        }

        if (score >= highest) {
            highest = score;
        }
    }

    cout << highest;

}