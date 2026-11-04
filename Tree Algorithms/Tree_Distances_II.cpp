#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int n, a, b;
vector<LL> adj[200005];
vector<LL> ans, s;
void dfs(int u, int pre, LL d){
    ans[1] += d;
    for(auto v:adj[u]){
        if(v==pre) continue;
        dfs(v, u, d+1);
        s[u] += s[v];
    }
    s[u]++;
}
void dfss(int u, int pre){
    for(auto v:adj[u]){
        if(v==pre) continue;
        //(變長) - 變短  
        ans[v] = ans[u]+(n-s[v])-s[v];
        dfss(v, u);
    }
}
int main(){
    cin >> n;
    s.assign(n+5, 0);
    ans.assign(n+5, 0);
    for(int i=1;i<n;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0, 0);
    dfss(1, 0);
    for(int i=1;i<=n;++i) cout << ans[i] << " ";
}
