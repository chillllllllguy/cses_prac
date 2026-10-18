#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    multiset<int> l;
    int x, n;
    cin >> x >> n;
    l.insert(x);
    s.insert(0);
    s.insert(x);
    for(int i=0;i<n;++i){
        int a;
        cin >> a;
        auto it1 = s.upper_bound(a);
        auto it2 = prev(it1);
        l.erase(l.find(*it1-*it2));
        l.insert(*it1-a);
        l.insert(a-*it2);
        s.insert(a);
        cout << *l.rbegin() << endl;
    }
}
