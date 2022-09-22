#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;
        vector<int> nums(m, 0);
        for (int j=0; j<m; j++) {
            cin >> nums[j];
        }
        double result=nums[0];
        sort(nums.begin(), nums.end());
        for (int j=1; j<m-1; j++) {
            result += nums[j];
            result = result / 2;
            cout << result << ' ';
        }
        int output=result;
        cout << output << endl;
    }
    return 0;
}