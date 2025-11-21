#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;
int mod_add(int x, int y){
    int res = x + y;
    if(res >= mod)
        res -= mod;
    return res;
}

int main(){
    int n; cin >> n;

    vector<string>grid(n);
    for(string& s : grid) cin >> s;

    // BaseCase
    if((grid[0][0] == '*') || (grid[n-1][n-1] == '*')){
        cout<<0<<'\n';
        return 0;
    }

    // Approch1 :
    // dp[r][c] = number of ways to reach grid[r][c] cell from the top-left cell
    // Transitions : dp[r][c] = 0 if grid[r][c] == '*'
    //                        =   number of ways to reach grid[r-1][c]
    //                          + number of ways to reach grid[r][c-1]
    //                        = dp[r-1][c] + dp[r][c-1]
    // Time Complexiity = O(n^2), Space Complexity = O(n ^ 2)

    // Approch2 :
    // In approach1 while calculating dp[r][c], we only need the information about
    // dp[r-1] row and dp[r] row
    // So we can create only one 1D array dp(n)
    // we'll being going through each row and perform the following ops
    // while traversing r th row dp[c] = dp[c](which equals to dp[r-1][c]) + dp[c-1](which equals to dp[r][c-1])
    // Time Complexiity = O(n^2), Space Complexity = O(n)

    vector<int>dp(n);
    for(int c = 0; c < n; ++c){
        if(grid[0][c] == '*')
            break;
        dp[c] = 1;
    }
    for(int r = 1; r < n; ++r){
        if(grid[r][0] == '*')
            dp[0] = 0;
        for(int c = 1; c < n; ++c){
            dp[c] = (grid[r][c] == '*') ? 0 : mod_add(dp[c], dp[c-1]);
        }
    }
    cout<<dp[n-1];
    return 0;
}