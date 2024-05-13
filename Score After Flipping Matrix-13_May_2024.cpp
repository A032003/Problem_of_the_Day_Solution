class Solution {
public:
    void flipcols(int col, vector<vector<int>>& grid, int n) {

        for (int row = 0; row < n; row++) {
            if (grid[row][col] == 0) {
                grid[row][col] = 1;
            } else {
                grid[row][col] = 0;
            }
        }
    }

    void fliprows(int row, vector<vector<int>>& grid, int m) {

        for (int col = 0; col < m; col++) {
            if (grid[row][col] == 0) {
                grid[row][col] = 1;

            } else {
                grid[row][col] = 0;
            }
        }
    }

    int value(vector<int>& temp) {

        int n = temp.size();
        int ans = 0;
        int k = 0;

        for (int i = n - 1; i >= 0; i--) {
            int bit = temp[i];

            ans = ans + (bit * pow(2, k));
            k++;
        }

        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for (int row = 0; row < n; row++) {
            if (grid[row][0] == 0) {
                fliprows(row, grid, m);
            }
        }

        for (int col = 0; col < m; col++) {
            int zeros = 0, ones = 0;
            for (int row = 0; row < n; row++) {
                if (grid[row][col] == 0) {
                    zeros++;
                } else {
                    ones++;
                }
            }

            if (zeros > ones) {
                flipcols(col, grid, n);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = ans + value(grid[i]);
        }

        return ans;
    }
};
