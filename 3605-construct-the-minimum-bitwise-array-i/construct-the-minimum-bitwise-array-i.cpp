class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int a = -1;
            for(int candidate = 0; candidate <= x; candidate++){
                if( (candidate | (candidate + 1)) == x ){
                    a = candidate;
                    break;
                }
            }

            ans.push_back(a);
        }
        return ans;
    }
};
