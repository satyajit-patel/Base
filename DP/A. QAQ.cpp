#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

int f(int i, string s, string temp) {
    // base case
    if(temp == "QAQ") {
        return 1;
    }
    if(temp.size() > 3) {
        return 0;
    }
    if(temp.size() > 0 && temp[0] != 'Q') {
        return 0;
    }
    if(i >= s.size()) {
        return 0;
    }
    
    // transition
    temp += s[i];
    int take = f(i+1, s, temp);
    temp.pop_back();
    int notTake = f(i+1, s, temp);
    
    // ans
    int ans = take + notTake;
    return ans;
}

// https://codeforces.com/contest/894/problem/A

int dp(int i, int index, string s, vvi& memo) {
    if(index == 3) {
        return 1;
    }
    if(i == s.size()) {
        return 0;
    }
    if(memo[i][index] != -1) {
        return memo[i][index];
    }
    
    // notTake
    int ans = dp(i+1, index, s, memo);
    if(s[i] == "QAQ"[index]) {
        ans += dp(i+1, index+1, s, memo);
    }
    memo[i][index] = ans;
    return ans;
}

void solve() {
    string s; cin >> s;
    
    // string temp = "";
    // int ans = f(0, s, temp); // TLE
    
    int n = s.size();
    // 1 <= n <= 100
    vvi memo(n+1, vi(3+1, -1));
    int ans = dp(0, 0, s, memo);
    
    cout << ans;
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();   
    }
    return 0;
}