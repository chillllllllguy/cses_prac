#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long> v(n-1);
    for(int i=0;i<n-1;++i) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i=0;i<n;++i){
        if(v[i]!=i+1){
            cout << i+1 << endl;
            return 0;
        }
    }
}
