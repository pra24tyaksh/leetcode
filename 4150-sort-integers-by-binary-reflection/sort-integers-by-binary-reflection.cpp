class Solution {
public:
    int reflect(int n) {
        if (n == 0) return 0;

        string s = "";
        while (n > 0) {
            s += char('0' + (n % 2)); 
            n /= 2;
        }

        return stoi(s, nullptr, 2); 
    }  

    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> v;

        for (int x : nums) {
            v.push_back({reflect(x), x}); 
        }

        sort(v.begin(), v.end());  

        vector<int> res;
        for (auto &p : v) {
            res.push_back(p.second); 
        }

        return res;
    }
};
