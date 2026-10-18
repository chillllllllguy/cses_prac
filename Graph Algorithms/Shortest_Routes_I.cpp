#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
struct node{
    LL to, w;
    node(LL _to, LL _w){
        to = _to;
        w = _w;
    }
};
LL n, m;
vector<node> vec[100005];
vector<LL> d;
int main(){
    cin >> n >> m;
    d.assign(n+1, 0x3f3f3f3f3f3f3f3f);
    for(int i=0;i<m;++i){
        LL a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back(node(b, c));
        //vec[b].push_back(node(a, c));
    }
    priority_queue<pair<LL, LL>> q;
    q.push({0, 1});//權重 / 點
    d[1] = 0;
    while(!q.empty()){
        LL w, u;
        tie(w, u) = q.top();
        q.pop();
        if(-w>d[u]) continue;
 
        for(auto i:vec[u]){
            if(d[i.to]>d[u]+i.w){
                d[i.to] = d[u]+i.w;
                q.push({-d[i.to], i.to});
            }
        }
    }
    for(int i=1;i<=n;++i) cout << d[i] << " ";
 
}
