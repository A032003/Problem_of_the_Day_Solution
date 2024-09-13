class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int anss = 0;
        for (auto vec : queries) {
            anss = 0;

            for (int i = vec[0]; i <= vec[1]; i++) {
                anss = anss ^ arr[i];
            }
            ans.push_back(anss);
        }
        return ans;
    }
};
