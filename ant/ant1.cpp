#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, result=0;
    vector<int> arr(n, 0);
    cin >> n;
    cin >> arr[0];
    for (int i=1; i<n; i++) {
        cin >> arr[i];
    }
    int left, right;
    int j;
    for (int i=1; i<n; i++ {
        if (arr[i] < arr[i-1]) left = i;
        for (j=left+1; j<n; j++) {
            if (arr[j] < arr[j-1]) right = j-1;
        }
        if (j == n) j = n-1;

    }
    cout << result << endl;
    return 0;
}