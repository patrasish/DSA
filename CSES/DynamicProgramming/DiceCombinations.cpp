#include <iostream>
#include <vector>
#include <algorithm>

const int mod = (int)1e9 + 7;

int self_add(int& original, int value){
    original += value;
    if(original >= mod)
        original -= mod;
    return original;
}

int main(){
    int n; std::cin >> n;

    std::vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int last_outcome = 1; last_outcome <= std::min(6, i); ++last_outcome){
            self_add(dp[i], dp[i-last_outcome]);
        }
    }
    std::cout<<dp[n]<<std::endl;
    return 0;
}