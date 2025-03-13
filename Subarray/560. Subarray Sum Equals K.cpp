class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        // sum = x + k just we have to know have we seen x before
        int sum = 0;
        unordered_map<int, int> mp;
        mp[sum]++;
        for(auto& it: nums) {
            sum += it;

            int x = sum - k;
            if(mp.find(x) != mp.end()) {
                ans += mp[x];
            }

            mp[sum]++;
        }

        return ans;
    }
};