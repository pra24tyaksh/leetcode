class Solution {
public:
    // Recursive helper function
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        // base case: reached end of array
        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // -------- Include current element --------
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);
        ans.pop_back(); // backtrack

        // -------- Skip duplicate values --------
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1])
            idx++;

        // -------- Exclude current element --------
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Step 1: sort to bring duplicates together
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        // Step 2: generate subsets
        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};
