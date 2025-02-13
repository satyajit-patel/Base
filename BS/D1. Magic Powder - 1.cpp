#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

bool isGood(int mid, int n, vi& a, vi& b, int k) {
    vi newRequirement(n);
    for(int i=0; i<n; i++) {
        newRequirement[i] = a[i] * mid;
    }
    int extraNeed = 0;
    for(int i=0; i<n; i++) {
        if(newRequirement[i] > b[i]) {
            extraNeed += (newRequirement[i] - b[i]);
        }
    }
    return extraNeed <= k;
}

void solve() {
    /*
        https://codeforces.com/contest/670/problem/D1
        3 1
        2 1 4
        11 3 16
        
        [2 1 4] [4 2 8] [6 3 12] [8 4(extra 1 powder needed) 16]
    */
    
    int n, k; cin >> n >> k;
    vi a(n); // required gram
    for(auto& it: a) {
        cin >> it;
    }
    vi b(n); // gram we have
    for(auto& it: b) {
        cin >> it;
    }
    
    int i = 0;
    int j = 1e3 + 1e3 + 1; // bi + n
    int ans = -1;
    
    while(i <= j) { // O(log n)
        int mid = (i + j) / 2;
        if(isGood(mid, n, a, b, k)) { // O(n)
            ans = mid;
            // can we bake more
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    
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