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
int main(){
    cin >>n >> m;
    for(int i=1;i<=n;++i) cin>>x[i];

    sgbuild(0,1,n);
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        if(a>b)swap(a, b);
        cout << seq(a, b, 0, 1, n) << endl;
    }
}
