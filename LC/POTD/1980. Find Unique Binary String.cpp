class Solution {
public:
    void f(auto& temp, auto& ans, auto n) {
        // cout << temp << endl;
        if(temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        temp += '0';
        f(temp, ans, n);
        temp.pop_back();

        temp += '1';
        f(temp, ans, n);
        temp.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> ans;
        string temp = "";
        int n = nums.size();
        f(temp, ans, n);
        unordered_set<string> st(nums.begin(), nums.end());
        for(auto& it: ans) {
            // cout << it << " ";
            if(st.find(it) == st.end()) {
                return it;
            }
        }
        return "";
    }
};