    /*
                         1
                        1 1
                       1 2 1
                      1 3 3 1
                     1 4 6 4 1

                    1
                    1 1
                    1 2 1
                    1 3 3 1
                    1 4 6 4 1
    */

class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        int N = nums.size();

        int nCr[N+1][k+1];
        nCr[0][0] = 1;
        nCr[1][0] = 1;
        nCr[1][1] = 1;
        for (int i=2 ; i<=N; i++) {
            nCr[i][0] = 1; 
            if(i <= k) {
                nCr[i][i] = 1;
            }
            for(int j=1; j<=k && j<i; j++) {
                nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % mod;
            }
        }

        sort(nums.begin(), nums.end());

        long long total = 0;

        // Min contribution
        for(int i=0; i<N; i++) {
            int n = N-1-i;
            for(int r=0; r<k && r<=n; r++) {
                total += (1LL * nums[i] * nCr[n][r]) % mod;
            }
        }

        // Max contribution
        reverse(nums.begin(), nums.end());
        for(int i=0; i<N; i++) {
            int n = N-1-i;
            for(int r=0; r<k && r<=n; r++) {
                total += (1LL * nums[i] * nCr[n][r]) % mod;
            }
        }

        return total % mod;
    }
};
