#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL n, x;
    cin >> n >> x;
    vector<pair<LL, LL>> h(n);
    vector<LL> dp(x+5, 0);
    for(int i=0;i<n;++i) cin >> h[i].first;
    for(int i=0;i<n;++i) cin >> h[i].second;
    sort(h.begin(), h.end());

    for(int i=n-1;i>=0;--i){
        for(int j=x;j>=h[i].first;--j){
            dp[j] = max(dp[j], dp[j-h[i].first]+h[i].second);
        }
    }
    cout << dp[x] << endl;
}
