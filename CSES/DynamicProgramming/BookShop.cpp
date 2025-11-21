#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, budget;
    cin >> n >> budget;

    vector<int> prices(n), pages(n);
    for(int& price : prices) cin >> price;
    for(int& page : pages) cin >> page;

    // Approach1 :
    // dp[i][j] = maximum number of pages we can buy if we are given books[0, i] with budget j.
    // Transitions :
    // dp[i][j] = max(not-take i-th book , take i-th book)
    //          = max(dp[i-1][j]         , (j >= prices[i]) ? pages[i] + dp[i-1][j - prices[i]] : 0)
    // TimeComplexity = O(n * budget), SpaceComplexity = O(n * budget)

    // Approach2 :
    // while calculating the dp[i][j] we only need the information about i-th and (i-1)-th row
    // We can create an 1-D array dp(budget) and do the following ops
    // we will go through each book 
    // while we are with the i-th book for budget j
    // dp[j] = max(dp[j] (= dp[i-1][j]) , (dp[j - prices[i]] + pages[i]) (= dp[i-1][j - prices[i]]))
    // But this can leads to overcounting
    // So we have to traverse j in descending order
    // TimeComplexity = O(n * budget), SpaceComplexity = O(budget)

    vector<int>dp(budget+1);
    for(int cur_budget = prices[0]; cur_budget <= budget; ++cur_budget) dp[cur_budget] = pages[0];
    for(int i = 1; i < n; ++i){
        for(int cur_budget = budget; cur_budget >= prices[i]; --cur_budget)
            dp[cur_budget] = max(dp[cur_budget], dp[cur_budget - prices[i]] + pages[i]);
    }
    cout<<dp[budget];
    return 0;
}