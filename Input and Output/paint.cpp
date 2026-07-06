#include <iostream>
using namespace std;

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a;
    int b;
    int c;
    int d;

    cin >> a >> b;
    cin >> c >> d;

    int overlap_start = max(a, c);
    int overlap_end = min(b, d);

    int overlap = max(0, overlap_end - overlap_start);

    cout << (b - a) + (d - c) - overlap;
}