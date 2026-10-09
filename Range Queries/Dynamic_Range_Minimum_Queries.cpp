
#include <bits/stdc++.h>
using namespace std;
int n, m;
int tree[800005] = {}, x[200005] = {};
int sgbuild(int i, int l, int r){
    if(l==r) tree[i] = x[l];
    else{
        int minl = sgbuild(2*i+1, l, (l+r)/2);
        int minr = sgbuild(2*i+2, (l+r)/2+1, r);
        tree[i] = min(minl, minr);
    }
    return tree[i];
}
int seq(int ql, int qr, int i, int l, int r){
    if(qr<l||r<ql) return INT_MAX;
    else if(ql<=l&&r<=qr) return tree[i];

    int minl = seq(ql, qr, 2*i+1, l, (l+r)/2);
    int minr = seq(ql, qr, 2*i+2, (l+r)/2+1, r);
    return min(minr, minl);
}
int sgadd(int pos, int val, int i, int l, int r){
    if(pos<l||pos>r) ;
    else if(l==r) tree[i] = val;
    else{
        int minl = sgadd(pos, val, 2*i+1, l, (l+r)/2);
        int minr = sgadd(pos, val, 2*i+2, (l+r)/2+1, r);

        tree[i] = min(minl, minr);
    }
    return tree[i];
}
int main(){
    cin >>n >> m;
    for(int i=1;i<=n;++i) cin>>x[i];

    sgbuild(0,1,n);
    for(int i=0;i<m;++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==2){
            cout << seq(b, c, 0, 1, n) << endl;
        }
        else{
            sgadd(b, c, 0, 1, n);
        }
    }
}
