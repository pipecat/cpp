#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
    int n, m;
    vector<int> id;
    vector<int> result;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        id.push_back(tmp);
    }
    unordered_set<int> s;
    for (int i=m-1; i>=0; i--) {
        if (!s.count(id[i])) {
            result.push_back(id[i]);
            s.insert(id[i]);
        }
    }
    for (int i=1; i<=n; i++) {
        if (!s.count(i)) result.push_back(i);
    }
    for (int i=0; i<result.size(); i++) {
        if (i == (result.size()-1)) cout << result[i] << endl;
        else cout << result[i] << ' ';
    }
    return 0;
}