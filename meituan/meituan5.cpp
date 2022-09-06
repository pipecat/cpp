#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int main() {
    int n, toy_n, time;
    int result = 0;
    cin >> n >> toy_n >> time;
    vector< vector<int> > toys;
    for (int i=0; i<toy_n; i++) {
        vector<int> tmp(2);
        int toy;
        cin >> toy;
        tmp[0] = toy;
        tmp[1] = 0;
        toys.push_back(tmp);
    }
    sort(toys.begin(), toys.end(), comp);
    for (int i=0; i<n; i++) {
        int event;
        cin >> event;
        if (event == 0) {
            int j;
            for (j=0; j<toys.size(); i++){
                if (toys[j][1] > 0) {
                    toys[j][1]--;
                    result += toys[j][0];
                    break;
                } 
            }
            if (j == toys.size()) {
                result += time;
            }
        } else {
            toys[event][1]++;
        }
    }
    cout << result << endl;
}