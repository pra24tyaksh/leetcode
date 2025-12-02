class Solution {
public:
   int singleNumber(vector<int>& nums) {
    int as = 0;
    for (int n : nums) 
    as ^= n;
    return as;
}
};