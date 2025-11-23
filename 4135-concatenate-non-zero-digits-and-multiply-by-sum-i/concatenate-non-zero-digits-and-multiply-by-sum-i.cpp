class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x = "";
        for (char c : s) {
            if (c != '0') x += c;
        }

        if (x.empty()) return 0;
        long long num = 0;
        long long sum = 0;
        for (char c : x) {
            int d = c - '0';
            num = num * 10 + d;   
            sum += d;
        }

        return num * sum; 
    }
};
