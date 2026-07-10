#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> matches_no_reversal(n + 1, 0);
    for(int i = 1; i<=n; i++) {
        if (a[i] == b[i]) {
            matches_no_reversal[i] = 1;
        }
        else {
            matches_no_reversal[i] = 0;
        }
    }
    vector<int> matches_to_point(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        matches_to_point[i] = matches_to_point[i-1] + matches_no_reversal[i];
    }

    int total_matches = matches_to_point[n];
    vector<long long> combinations(n+1, 0);
    for (int sum = 2; sum <= 2 * n; sum++) {
        int lower = max(1, sum - n);
        int higher = min(n, sum - 1);
        if (higher < lower) {
            break;
        }
        int length = higher - lower + 1;
        vector<int> rev_matches_to_point(length + 1, 0);
        for (int i = 1; i <= length; i++) {
            int index = lower + i - 1;
            int pair = sum - index;
            int match;
            if (a[pair] == b[index]) {
                match = 1;
            }
            else {
                match = 0;
            }
            rev_matches_to_point[i] = rev_matches_to_point[i-1] + match;
        }
        for (int l = lower; l <= sum/2; l++) {
            int r = sum - l;
            int subtract = matches_to_point[r] - matches_to_point[l - 1];
            int add = rev_matches_to_point[r - lower + 1] - rev_matches_to_point[l - lower];
            int total = total_matches - subtract + add;
            combinations[total]++;
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << combinations[i] << "\n";
    }

}