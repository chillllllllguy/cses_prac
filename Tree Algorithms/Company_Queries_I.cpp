//Binary Lifting
#include <bits/stdc++.h>
using namespace std;
int up[200005][20] = {};
int n,m;
int main(){
    cin >> n >> m;
    for(int i=2;i<=n;++i){
        cin >> up[i][0];
    }
    for(int j=1;j<20;++j){
        for(int i=1;i<=n;++i){
            if(up[i][j-1]!=0)
                up[i][j] = up[up[i][j-1]][j-1];
            else up[i][j] = 0;
        }
    }
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        for(int j=19;j>=0;--j){
            if((b >> j)&1){
                a = up[a][j];
                if(a==0) break;
            }
        }
        if(a==0) cout << -1 << " ";
        else cout << a << " ";
    }
}
