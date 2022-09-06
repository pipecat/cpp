#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n, mex=0;
    unordered_set<int> s;
    cin >> n;
    vector<int> vec(n, -1);
    // vector<int> result;
    for (int i=0; i<n; i++) {
        cin >> vec[i];
        s.insert(vec[i]);
        if (vec[i] == mex) {
            while (s.count(mex))
            {
                mex++;
            }
        }
    }
    for (int i=0; i<n; i++) {
        int tmp;
        tmp = min(mex, vec[i]);
        if (i == 0) {
            cout << tmp;
            continue;
        } else {
            cout << ' ' << tmp;
        }
    }
    cout << endl;
    return 0;
}