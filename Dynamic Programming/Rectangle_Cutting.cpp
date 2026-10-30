#include <bits/stdc++.h>
using namespace std;
int dp[505][505] = {};
int main(){
    int a, b;
    cin >> a >> b;
    if(a<b) swap(a, b);
    int t = 0;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for(int i=0;i<=a;++i){
        dp[i][i] = 0;
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            for(int k=1;k<i;++k){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;++k){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                
            }
        }
    }
    cout << dp[a][b] << endl;
}
