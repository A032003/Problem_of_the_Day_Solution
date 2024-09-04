class Solution {
public:
    int getLucky(string s, int k) {
        string num;

        for (int i = 0; i < s.size(); i++) {
            int ch = (s[i] - 'a' + 1);
            num = num + to_string(ch);
        }

        int sum = 0;

        while (k--) {
            sum = 0;
            for (int i = 0; i < num.size(); i++) {
                sum += num[i] - '0';
            }
            num = to_string(sum);
        }

        return stoi(num);
    }
};
