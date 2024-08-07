class Solution {
public:
    int minOperations(vector<string>& logs) {

        int n = logs.size();
        int depth = 0;

        for (auto& log : logs) {
            if (log == "../") {
                depth = max(0, depth - 1);

            } else if (log == "./") {
                continue;
            } else {
                depth++;
            }
        }

        return depth;
    }
};
