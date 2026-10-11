#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, p[200005][20] = {}, d[200005] = {};
int dp(int i){    //depth
    if(d[i]) return d[i];
    if(i==1) return d[i] = 1;
    return d[i] = dp(p[i][0])+1;
}
int main(){
    cin >> n >> m;
    for(int i=2;i<=n;++i) cin >> p[i][0];

    for(int j=1;j<20;++j){
        for(int i=1;i<=n;++i) p[i][j] = p[p[i][j-1]][j-1];
    }


    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        int x = dp(a), y = dp(b);
        if(x>y){
            swap(x, y);
            swap(a, b);
        }

        y -= x;
        for(int i=19;i>=0;--i){
            if(y&(1<<i)) b = p[b][i];
        }

        if(a==b){
            cout << a << endl;    //a is b's parent
            continue;
        }

        for(int i=19;i>=0;--i){
            if(p[a][i]!=p[b][i]){    //finding the same parent
                a = p[a][i];
                b = p[b][i];
            }
        }
        cout << p[a][0] << endl;
    }
}
