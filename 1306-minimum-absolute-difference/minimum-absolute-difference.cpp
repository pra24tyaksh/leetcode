/*class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int minDiff = INT_MAX;
        
        // Step 1: Find Minimum Difference
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int diff = abs(arr[i] - arr[j]);
                minDiff = min(minDiff, diff);
            }
        }
        
        vector<vector<int>> result;
        
        // Step 2: Collect All Pairs Having minDiff
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int a = arr[i], b = arr[j];
                int diff = abs(a - b);
                
                if(diff == minDiff){
                    if(a < b) 
                        result.push_back({a, b});
                    else 
                        result.push_back({b, a});
                }
            }
        }
        sort(result.begin(), result.end());
        
        return result;
    }
};*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int minDiff = INT_MAX;
        
        // Step 1: Find the minimum difference
        for(int i = 1; i < n; i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }
        
        vector<vector<int>> result;
        
        // Step 2: Collect all pairs with that minimum difference
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i - 1] == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return result;
    }
};
