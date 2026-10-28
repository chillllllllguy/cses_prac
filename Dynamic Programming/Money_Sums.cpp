#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;++i) cin >> x[i];
    sort(x.begin(), x.end(), greater<int>());
    bool a[100005] = {};
    int Max = x[0];
    a[x[0]] = 1;
    int t = 0;
    for(int i=1;i<n;++i){

        for(int j=Max;j>=0;--j){
            if((j==0||a[j]==1)&&a[j+x[i]]==0){
                a[j+x[i]] = 1;
                ++t;
            }
            if(j==Max) Max += x[i];
        }
    }
    cout << t+1 << endl;
    for(int i=0;i<=Max;++i){
        if(a[i]==1) cout << i << " ";
    }
}
