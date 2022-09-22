#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, x, y;
    vector<int> arr;
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        arr.emplace_back(tmp);
    }
    cin >> x >> y;
    sort(arr.begin(), arr.end());
    if (x == 0) {
        if (arr[0] > 1) cout << arr[0] - 1 << endl;
        else cout << "infinity" << endl;
    } else if (y == 0) {
        if (arr[arr.size()-1] > 1000000000) cout << "infinity" << endl;
        else cout << 1000000000 - arr[arr.size()-1] + 1 << endl;
    } else {
        if (arr[x-1] >= arr[n-y]) {
            cout << "infinity" << endl;
        } else {
            cout << arr[n-y] - arr[x-1] << endl;
        }
    }
    return 0;
}