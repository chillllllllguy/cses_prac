#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL v[505][505];
int n, m, u;
int main(){
    cin >> n >> m >> u;
    memset(v, 0x3f3f3f3f3f3f3f3f, sizeof(v));
    for(int i=1;i<=n;++i) v[i][i] = 0;
    for(int i=0;i<m;++i){
        LL a, b, c;
        cin >> a >> b >> c;
        v[a][b] = min(v[a][b], c);
        v[b][a] = min(v[b][a], c);
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(v[i][k]!=0x3f3f3f3f3f3f3f3f&&v[k][j]!=0x3f3f3f3f3f3f3f3f)v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
    for(int i=0;i<u;++i){
        int a, b;
        cin >> a >> b;
        if(v[a][b] == 0x3f3f3f3f3f3f3f3f) cout << -1 << endl;
        else cout << v[a][b] << endl;
    }
}
