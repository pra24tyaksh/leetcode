class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string x = "";

        // form x by skipping zeros
        for (char c : s) {
            if (c != '0') x += c;
        }

        if (x.empty()) return 0;

        // build number in long long (avoid stoi overflow) and compute digit sum
        long long num = 0;
        long long sum = 0;
        for (char c : x) {
            int d = c - '0';
            num = num * 10 + d;   // num stays in long long
            sum += d;
        }

        return num * sum; // product is long long, no overflow for int-sized inputs
    }
};
