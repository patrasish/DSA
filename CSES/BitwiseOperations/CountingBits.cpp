#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long x = n;
    vector<int>bits;
    while(x > 0){
        int cur = x & 1;
        bits.push_back(cur);
        x >>= 1LL;
    }
    int len = (int)bits.size();
    vector<long long>dp_zero(len), dp_one(len);
    dp_zero[0] = 0; dp_one[0] = 1;
    for(int i = 1; i < len; ++i){
        dp_zero[i] = dp_zero[i-1] + dp_one[i-1];
        dp_one[i] = dp_zero[i] + (1LL << i);
    }
    
    long long res = 0, last_left = 0;
    for(int i = len-1; i >= 0; --i){
        if(bits[i] == 1){
            long long contri1 = dp_zero[i];
            long long contri2 = (((1LL << i) - 1) & n) + 1;
            long long contri = contri1 + contri2;
            res += contri;
        }
        
    }
    cout<<res<<'\n';
}