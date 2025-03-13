class Solution {
public:
    int getMaxSumSubarray(vector<int>& nums) {
        // what if all ele were -ve
        int ans = *max_element(nums.begin(), nums.end());
        if(ans <= 0) {
            return ans;
        }
        int sum = 0;
        for(auto& it: nums) {
            sum += it;

            if(sum < 0) {
                sum = 0;
            }

            ans = std::max(ans, sum);
        }
        return ans;
    }

    int getMinSumSubarray(vector<int>& nums) {
        // what if all ele were +ve
        int ans = *min_element(nums.begin(), nums.end());
        if(ans >= 0) {
            return ans;
        }
        int sum = 0;
        for(auto& it: nums) {
            sum += it;

            if(sum >= 0) {
                sum = 0;
            }

            ans = std::min(ans, sum);
        }
        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int ans = INT_MIN;

        // int n = nums.size();
        // for(int i=0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=i; j<n; j++) {
        //         sum += nums[j];
        //         ans = std::max(ans, std::abs(sum));
        //     }
        // }

        // kadanes(max sum subarray) with some additional work
        ans = std::max(getMaxSumSubarray(nums), std::abs(getMinSumSubarray(nums)));

        return ans;
    }
};