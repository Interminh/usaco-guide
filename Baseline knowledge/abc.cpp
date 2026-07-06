#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max(vector<int>& v) {
    int top = v.back();
    v.pop_back();
    return top;
}

int remove(vector<int>& v, int value) {
    auto ptr = find(v.begin(), v.end(), value);
    v.erase(ptr);
    return value; 
}

int main() {
    vector<int> numbers;
    int x;
    for (int i = 0; i < 7; i++) {
        cin >> x;
        numbers.push_back(x);
    }

    sort(numbers.begin(), numbers.end());

    int top = max(numbers);
    int sum_b_c = max(numbers);
    int a = top - sum_b_c;
    remove(numbers, a);
    int sum_a_c = max(numbers);
    int c = sum_a_c - a;
    int b = top - a - c;

    cout << a << " " << b << " " << c;
    

}
