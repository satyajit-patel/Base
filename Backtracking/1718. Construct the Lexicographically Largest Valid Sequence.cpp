class Solution {
public:
    vector<int> ans, vis;
    int N;

    bool f(int i) {
        if(i == ans.size()) {
            return true;
        }

        if(ans[i]) {
            return f(i+1);
        }
        for(int num = N; num >= 1; num--) {
            if(!vis[num]) {
                // try
                vis[num] = 1;
                ans[i] = num;

                // explore
                if(num == 1) {
                    if(f(i+1)) {
                        return true;
                    }
                } else {
                    int nextIndex = num + i;
                    if((nextIndex < ans.size()) && (!ans[nextIndex])) {
                        // try
                        ans[nextIndex] = num;

                        if(f(i+1)) {
                            return true;
                        }

                        // undo
                        ans[nextIndex] = 0;
                    }
                }

                // undo
                vis[num] = 0;
                ans[i] = 0;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        ans.resize(n * 2 - 1, 0);
        vis.resize(n+1, 0);
        N = n;
        if(!f(0)) {
            return {-1};
        }
        return ans;
    }
};