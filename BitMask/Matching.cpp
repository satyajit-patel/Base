#include <bits/stdc++.h>
using namespace std;
// #define int long long

// https://atcoder.jp/contests/dp/tasks/dp_o

// int f(int i, set<int>& st, int n, vector<vector<int>>& grid) {
//     // cout << i << " -> ";
//     // for(auto& it: st) {
//     //     cout << it << " ";
//     // }
//     // cout << endl;
//     if(st.empty()) {
//         return 1;
//     }
//     if(i >= n) {
//         return 0;
//     }
    
//     int ways = 0;
//     for(auto& women: st) {
//         if(grid[i][women] == 1) {
//             st.erase(women);
//             ways += f(i+1, st, n, grid);
//             st.insert(women);
//         }
//     }
//     return ways;
// }

int cache[21+1][(1 << 21) + 1];

int usingMask(int i, int mask, int n, vector<vector<int>>& grid) {
    if(!mask) {
        return 1;
    }
    if(i >= n) {
        return 0;
    }
    if(cache[i][mask] != -1) {
        return cache[i][mask];
    }
    
    int ways = 0;
    for(int j=0; j<n; j++) {
        // if the woman is compatible and availabe
        if((grid[i][j] == 1) && (mask & (1 << j))) {
            // turn that bit off(i.e that women is booked)
            ways += usingMask(i+1, mask ^ (1 << j), n, grid);
            ways %= 1000000007;
        }
    }
    cache[i][mask] = ways;
    return ways;
}

signed main() {
	int n; cin >> n;
	
	vector<vector<int>> grid(n, vector<int>(n));
	for(auto& it: grid) {
	    for(auto& ele: it) {
	        cin >> ele;
	    }
	}
	
// 	set<int> st;
// 	for(int i=0; i<n; i++) {
// 	    st.insert(i);
// 	}
	
// 	int ans = f(0, st, n, grid);
    std::memset(cache, -1, sizeof cache);
	int ans = usingMask(0, (1 << n)-1, n, grid);
	cout << ans;
	
	return 0;
}
