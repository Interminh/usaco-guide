#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;

    cin >> a >> b >> x >> y;

    int direct, teleport_x, teleport_y;

    direct = abs(a - b);
    teleport_x = abs(a - x) + abs(b - y);
    teleport_y = abs(a - y) + abs(b - x);

    cout << min({direct, teleport_x, teleport_y});

}