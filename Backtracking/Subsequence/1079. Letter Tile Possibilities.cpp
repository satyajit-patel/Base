class Solution {
public:
    void f(int i, auto& s, auto& st, auto& temp) {
        if(i == s.size()) {
            if(!temp.empty()) {
                st.insert(temp);
            }
            return;
        }

        f(i+1, s, st, temp); // not take
        temp += s[i];
        f(i+1, s, st, temp);
        temp.pop_back();
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        string temp = "";
        f(0, tiles, st, temp);
        unordered_set<string> ans;
        for(auto& it: st) {
            temp = it;
            // DB
            std::sort(temp.begin(), temp.end());
            // BD DB
            do {
                ans.insert(temp);
            } while(std::next_permutation(temp.begin(), temp.end()));
        }
        return ans.size();
    }
};