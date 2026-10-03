#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005], a(100005, 0);
vector<int> b;
int n, m;
int ans = 0;
void dfs(int x, int pre){
    for(auto u:v[x]){
        if(u==pre) continue;
        if(a[u]){
            b.push_back(x);
            while(b.back()!=u) b.push_back(a[b.back()]);

            b.push_back(x);
            cout << b.size() << endl;
            for(auto v:b) cout << v<< " ";
            exit(0);
        }
        a[u] = x;
        dfs(u, x);
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        if(a[i]==0){
            a[i]=i;
            dfs(i, 0);
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
