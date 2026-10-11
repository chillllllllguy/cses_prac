#include <bits/stdc++.h>
using namespace std;
int main(){
    long long total = 0;
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long totalk = 0;
    total = v[n/2];
    for(int i=0;i<n;++i){
        totalk += abs(v[i]-total);
    }
    cout << totalk << endl;
}
