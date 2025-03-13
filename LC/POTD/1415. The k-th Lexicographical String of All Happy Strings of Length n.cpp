class Solution {
public:
    void f(string& temp, vector<string>& ans, int n) {
        if(temp.size() == n) {
            ans.push_back(temp);
        }
        if(temp.size() > n) {
            return;
        }

        for(char ch='a'; ch<='c'; ch++) {
            if(temp.empty()) {
                temp += ch;
                f(temp, ans, n);
                temp.pop_back();
            } else if(temp.back() != ch) {
                    temp += ch;
                    f(temp, ans, n);
                    temp.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        string temp = "";
        f(temp, ans, n);
        if(ans.size() >= k) {
            return ans[k-1];
        }
        return "";
    }
};