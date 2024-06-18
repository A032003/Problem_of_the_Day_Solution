class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> v;

        for (int i = 0; i < profit.size(); i++) {
            v.push_back(make_pair(difficulty[i], profit[i]));
        }

        sort(worker.begin(), worker.end());
        sort(v.begin(), v.end());

        int money = 0;
        int maxProfit = 0;
        int j = 0;

        for (int i = 0; i < worker.size(); i++) {
            while (j < v.size() && worker[i] >= v[j].first) {
                maxProfit = max(maxProfit, v[j].second);
                j++;
            }
            money += maxProfit;
        }

        return money;
    }
};
