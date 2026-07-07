#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;
    vector<array<string, 2>> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i][0] >> boards[i][1];
    }

    array<int, 26> letters;
    int index = 0;
    for (char letter = 'a'; letter <= 'z'; letter++) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            int count1 = count(boards[i][0].begin(), boards[i][0].end(), letter);
            int count2 = count(boards[i][1].begin(), boards[i][1].end(), letter);
            total += max(count1, count2);
        }
        letters[index] = total;
        index++;
    }

    for (int i = 0; i < 26; i++) {
        cout << letters[i] << "\n";
    }
}

/*
SAMPLE INPUT:
3
fox box
dog cat
car bus
SAMPLE OUTPUT:
2
2
2
1
0
1
1
0
0
0
0
0
0
0
2
0
0
1
1
1
1
0
0
1
0
0
*/