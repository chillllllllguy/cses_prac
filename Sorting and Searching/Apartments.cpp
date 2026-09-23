#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<LL> a(n), b(m), c(m, 0);
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<m;++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    LL j = 0, i = 0, total = 0;
    while(i<n&&j<m){
        if(b[j]<a[i]-k) ++j;
        else if(b[j]>a[i]+k) ++i;
        else{
            if(c[j]==1) ++j;
            else if(c[j]==0){
                c[j]+=1;
                total++;
                ++i;
            }
        }
    }
    cout << total << endl;
}
