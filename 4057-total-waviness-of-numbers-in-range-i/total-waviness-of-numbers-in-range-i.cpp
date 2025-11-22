class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int i = num1; i <= num2; i++) {
            vector<int> digits;
           int t=i;
            if (t == 0)
                digits.push_back(0);

            while (t > 0) {
                digits.push_back(t % 10);
                t /= 10;
            }

            reverse(digits.begin(), digits.end());

            if (digits.size() < 3)
                continue;

            int wav = 0;

            for (int y = 1; y + 1 < digits.size(); y++) {

                // peak
                if (digits[y] > digits[y - 1] && digits[y] > digits[y + 1])
                    wav++;

                // valley
                else if (digits[y] < digits[y - 1] && digits[y] < digits[y + 1])
                    wav++;
            }

            total += wav;
        }

        return total;
    }
};