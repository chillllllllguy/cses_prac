#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL xx[200005] = {}, bit[200005] = {};
int n, m;
int lowbit(int x){
    return x&-x;
}
void bitadd(int x, LL val){
    for(int i=x;i<=n;i+=lowbit(i)) bit[i] += val;
}
LL bitquery(int x){
    LL ans = 0;
    for(int i=x;i>0;i-=lowbit(i)) ans += bit[i];

    return ans;
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> xx[i];
    for(int i=0;i<m;++i){
        int a, b, c;
        LL d;
        cin >> a;
        if(a==1){
            cin >> b >> c >> d;
            bitadd(b, d);
            bitadd(c+1, -d);
        }
        else{
            cin >> b;
            cout << bitquery(b)+xx[b] << endl;
        }
    }
}
