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

    vector<int>dp(target + 1); 
    // dp[i] =  number of ways to make a sum equals to i using the given coins
    
    // Transitions : 
    // dp[i] = summation of dp[i - x] for all x <= i in coin (i.e. if we know dp[i-x], then we can append coin with value x to get dp[i])

    dp[0] = 1; 
    // ways of making target = 0 is 1(In this case we'll not use any coin and there is no coin with value 0)

    for(int cur_target = 1; cur_target <= target; ++cur_target){
        for(int coin : coins){
            if(cur_target >= coin)
                add_self(dp[cur_target], dp[cur_target - coin]);
        }
    }
    cout<<dp[target];
    return 0;
}
