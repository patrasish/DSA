#include <iostream>
#include <vector>
#include <algorithm>

const int INF = (int)1e9;

int main(){
    int n, target; 
    std::cin >> n >> target;
    
    std::vector<int> coins(n);
    for(int i = 0; i < n; ++i)
        std::cin>> coins[i];
    
    std::vector<int> dp(target + 1, INF); // dp[i] = minimum number of coins required that sum up to target
    dp[0] = 0; // for target = 0, we require no coins

    for(int i = 0; i < n; ++i){
        int contri = coins[i];
        for(int t = contri; t <= target; ++t)
            dp[t] = std::min(dp[t], 1 + dp[t-contri]);
    }

    int res = (dp[target] == INF) ? -1 : dp[target];
    std::cout<<res<<std::endl;

    return 0;
}