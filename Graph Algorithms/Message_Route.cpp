#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> v(100001);
vector<int> p(100001, 0);
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i) p[i] = i;
    p[1] = 0;
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    int ans = 0, len = 0;
    while(!q.empty()){
        int iter, l;
        tie(iter, l) = q.front();
        q.pop();
        for(auto u:v[iter]){
            if(u==n){
                p[u] = iter;
                ans = 1;
                len = l;
                break;
            }
            else if(p[u]==u){
                p[u] = iter;
                q.push({u, l+1});
            }
        }
        if(ans) break;
    }
    if(ans){
        vector<int> v;
        int pre = n;
        while(p[pre]!=0){
            v.push_back(pre);
            pre = p[pre];
        }
        v.push_back(1);
        reverse(v.begin(), v.end());
        cout << v.size() << endl;
        for(auto u:v) cout << u << " ";
    }
    else cout << "IMPOSSIBLE" << endl;
}
