#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m;
LL tree[800005] = {}, x[200005] = {};
LL sgbuild(LL i, LL l, LL r){
    if(l==r) tree[i] = x[l];
    else{
        LL tl = sgbuild(2*i+1, l, (l+r)/2);
        LL tr = sgbuild(2*i+2, (l+r)/2+1, r);
        tree[i] = tl+tr;
    }
    return tree[i];
}
LL seq(LL ql, LL qr, LL i, LL l, LL r){
    if(qr<l||r<ql) return 0;
    else if(ql<=l&&r<=qr) return tree[i];

    LL tl = seq(ql, qr, 2*i+1, l, (l+r)/2);
    LL tr = seq(ql, qr, 2*i+2, (l+r)/2+1, r);
    return tl+tr;
}
LL sgadd(LL pos, LL val, LL i, LL l, LL r){
    if(pos<l||pos>r) ;
    else if(l==r) tree[i] = val;
    else{
        LL tl = sgadd(pos, val, 2*i+1, l, (l+r)/2);
        LL tr = sgadd(pos, val, 2*i+2, (l+r)/2+1, r);
        tree[i] = tl+tr;
    }
    return tree[i];

}
int main(){
    cin >>n >> m;
    for(int i=1;i<=n;++i) cin>>x[i];

    sgbuild(0,1,n);
    for(int i=0;i<m;++i){
        LL a, b, k;
        cin >> k >> a >> b;
        if(k==2){
            if(a>b)swap(a, b);
            cout << seq(a, b, 0, 1, n) << endl;
        }
        else{
            sgadd(a, b, 0, 1, n);
        }
    }
}
