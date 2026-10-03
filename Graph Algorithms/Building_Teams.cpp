#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(100005);
vector<int> a(100005, 0);
int n, m;
int main(){
    //dfs
    cin >> n >>m;
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    stack<int> s;
    for(int i=1;i<=n;++i){
        if(i==1){
            a[1] = 1;
            s.push(1);
        }
        else if(a[i]==0){
            s.push(i);
            a[i] = 1;
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            for(auto u:v[t]){
                if(a[u]==a[t]){
                    cout << "IMPOSSIBLE" << endl;
                    return 0;
                }
                else if(a[u]==0){
                    a[u] = a[t]%2+1;
                    s.push(u);
                }
            }
        }
    }
    for(int i=1;i<=n;++i) cout << a[i] << " ";
}
