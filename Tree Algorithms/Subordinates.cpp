#include <bits/stdc++.h>
using namespace std;
int n;
int c[200005] = {};
set<int> s;
vector<int> parent(200005, 0);
vector<int> child[200005];
int dfs(int u){
    if(child[u].empty()){
        c[u] = 0;
        return 1;
    }
    for(auto v:child[u]){
        c[u] += dfs(v);
    }
    return c[u]+1;
}
int main(){
    cin >> n;
    
    for(int i=2;i<=n;++i){
        cin >> parent[i];
        child[parent[i]].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;++i) cout << c[i] << " ";
}
