#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int n, x;
    cin >> n >> x;
    vector<LL> dp(x+5, 1e9);
    dp[0] = 0;
    for(int i=0;i<n;++i){
        LL a;
        cin >> a;
        for(int j=a;j<=x;++j){
            dp[j] = min(dp[j], dp[j-a]+1);
        }
    }
    if(dp[x]>x) cout << -1 << endl;
    else cout << dp[x] << endl;
}
