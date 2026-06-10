class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }

        if (ones <= 1) return 0;

        int currOnes = 0;
        for (int i = 0; i < ones; i++) {
            currOnes+=nums[i];
        }
        int maxOnes = currOnes;
        for (int i = ones; i < n + ones; i++) {
            currOnes += nums[i % n];
            currOnes -= nums[(i - ones) % n];

            maxOnes = max(maxOnes, currOnes);
        }

        return ones - maxOnes;

        
    }
};