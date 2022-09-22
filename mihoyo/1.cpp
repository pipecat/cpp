#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    int n, k;
    vector<int> pos;
    vector<int> result = {0, 0};
    int distance=2000000000;
    cin >> n >> k ;
    cin >> s;
    if (n < k * 6) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0; i<n-5; i++) {
        if (s[i] != 'm') continue;
        string tmp;
        tmp = s.substr(i, 6);
        // cout << i << ' ' << tmp << endl;
        if (tmp == "mihoyo") {
            pos.push_back(i);
            i = i + 5;
        }
    }
    if (pos.size() < k) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=0; i<pos.size(); i++) {
        if (i + k < pos.size() && pos[i+k] - pos[i] < distance) {
            distance = pos[i+k-1] - pos[i];
            result[0] = pos[i];
            result[1] = pos[i+k-1];
        }
    }
    cout << result[0] << ' ' <<  result[1] + 5 << endl;
    return 0;
}