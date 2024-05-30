class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;
        int xorr = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            xorr = arr[i];
            for (int k = i + 1; k < n; k++) {
                xorr = xorr ^ arr[k];
                if (xorr == 0) {
                    ans = ans + (k - i);
                }
            }
        }

        return ans;
    }
};
