//bitmask
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int n, m;
int main(){
    cin >> n >> m;
    vector<LL> a(n), weight(1<<n, 0);
    vector<int> dp(1<<n, 0x3f3f3f3f);
    for(int i=0;i<n;++i) cin >> a[i];
    dp[0] = 1;
    for(int mask=0;mask<(1<<n);++mask){
        if(dp[mask]==0x3f3f3f3f) continue;
        for(int j=0;j<n;++j){
            if(!(mask&(1<<j))){
                int nextmask = mask|(1<<j);

                int nextdp;
                LL nextw;
                if(weight[mask]+a[j]<=m){
                    nextdp = dp[mask];
                    nextw = weight[mask]+a[j];
                }
                else{
                    nextdp = dp[mask] + 1;
                    nextw = a[j];
                }

                if(nextdp<dp[nextmask]){
                    dp[nextmask] = nextdp;
                    weight[nextmask] = nextw;
                }
                else if(dp[nextmask]==nextdp){
                    weight[nextmask] = min(weight[nextmask], nextw);
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}
