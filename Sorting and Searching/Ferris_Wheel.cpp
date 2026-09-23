#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL n, x;
    cin >> n >> x;
    vector<LL> p(n);
    for(int i=0;i<n;++i) cin >> p[i];
    sort(p.begin(), p.end());
    int i = n-1, j = 0;
    LL total = 0;
    while(i>=j){
        if(p[i]+p[j]<=x){
            total++;
            i--;
            j++;
        }
        else{
            total++;
            i--;
        }
    }
    cout << total << endl;
}
