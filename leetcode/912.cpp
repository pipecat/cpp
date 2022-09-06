#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, nums.size()-1);
        return nums;
    }
    void qsort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int i, j, part;
        i = l + 1;
        j = r;
        while (i <= j) {
            while(i <= r && nums[i] <= nums[l]) i++;
            while(j > l && nums[j] > nums[l]) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
        if (l != j) swap(nums[l], nums[j]);
        qsort(nums, l, j-1);
        qsort(nums, j+1, r);
    }
};

int main() {
    Solution* solu = new Solution();
    vector<int> a = {5,2,3,1};
    solu->sortArray(a);
    for (int i=0; i<a.size(); i++) {
        cout << a[i] << ' ';
    }
    return 0;
}