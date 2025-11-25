#include <bits/stdc++.h>
using namespace std;

const int nax = (int)1e6;
int req_bits;

void cal_req_bits(){
    int cur = 1;
    req_bits = 1;
    while(cur < nax){
        ++req_bits;
        cur = (cur << 1) | 1;
    }
}

int main(){
    int n; cin >> n;
    vector<int>nums(n);
    for(int& x : nums) cin >> x;

    cal_req_bits();

    int total_subsets = 1 << req_bits;
    vector<int>dp1(total_subsets), dp2(total_subsets), dp3(total_subsets);
    for(int x : nums){
        ++dp1[x];
        ++dp2[x];
    }

    for(int bit_pos = 0; bit_pos < req_bits; ++bit_pos){
        for(int p = 1; p < total_subsets; ++p){
            if(p & (1 << bit_pos))
                dp1[p] += dp1[p ^ (1 << bit_pos)];
        }
    }
    for(int bit_pos = 0; bit_pos < req_bits; ++bit_pos){
        for(int p = total_subsets - 1; p > 0; --p){
            if(p & (1 << bit_pos))
                dp2[p ^ (1 << bit_pos)] += dp2[p];
        }
    }
    int temp = total_subsets - 1;
    for(int x : nums)
        dp3[x] = n - dp1[x ^ temp];
    for(int x : nums) cout<<dp1[x]<<' '<<dp2[x]<<' '<<dp3[x]<<'\n';
    return 0;
}