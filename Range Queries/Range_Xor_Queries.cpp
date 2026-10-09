#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[200005] = {}, prefix[200005] = {};
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> x[i];
        if(i==1) prefix[i] = x[i];
        else prefix[i] = prefix[i-1]^x[i];
    }
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        cout << (prefix[b]^prefix[a-1]) << endl;
    }
}
