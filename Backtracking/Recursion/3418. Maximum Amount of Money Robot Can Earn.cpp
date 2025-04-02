class Solution {
public:
    vector<vector<int>> grid;
    int n, m;

    bool isValid(int i, int j) {
        return i>=0 && i<n && j>=0 && j<m;
    }

    int dp[501][501][2+1];
    int f(int i, int j, int k) {
        // base case
        if(!isValid(i, j)) {
            return -1e8;
        }
        if((i == n-1) && (j == m-1)) {
            if(grid[i][j] >= 0) {
                return grid[i][j];
            } else {
                if(k) {
                    return 0;
                } else {
                    return grid[i][j];
                }
            }
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        // transition
        int val = grid[i][j];
        if(val >= 0) {
            return dp[i][j][k] = val + max(f(i, j+1, k), f(i+1, j, k));
        } else {
            if(k) {
                // again we have 2 choice either neutralize this or not
                // as it can happen that we might find better guy to neutralize furher
                return dp[i][j][k] = max(0 + max(f(i, j+1, k-1), f(i+1, j, k-1)), val + max(f(i, j+1, k), f(i+1, j, k)));
            } else {
                return dp[i][j][k] = val + max(f(i, j+1, k), f(i+1, j, k));
            }
        }
    }

    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size();
        m = coins[0].size();
        grid.clear();
        grid = coins;
        memset(dp, -1, sizeof dp);
        int ans = f(0, 0, 2);
        return ans;
    }
};