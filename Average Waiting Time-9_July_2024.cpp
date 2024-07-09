class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitTime = 0;
        int total = 0;
        double n = customers.size();

        for (auto& vec : customers) {
            if (total > vec[0]) {
                total = total + vec[1];
            } else {
                total = vec[0] + vec[1];
            }

            waitTime = (total - vec[0]) + waitTime;
        }
        return waitTime / n;
    }
};
