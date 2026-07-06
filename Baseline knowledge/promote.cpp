#include <iostream>

using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    int bronze_i, bronze_f, sliver_i, sliver_f, gold_i, gold_f, plat_i, plat_f;

    cin >> bronze_i >> bronze_f;
    cin >> sliver_i >> sliver_f;
    cin >> gold_i >> gold_f;
    cin >> plat_i >> plat_f;

    int b_s, s_g, g_p;

    g_p = plat_f - plat_i;
    s_g = gold_f - gold_i + g_p;
    b_s = sliver_f - sliver_i + s_g;

    cout << b_s << "\n";
    cout << s_g << "\n";
    cout << g_p << "\n";
}