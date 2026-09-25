#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    //vector<LL> Begin(n), End(n);
    vector<pair<LL, int>> p;
    for(int i=0;i<n;++i){
        LL a, b;
        cin >> a >> b;
        p.push_back({a, 1});
        p.push_back({b, -1});
        //cin >> Begin[i] >> End[i];
        
    }
    //sort(Begin.begin(), Begin.end());
    //sort(End.begin(), End.end());
    sort(p.begin(), p.end());
    
    int total = 0, Max = 0;
    int u=0, v=0;
    
    for(auto u:p){
        total += u.second;
        Max = max(Max, total);
    }
    cout << Max << endl;
}
