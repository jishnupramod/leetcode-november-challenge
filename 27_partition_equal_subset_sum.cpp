/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/




// Top Down DP Approach
class Solution {
private:
    vector<vector<pair<bool, bool>>> dp;
    bool backtrack(vector<int>& nums, int i, int sum, int target) {
        if (sum == target) {
            return true;
        }
        if (i >= nums.size()) return false;
        if (sum > target) return false;
        if (dp[sum][i].first) return dp[sum][i].second;
        dp[sum][i].second = backtrack(nums, i+1, sum+nums[i], target) or backtrack(nums, i+1, sum, target);
        dp[sum][i].first = true;
        return dp[sum][i].second;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        dp.resize(target+1, vector<pair<bool, bool>>(nums.size(), {false, false}));
        return backtrack(nums, 0, 0, target);
    }
};

