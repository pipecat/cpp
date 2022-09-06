#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, result=INT32_MIN;
void visit(int pos, int day, int value, vector<int>& a, vector<int>& b, vector<int>& c) {
    if (day >= m) {
        result = max(result, value);
        return;
    }
    if (pos == c[day]) {
        visit(pos, day+1, value+a[day], a, b, c);
    } else {
        visit(c[day], day+1, value+b[day], a, b, c);
    }
    visit(pos, day+1, value, a, b, c);
}

int main() {
    cin >> n >> m >> k;
    vector<int> c(m, 0);
    vector<int> a(m, 0);
    vector<int> b(m, 0);
    for (int i=0; i<m; i++) {
        cin >> c[i];
    }
    for (int i=0; i<m; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    visit(k, 0, 0, a, b, c);
    cout << result << endl;
    return 0;
}