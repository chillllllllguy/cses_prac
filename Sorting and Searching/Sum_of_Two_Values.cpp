#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    LL n, x;
    cin >> n >> x;
    multimap<LL, LL> m;
    for(LL i=0;i<n;++i){
        LL a;
        cin >> a;
        m.insert({a, i+1});
    }
    for(auto u:m){

        auto it = m.find(x-u.first);
        if(it!=m.end()&&u.second!=it->second){
            cout << min(u.second, it->second) << " "<< max(u.second, it->second)<< endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
