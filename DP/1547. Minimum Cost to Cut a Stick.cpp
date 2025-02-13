class Solution {
public:
    vector<vector<int>> memo;

    int f(int l, int r, vector<int>& cuts) {
        if(r-l+1 == 2) {
            return 0;
        }
        if(memo[l][r] != -1) {
            return memo[l][r];
        }

        int mini = 1e8;
        for(int i = l+1; i <= r-1; i++) {
            int len = cuts[r] - cuts[l]; // imaginary scale len 0 1 2 3 4 5 6 7
            int cost = len + f(l, i, cuts) + f(i, r, cuts);
            mini = std::min(mini, cost);
        }
        memo[l][r] = mini;
        return mini;
    }

    int minCost(int n, vector<int>& cuts) {
        // 2 <= n <= 1e6
        // 1 <= a[i] <= n-1
        std::sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        int len = cuts.size();
        // 1 <= len <= 100
        memo.resize(len+1, vector<int>(len+1, -1));
        int ans = f(0, len-1, cuts);
        return ans; 
    }
};