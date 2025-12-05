class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n;
        if (k >= n) return 0;

        sort(nums.begin(), nums.end(), greater<int>()); // descending

        int seen = 0;   // number of elements strictly greater than current group's value
        int ans = 0;

        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) j++;
            int groupSize = j - i;

            if (seen >= k) {
                ans += groupSize;
            }

            seen += groupSize;
            i = j;
        }

        return ans;
    }
};