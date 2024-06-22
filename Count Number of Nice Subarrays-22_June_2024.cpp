class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int count = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        if (k < 0) {
            return 0;
        }

        while (r < nums.size()) {
            sum = sum + nums[r];

            while (sum > k) {
                sum = sum - nums[l];
                l++;
            }

            count = count + (r - l + 1);

            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != 0) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }
        return solve(nums, k) - solve(nums, k - 1);
    }
};
