#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

/*
InputCopy
BBBSSC
6 4 1
1 2 3
4
OutputCopy
2
*/

// https://codeforces.com/contest/371/problem/C

bool isGood(int mid, vi& BSCRatio, vi& ourStock, vi& costOfThis, int ourWallet) {
    vi newRatio(3);
    for(int i=0; i<3; i++) {
        newRatio[i] = BSCRatio[i] * mid;
    }
    int newCost = 0;
    for(int i=0; i<3; i++) {
        if(newRatio[i] > ourStock[i]) {
            newCost += (newRatio[i] - ourStock[i]) * costOfThis[i];
        }
    }
    
    // debug
    // cout << mid << endl;
    // for(auto& it: newRatio) {
    //     cout << it << " ";
    // }
    // cout << endl;
    // cout << newCost << " -> " << ourWallet << "\n\n";
    
    return ourWallet >= newCost;
}

void solve() {
    string s; cin >> s;
    vi ourStock(3);
    for(auto& it: ourStock) {
        cin >> it;
    }
    vi costOfThis(3);
    for(auto& it: costOfThis) {
        cin >> it;
    }
    int ourWallet; cin >> ourWallet;
    
    vi BSCRatio(3, 0); // bread sausage cheese
    for(auto& it: s) {
        if(it == 'B') {
            BSCRatio[0]++;
        } else if(it == 'S') {
            BSCRatio[1]++;
        } else {
            BSCRatio[2]++;
        }
    }
    
    int i = 0;
    int j = 1e12 + 101;
    int ans = -1;
    while(i <= j) {
        int mid = (i + j) / 2;
        if(isGood(mid, BSCRatio, ourStock, costOfThis, ourWallet)) {
            ans = mid;
            // can we make more
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