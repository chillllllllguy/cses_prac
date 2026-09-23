#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL n, total = 0;
    cin >> n;
    vector<LL> a(n);
    cin >> a[0];
    for(int i=1;i<n;++i){
        cin >> a[i];
        if(a[i]<a[i-1]){
            total += a[i-1]-a[i];
            a[i] = a[i-1];
        }
    }
    cout << total << endl;

}
