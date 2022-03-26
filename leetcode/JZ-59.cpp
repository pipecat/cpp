#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            vector<int> temp = {};
            return temp;
        }
        vector<int> result(nums.size() - k + 1, 0);
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        result[0] = nums[q.front()];
        for (int i = 1; i < nums.size() - k + 1; i++) {
            int first_index = q.front();
            if (nums[i-1] == nums[first_index]) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i - 1 + k]) {
                q.pop_back();
            }
            q.push_back(i - 1 + k);
            result[i] = nums[q.front()];
        }
        return result;
    }
};
int main() {
    int n, k=3;
    vector<int> v = {1,3,-1,-3,5,3,6,7} ,result;
    Solution* s = new Solution();
    result = s->maxSlidingWindow(v, k);
    for (auto i:result) {
        cout << i << endl;
    }
    delete s;
    return 0;
}