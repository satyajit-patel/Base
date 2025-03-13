class Solution {
public:
    int mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;

        // int n = arr.size();
        // for(int i=0; i<n; i++) {
        //     int sum = 0;
        //     for(int j=i; j<n; j++) {
        //         sum += arr[j];
        //         if(sum & 1) {
        //             ans++;
        //             ans %= mod;
        //         }
        //     }
        // }

        // o + o = even
        // o + e = odd
        // e + e = even

        int sum = 0;
        int evenCount = 1; // 0 initially
        int oddCount = 0;
        for(auto& it: arr) {
            sum += it;

            if(sum & 1) {
                oddCount++;
                ans += evenCount;
            } else {
                evenCount++;
                ans += oddCount;
            }
            ans %= mod;
        }

        return ans;
    }
};