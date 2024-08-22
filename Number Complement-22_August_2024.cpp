class Solution {
public:
    int findComplement(int num) {
        string s;
        int ans = 0;

        while (num != 0) {
            s.push_back((num % 2) + '0');
            num = num / 2;
        }

        reverse(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }

        
        for (int i = 0; i < s.size(); i++) {
            ans = ans * 2 + (s[i] - '0');
        }

        return ans;
    }
};
