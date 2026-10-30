#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int dp[67000] = {};
int main(){
    int n;
    cin >> n;
    LL total = n*(n+1)/2;
    if(total%2==1){
        cout << 0;
        return 0;
    }
    total /= 2;
    
    int t = 0;
    const int m = 1000000007;
    
    int Max = 0;
    dp[0]=1;
    /*
    for(int i=1;i<=n;++i){
        for(int j=0;j<=total;++j){
            dp[i][j]+=dp[i-1][j]%m;
            if(j-i>=0)dp[i][j]= (dp[i][j]+dp[i-1][j-i])%m;
        }
    }
    */
    for(int i=2;i<=n;++i){
        for(int j=total;j>=i;--j){
            dp[j] = (dp[j]+dp[j-i])%m;
        }
    }
    cout << dp[total] << endl;
}
