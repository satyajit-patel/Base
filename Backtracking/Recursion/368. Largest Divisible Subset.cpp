class Solution {
public:
    vector<int> ans, dp;

    void f(int i, vector<int>& nums, vector<int>& temp) {
        // base case
        if(i >= nums.size()) {
            if(temp.size() > ans.size()) {
                ans = temp;
            }
            return;
        }

        // transition
        int len = temp.size() + 1;
        if((temp.empty()) || (nums[i] % temp.back() == 0) && (dp[i] < len)) {
            // take
            dp[i] = len;
            temp.push_back(nums[i]);
            f(i+1, nums, temp);
            temp.pop_back();
        }
        // notTake
        f(i+1, nums, temp);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dp.clear();
        int n = nums.size();
        dp.resize(n+1, -1);
        f(0, nums, temp);
        return ans;
    }
};


			// or

class Solution {
public:
    vector<int> ans;
    vector<vector<int>> dp;

    void f(int i, vector<int>& nums, vector<int>& temp, int prev) {
        // base case
        if(i >= nums.size()) {
            if(temp.size() > ans.size()) {
                ans = temp;
            }
            return;
        }

        // transition
        int len = temp.size() + 1;
        if((prev == -1) || (nums[i] % nums[prev] == 0) && (dp[i][prev+1] < len)) {
            // take
            dp[i][prev+1] = len;
            temp.push_back(nums[i]);
            f(i+1, nums, temp, i);
            temp.pop_back();
        }
        // notTake
        f(i+1, nums, temp, prev);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ans.clear();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        dp.clear();
        int n = nums.size();
        dp.resize(n+1, vector<int>(n+2, -1));
        f(0, nums, temp, -1);
        return ans;
    }
};