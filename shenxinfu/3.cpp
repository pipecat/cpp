#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k=0; k<t; k++) {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> timestamp(n, 0);
        for (int i=0; i<n; i++) {
            cin >> timestamp[i];
        }
        if (timestamp[timestamp.size()-1] - timestamp[0] < a) {
            cout << "Yse" << endl;
            continue;
        } else if (timestamp.size() < b) {
            cout << "No" << endl;
        }
        int i;
        for (i=0; i<n-b+1; i++) {
            if (timestamp[i + b - 1] - timestamp[i] < a) {
                cout << "Yes" << endl;
                break;
            }
        }
        if (i == n-b+1) {
            cout << "No" << endl;
        }
    }
    return 0;
}