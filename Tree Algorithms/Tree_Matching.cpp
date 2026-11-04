//dp
#include <bits/stdc++.h>
using namespace std;
int dp[200005][2];
vector<int> adj[200005];
vector<pair<int, int>> k;
int n, a, b;
/*
int findparent(int u){
    if(parent[u]==u) return u;
    else return findparent(parnet[u]);
}
*/
void dfs(int u, int pre){
    int s = 0;
    for(auto v:adj[u]){
        if(v==pre) continue;
        dfs(v, u);
        s+=max(dp[v][0], dp[v][1]);
    }
    dp[u][0] = s;
    dp[u][1] = 0;
    for(auto v:adj[u]){
        if(v==pre) continue;
        dp[u][1] = max(dp[u][1], s-max(dp[v][0], dp[v][1])+1+dp[v][0]);

    }
}
int main(){
    cin >> n;
    //for(int i=1;i<=n;++i) parent[i] = i;
    for(int i=1;i<n;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    cout << max(dp[1][1], dp[1][0]) << endl;
}
