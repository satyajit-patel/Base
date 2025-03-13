class Solution {
public:
    int getSumOfDigits(int n) {
        int sum = 0;

        while(n) {
            int lastDigit = n % 10;
            sum += lastDigit;
            n /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int>> mp;

        for(auto& it: nums) { // O(n)
            int sum = getSumOfDigits(it); // O(9 digit) == O(1)
            mp[sum].insert(it);
        }

           int maxi = -1;

        for(auto& it: mp) { // O(n)
            auto st = it.second;
            if(st.size() >= 2) { // O(1)
                auto itr = st.rbegin();
                int x = *itr;
                itr++;
                int y = *itr;
                maxi = std::max(maxi, x + y);
            }
        }

        return maxi;
    }
};