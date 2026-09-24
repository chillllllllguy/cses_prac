#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    multiset<LL> h;
    int n, m;
    cin >> n >> m;
    //vector<LL> h;
    for(int i=0;i<n;++i){
        LL h1;
        cin >> h1;
        h.insert(h1);
    }
    //sort(h.begin(), h.end());
    for(int i=0;i<m;++i){
        LL t;
        cin >> t;
        auto index = h.upper_bound(t);
        if(index!=h.begin()){
            cout << *(--index) << endl;
            h.erase(index);
        }
        else cout << -1 << endl;
    }

}
