#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005];
//vector<int> parnet(200005, 0);
int n;
int h = 0; 
int Maxit = 0;
vector<int> dfs(int u){
    vector<int> c(200005, -1);

    queue<int> q;
    q.push(u);
    c[u]++;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto v:vec[cur]){
            if(c[v]!=-1) continue;
            q.push(v);
            c[v] = c[cur]+1;
        }
    }
    return c;
}
int main(){
    cin >> n;
    for(int i=0;i<n-1;++i){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);

    }
    vector<int> ret = dfs(1);
    for(int i=1;i<=n;++i)
        if(ret[i]>ret[Maxit]) Maxit = i;
    vector<int> ans = dfs(Maxit);
    Maxit= 0;
    for(int i=1;i<=n;++i)
        if(ans[i]>ans[Maxit]) Maxit = i;
    ret = dfs(Maxit);
    for(int i=1;i<=n;++i) cout << max(ret[i], ans[i]) << " ";
}
