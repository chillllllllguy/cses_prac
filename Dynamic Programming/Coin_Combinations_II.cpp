#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL mod = 1000000007;
    int n, x;
    cin >> n >> x;
    vector<LL> dp(x+5, 0), a(n);
    dp[0] = 1;
    
    for(int i=0;i<n;++i){
        cin >> a[i];
        
    }
    sort(a.begin(), a.end());
    for(int j=0;j<n;++j){
        for(int i=1;i<=x;++i){
            if(i-a[j]>=0){
                dp[i] += dp[i-a[j]];
                dp[i]%=mod;
            }
        }
    }
    
    cout << dp[x] << endl;
}
