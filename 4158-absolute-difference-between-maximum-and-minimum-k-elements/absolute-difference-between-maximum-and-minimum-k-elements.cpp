class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int sum=0,diff=0;
        int n=nums.size();
        if(n==0||k==0)
        return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            diff+=nums[i];
            sum+=nums[n-1-i];
        }
        return abs(sum-diff);

    }
};