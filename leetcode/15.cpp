#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (i > 0 && i < nums.size() && nums[i] == nums[i-1]) i++;
            int j=i+1, k=nums.size()-1;
            while (j < k) {
                if (nums[j] + nums[k] == -nums[i]) {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    result.push_back(tmp);
                    j++;
                    while (j >=0 && j < nums.size() && nums[j] == nums[j-1]) j++;
                    k--;
                    while (k >=0 && k < nums.size() && nums[k] == nums[k+1]) k--;
                } else if (nums[j] + nums[k] < -nums[i]){
                    j++;
                    while (j >=0 && j < nums.size() && nums[j] == nums[j-1]) j++;
                } else {
                    k--;
                    while (k >=0 && k < nums.size() && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> input = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution* solu = new Solution();
    solu->threeSum(input);
    return 0;
}