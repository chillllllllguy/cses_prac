#include <bits/stdc++.h>
using namespace std;
int n, m, total = 0;
int parent[100005] = {};
int findparent(int u){
    if(parent[u]!=u) parent[u] = findparent(parent[u]);
    return parent[u];
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i) parent[i] = i;
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;

        int pa = findparent(a), pb = findparent(b);
        if(pa!=pb){
            parent[pb] = parent[pa];
        }

    }
    int p1 = findparent(1);
    vector<pair<int, int>> v;

    for(int i=2;i<=n;++i){
        int pi = findparent(i);
        if(pi!=p1){
            total++;
            v.push_back({p1, pi});
            parent[pi] = parent[p1];
        }
    }
    cout << total << endl;
    for(auto a:v){
        cout << a.first << " " << a.second << endl;
    }
}
