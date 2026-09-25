#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[1000005] = {};
int main(){
    LL m = 1000000007;
    
    dp[0] = 1;
/*
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    dp[4] = 8;

1 1 1 1
2 1 1
1 2 1
1 1 2
3 1
1 3
2 2
4
    */
   LL n;
    cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=i-6;j<i;++j){
            if(j<0) continue;
            dp[i] += dp[j];
            dp[i] %= m;
        }
    }
    cout << dp[n] << endl;
}
