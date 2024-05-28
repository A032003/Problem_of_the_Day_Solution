class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0;
        int n = s.size();
        int maxlength = 0;
        int current_cost = 0;

        for (int end = 0; end < n; end++) {
            current_cost += abs(s[end] - t[end]);

            while (current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                start++;
            }
            maxlength = max(maxlength, end - start + 1);
        }
        return maxlength;
    }
};
