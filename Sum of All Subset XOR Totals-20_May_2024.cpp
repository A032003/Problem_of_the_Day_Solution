class Solution {
public:
    void solve(vector<int> nums, vector<int> output, vector<vector<int>>& ans,
               int index) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        solve(nums, output, ans, index + 1); // exclude

        // include
        int elem = nums[index];
        output.push_back(elem);
        solve(nums, output, ans, index + 1);
    }

    int SumXor(vector<int>& input) {
        int sum = 0;
        for (int i = 0; i < input.size(); i++) {
            sum ^= input[i];
        }
        return sum;
    }

    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, output, ans, 0);

        int totalsum = 0;
        for (int i = 0; i < ans.size(); i++) {
            int sum = SumXor(ans[i]);
            totalsum += sum;
        }

        return totalsum;
    }
};
