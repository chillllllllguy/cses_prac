#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<LL> v(n);
    for(int i=0;i<n;++i)cin >> v[i];
    sort(v.begin(), v.end());
    LL x = 1;
    for(int i=0;i<n;++i){
        if(v[i]>x){
            cout << x << endl;
            return 0;
        }
        x+=v[i];
    }
    cout << x << endl;
}
