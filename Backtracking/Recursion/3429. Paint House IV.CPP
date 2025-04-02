class Solution {
public:
    long long dp[100000+2][3+2][3+2];
    long long f(int i, int prevFrontCol, int prevBackCol, int n, vector<vector<int>>& cost) {
        // base case
        int mid = n / 2;
        if(i >= mid) {
            return 0;
        }
        if(dp[i][prevFrontCol+1][prevBackCol+1] != -1) {
            return dp[i][prevFrontCol+1][prevBackCol+1];
        }

        // transition
        long long mini = 1e18;
        for(int frontCol=0; frontCol<3; frontCol++) {
            for(int backCol=0; backCol<3; backCol++) {
                if((frontCol != backCol) && (frontCol != prevFrontCol) && (backCol != prevBackCol)) {
                    auto x = cost[i][frontCol] + cost[n-i-1][backCol] + f(i+1, frontCol, backCol, n, cost);
                    mini = min(mini, x);
                }
            }
        }

        // ans
        dp[i][prevFrontCol+1][prevBackCol+1] = mini;
        return mini;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        memset(dp, -1, sizeof dp);
        return f(0, -1, -1, n, cost);
    }
};