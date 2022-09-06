#include <vector>
#include <iostream>
#include <algorithm>
// #include <limits.h>
using namespace std;

void adjust(vector<int>& arr, int index) {
    if (index > (arr.size()-1)/2) return;
    int max_index=index;
    if (arr[2*index] > arr[max_index]) max_index = 2*index;
    if (arr[2*index +1] > arr[max_index]) max_index = 2*index + 1;
    if (max_index == index) return ;
    swap(arr[index], arr[max_index]);
    adjust(arr, max_index);
}

void build_heap(vector<int>& arr) {
    int i=(arr.size()-1)/2;
    for (; i>=0; i--) {
        adjust(arr, i);
    }
}

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> arr(n, 0);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    // build_heap(arr);
    // while (k > 0) {
    //     arr[0] -= x;
    //     adjust(arr, 0);
    //     k--;
    // }
    sort(arr.begin(), arr.end(), greater<int>());
    
    while (k > 0) {
        int x_index=0, x2_index=0;
        while ( x_index < arr.size() && arr[x_index] >= arr[0] - x) x_index++;
        while ( x2_index < arr.size() && arr[x2_index] >= arr[0] - 2*x) x2_index++;
        int index = min(k, min(n, x_index+1));
        int sort_index = min(x2_index, n);
        k -= index;
        for (int i=0; i<index; i++) {
            arr[i] -= x;
        }
        sort(arr.begin(), arr.begin() + sort_index, greater<int>());
    }
    cout << arr[0] << endl;
    return 0;
}