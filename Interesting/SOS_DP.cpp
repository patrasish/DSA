/*

author : Tandav
date   : 26Nov, 2025
prob   : Codeforces Div1(257), problem D
https://codeforces.com/problemset/problem/449/D

*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n; cin >> n;
    vector<int>nums(n);
    for(int& x : nums) cin >> x;

    int B = 20, total_subsets = (1 << B);
    vector<int> dp(total_subsets); // dp[x] = number of y in nums such that x & y = x.
    for(int x : nums) ++dp[x];

    for(int pos = 0; pos < B; ++pos){
        for(int t = total_subsets - 1; t >= 0; --t){
            if(t & (1 << pos))
                dp[t ^ (1 << pos)] += dp[t];
        }
    }
    vector<int>power(n + 1);
    power[0] = 1;
    for(int i = 1; i <= n; ++i){
        power[i] = (power[i-1] << 1);
        if(power[i] >= MOD)
            power[i] -= MOD;
    }

    int bad = 0;
    for(int t = 1; t < total_subsets; ++t){
        int contri = power[dp[t]] - 1;
        if(contri < 0) contri += MOD;
        if(__builtin_parity(t)){
            bad += contri;
            if(bad >= MOD)
                bad -= MOD;
        }
        else{
            bad -= contri;
            if(bad < 0)
                bad += MOD;
        }
    }
    int good = power[n] - 1;
    if(good < 0)
        good += MOD;
    good -= bad;
    if(good < 0)
        good += MOD;

    cout<<good<<'\n';
    return 0;
}