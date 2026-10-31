#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL dp[1000005][2] = {};//middle
LL m = 1000000007;
int main(){
    int t;
    cin >> t;
    dp[1][1] = 1;//a
    dp[1][0] = 1;//b
    for(int i=2;i<=1000000;++i){
        dp[i][1] = (2*dp[i-1][1] + dp[i-1][0])%m;
        dp[i][0] = (dp[i-1][1] + 4*dp[i-1][0])%m;
    }
    while(t--){
        int n;
        cin >> n;
        cout <<  (dp[n][0]+dp[n][1])%m << endl;
    }
}
