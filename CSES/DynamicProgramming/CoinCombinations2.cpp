#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

void add_self(int& original, int val){
    original += val;
    if(original >= mod)
        original -= mod;
}

int main(){
    int n, target;
    cin >> n >> target;

    vector<int>coins(n);
    for(int& coin : coins) cin >> coin;

    // out target is combinations of x_i is there such that summation of x_i * c_i = target for i in [0, n)
    
    vector<int>dp(target + 1);
    // dp[i] = number of ways to get a sum upto i

    // Transitions:
    // we'll traverse through the coins array and for each coin we'll compute
    // the number of ways to make target with that coin including already traversed coins
    // dp[i] = without using that coin + with using that coin
    //       = dp[i] + (i >= coin_val) ? dp[i-coin] : 0

    dp[0] = 1; 
    // ways of making target = 0 is 1(In this case we'll not use any coin and there is no coin with value 0)

    for(int coin : coins){
        for(int cur_target = coin; cur_target <= target; ++cur_target)
            add_self(dp[cur_target], dp[cur_target - coin]);
    }
    cout<<dp[target];
    return 0;
}