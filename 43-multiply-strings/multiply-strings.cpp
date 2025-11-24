/*class Solution {
public:
    string multiply(string num1, string num2) {

        long long n1 = 0;
        long long n2 = 0;

        for(int i = 0; i < num1.size(); i++){
            int digit1 = num1[i] - '0';
            n1 = n1 * 10 + digit1;
        }

        for(int j = 0; j < num2.size(); j++){
            int digit2 = num2[j] - '0';
            n2 = n2 * 10 + digit2;
        }

        long long product = n1 * n2;
        if(product == 0)
         return "0";
        string ans = "";
        while(product > 0){
            int digit = product % 10;
            ans = char('0' + digit) + ans;
            product /= 10;
        }

        return ans;
    }
};*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> res(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';
                int mul = d1 * d2;
                int sum = mul + res[i + j + 1]; // add existing
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string ans;
        int k = 0;
        while (k < (int)res.size() && res[k] == 0) ++k;
        for (; k < (int)res.size(); ++k) ans.push_back(char('0' + res[k]));
        return ans.empty() ? "0" : ans;
    }
};

