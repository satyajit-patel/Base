class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 1;
        int ans = 0;

        while(i < n && j < n) {
            if(i == j) {
                j++;
                continue;
            }
            int diff = nums[j] - nums[i];
            if(diff == k) {
                ans++;
                // 1 1 3
                // (1, 3) (1, 3) duplicate pair
                // remove duplicate
                int ele = nums[i];
                while(i < n && nums[i] == ele) {
                    i++;
                }
            } else if(diff < k) {
                j++;
            } else {
                i++;
            } 
        }

        return ans;
    }
};