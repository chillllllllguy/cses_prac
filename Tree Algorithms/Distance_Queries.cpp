#include <bits/stdc++.h>
using namespace std;
int n, q, a, b;
vector<int> h(200005);
vector<int> edge[200005];
int up[200005][20];
void dfs(int node, int pre){
    for(auto u:edge[node]){
        if(u==pre) continue;
        up[u][0] = node;
        h[u] = h[node]+1;
        dfs(u, node);
    }
}
int k = 0;
int main(){
    cin >> n >> q;
    for(int i=1;i<n;++i){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    
    }
    h[1] = 0;
    dfs(1, -1);
    for(int i=1;i<20;++i){
        for(int j=1;j<=n;++j){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }
    for(int i=0;i<q;++i){
        cin >> a >> b;
        int x, y;
        x = h[a];
        y = h[b];
        if(x<y){
            swap(x, y);
            swap(a, b);
        }
        int diff = x-y;
        for(int j=0;j<20;++j){
            if(diff>>j & 1) a = up[a][j];
        }
        if(a==b){
            cout << (x+y)-2*h[a] << endl;
            continue;
        }
        for(int j=19;j>=0;--j){
            if(up[a][j]!=up[b][j]){
                a = up[a][j];
                b = up[b][j];
            }
        }
        cout << (x+y)-2*h[up[a][0]] << endl;
    }

}
