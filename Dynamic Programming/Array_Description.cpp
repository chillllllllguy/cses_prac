#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL dp[100005][105] = {};
LL mod = 1000000007;
// -1, 0, 1
int main(){
    LL n, m;
    cin >> n >> m;
    vector<LL> x(n);
    for(int i=0;i<n;++i){
        cin >> x[i];
        if(i==0){
            if(x[i]==0)    
                for(int i=1;i<=m;++i) dp[0][i] = 1;
            else dp[0][x[i]] = 1;
        }
        else if(x[i]!=0){
            dp[i][x[i]] = dp[i-1][x[i]-1]+dp[i-1][x[i]]+dp[i-1][x[i]+1];
            dp[i][x[i]]%=mod;
        }
        else{
            for(int j=1;j<=m;++j){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
                dp[i][j]%=mod;
            }
        }
    }
    int total = 0;
    for(int i=1;i<=m;++i){
        total += dp[n-1][i];
        total%=mod;
    }
    cout << total << endl;
}
