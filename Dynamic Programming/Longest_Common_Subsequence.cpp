//LCS
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005] = {}, a[1005], b[1005];
int n, m;
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=m;++i) cin >> b[i];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int u = n, v = m;
    vector<int> ans;
    while(u>0&&v>0){
        if(a[u]==b[v]){
            ans.push_back(a[u]);
            u--;
            v--;
        }
        else if(dp[u-1][v]>=dp[u][v-1]) u--;
        else v--;
    }
    reverse(ans.begin(), ans.end());
    cout << dp[n][m] << endl;
    for(auto i:ans) cout << i << " ";

}
