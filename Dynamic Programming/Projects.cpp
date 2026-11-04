#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
tuple<LL, LL, LL> v[200005];
pair<LL, LL> dp[200005];
LL n;
LL a, b;
LL c;
int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        
        cin >> a >> b >> c;
        v[i] = {b, a, c};
    }
    LL Max = 0;
    sort(v, v+n);
    //int st = a, en = b;
    for(int i=0;i<n;++i){
        tie(b, a, c) = v[i];
        int id = lower_bound(dp, dp+i, make_pair(a, LLONG_MIN)) - dp;
        --id;
        LL k1, k2;
        if(id>=0){
            k1 = dp[id].second;
        }
        else k1 = 0;
        if(i>0) k2 = dp[i-1].second;
        else k2 = 0;
        Max = max(Max, max(k1+c, k2));
        dp[i] = {b, max(k1+c, k2)};
    }
    cout << Max << endl;
}
