class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // take out 2 smallest ele x, y
            // remove x, y
            // add min(x, y) * 2 + max(x, y)
        // make all ele >= k

        priority_queue<long long> minHeap;
        for(auto& it: nums) {
            minHeap.push(-it);
        }
        int ans = 0;
        while(minHeap.size() >= 2) {
            long long x = -minHeap.top();
            minHeap.pop();
            long long y = -minHeap.top();
            minHeap.pop();

            if(x < k || y < k) {
                long long newEle = std::min(x, y) * 2 + std::max(x, y);
                minHeap.push(-newEle);
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};