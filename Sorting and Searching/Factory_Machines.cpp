#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL n, t;
    cin >> n >> t;
    vector<LL> a(n);
    for(int i=0;i<n;++i) cin >> a[i];
    sort(a.begin(), a.end());
    LL L = 0, R = a[n-1]*t;
    LL r = R, l = L;
    LL ans = 0;
    while(l<r){
        LL total = 0;
        LL mid = (l+r)/2;
        int i;
        for(i=0;i<n;++i){
            total += mid/a[i];
            if(total>=t) break;
        }
        if(total<t) l = mid+1;
        else{
            ans = mid;
            r = mid;
        }
    }
    cout << r << endl;
}
