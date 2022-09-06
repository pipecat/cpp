#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> result(k, 0);
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        result[tmp % k]++;
    }
    int res=0;
    for (int i=0; i<n; i++) {
        res = max(result[i], res);
    }
    cout << res << endl;
    return 0;
}