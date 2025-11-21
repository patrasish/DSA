#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<int>dp(n+1);
    // dp[i] = min number of operations to make i equals to zero.

    // Transitions:
    // dp[i] = 0 if i = 0
    //       = 1 + min({dp[i-d]}) where d is a digit in i

    for(int num = 1; num <= n; ++num){
        int temp_num = num;
        dp[num] = n; // initializing dp[num] with a valule x such that x >= dp[num]
        while(temp_num > 0){
            int d = temp_num % 10;
            dp[num] = min(dp[num], dp[num - d] + 1);
            temp_num /= 10;
        }
    }
    cout<<dp[n];
    return 0;
}