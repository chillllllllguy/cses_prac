#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> m;
int l = 0;
int Max = 1;
int main(){
    cin >> n;
    vector<int> v(n+1);
    for(int i=1;i<=n;++i){
        cin >> v[i];
        auto iter = m.find(v[i]);
        if(iter!=m.end()){
            int a = iter->second;
            l = max(l, a);
            m.erase(v[i]);
        }
        m.insert({v[i], i});
        Max = max(Max, i-l);
    }
    cout << Max << endl;
}
