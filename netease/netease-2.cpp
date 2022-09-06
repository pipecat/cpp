#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    if (k <= t || 2 * k - t - 1> n) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0; i<=t; i++) {
        cout << 1;
    }
    for (int i=0; i<((k - t - 1)); i++) {
        cout << 0 << 1;
    }
    for (int i=0; i<(n - 2 * k + t + 1); i++) {
        cout << 0;
    }
    cout << endl;
    return 0;
}