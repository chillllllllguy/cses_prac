#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL n, Max = 0, cur = 0;
    cin >> n;
    vector<LL> v(n+1, 0);
    cin >> v[1];
    cur = v[1];
    Max = cur;
    for(int i=2;i<=n;++i){
        cin >> v[i];
        cur = max(cur+v[i], v[i]);
        Max = max(Max, cur);

    }
    cout << Max << endl;
}
