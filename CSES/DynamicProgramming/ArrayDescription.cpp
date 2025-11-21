#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

int mod_add(int val1, int val2){
    int res = val1 + val2;
    if(res >= mod)
        res -= mod;
    return res;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int>arr(n);
    for(int& x : arr) cin >> x;

    vector<int>dp(m+2);
    if(arr[0] == 0)
        for(int i = 1; i <= m; ++i) dp[i] = 1;
    else
        dp[arr[0]] = 1;
    // for(int i = 1; i <= m; ++i) cout<<dp[i]<<' ';
    // cout<<'\n';
    for(int i = 1; i < n; ++i){
        // cout<<i<<':';
        int x = arr[i];
        if(x == 0){
            for(int val = 1, last = 0; val <= m; ++val){
                int new_val = mod_add(dp[val], dp[val+1]);
                new_val = mod_add(new_val, last);
                last = dp[val];
                dp[val] = new_val;
                // cout<<' '<<dp[val];
            }
        }
        else{
            dp[x] = mod_add(dp[x], dp[x + 1]);
            dp[x] = mod_add(dp[x], dp[x - 1]);
            for(int val = 1; val <= m; ++val){
                if(val != x)
                    dp[val] = 0;
            }
            // cout<<dp[x];
        }
        // cout<<'\n';
    }
    int res = 0;
    for(int x : dp) res = mod_add(res, x);
    cout<<res<<'\n';
    return 0;
}