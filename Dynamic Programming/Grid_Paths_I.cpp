#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL mod = 1000000007;
LL dp[1005][1005] = {};
int main(){
    int n;
    cin >> n;
    
    vector<string> s(n+1);
    
    for(int i=0;i<n;++i) cin >> s[i];

    for(int i=0;i<n;++i){
        if(s[i][0]=='*') break;
        dp[i][0] = 1;
    }
    for(int i=0;i<n;++i){
        if(s[0][i]=='*') break;
        dp[0][i] = 1;
    }
    for(int i=1;i<n;++i){
        for(int j=1;j<n;++j){
            if(s[i][j]=='.'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=mod;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
}
