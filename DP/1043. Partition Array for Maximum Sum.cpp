class Solution {
public:
    vector<int> memo;

    int f(int i, vector<int>& arr, int k) {
        int n = arr.size();
        if(i == n) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        }

        int maxi = -1e8;
        int maxEleSoFar = -1e8;
        for(int index=i; index<n && index-i+1 <= k; index++) {
            maxEleSoFar = std::max(maxEleSoFar, arr[index]);
            int cost = (maxEleSoFar * (index-i+1)) + f(index+1, arr, k);
            maxi = std::max(maxi, cost);
        }
        memo[i] = maxi;
        return maxi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memo.resize(n+1, -1);
        int ans = f(0, arr, k);
        return ans;
    }
};