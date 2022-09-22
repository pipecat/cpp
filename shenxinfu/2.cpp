#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int z=0; z<t; z++) {
        int n, k;
        cin >> n >> k;
        vector<int> distance(n, 0);
        vector<int> price(n-1, 0);
        for (int i=0; i<n; i++) {
            cin >> distance[i];
        }
        for (int i=0; i<n-1; i++) {
            cin >> price[i];
        }
        int now = 0;
        int i=0;
        double val = 1000000000.0;
        while (distance[i] - now < k) {
            
        }
    }
}