#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main () {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        vector<bool> dp(s.size()+1, false);
        if (s.size() == 2) {
            if (s == "00" || s == "11") cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if ()
        }
    }
}