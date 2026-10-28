#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
//multiset<LL> s;
//multimap<LL, LL> m1;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<LL, LL>> x(n);
    for(int i=0;i<n;++i){
        cin >> x[i].first;
        x[i].second = i;
        
    }
    sort(x.begin(), x.end());
    //for(int i=0;i<n;++i) m1.insert({x[i], i});;
 
    for(int i=0;i<n;++i){
        LL t = m-x[i].first;
        int l=0, r = n-1;
        while(l<r){
        
            if(l==i){
                ++l;
                continue;
            }
            if(r==i){
                --r;
                continue;
            };

            if(x[l].first+x[r].first==t){
                cout << x[i].second+1 << " " << x[l].second+1 << " " << x[r].second+1;
                return 0;
            }
            else if(x[l].first+x[r].first<t) ++l;
            else --r;
        }
    }
    cout << "IMPOSSIBLE" << endl;
 
}
