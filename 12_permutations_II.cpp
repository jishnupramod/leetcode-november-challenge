/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/




class Solution {
private:
    void generatePerms(vector<int>& nums, set<vector<int>>& up, vector<int>& ep, vector<bool>& chosen) {
        if (nums.size() == ep.size()) {
            up.insert(ep);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (chosen[i]) continue;
            ep.push_back(nums[i]);
            chosen[i] = true;
            generatePerms(nums, up, ep, chosen);
            ep.pop_back();
            chosen[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> uniqPerms;
        vector<int> eachPerm;
        vector<bool> chosen(n, false);
        generatePerms(nums, uniqPerms, eachPerm, chosen);
        vector<vector<int>> permutations(uniqPerms.begin(), uniqPerms.end());
        return permutations;
    }
};

