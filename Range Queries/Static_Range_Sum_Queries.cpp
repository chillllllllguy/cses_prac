#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n>>m;
    vector<long long> a(n+5, 0);
    for(int i=1;i<=n;++i){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    for(int j=0;j<m;++j){
        int b, c;
        cin>>b >> c;
        cout << a[c] - a[b-1]<< endl;
    }
}
