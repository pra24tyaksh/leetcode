class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxima=sum;
        for(int i=k;i<n;i++){
            sum=sum-nums[i-k]+nums[i];
            maxima=max(maxima,sum);
        }
        return (double)maxima/k;
    }
};