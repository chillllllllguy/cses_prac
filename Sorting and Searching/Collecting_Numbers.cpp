#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n), re(n+1);
    for(int i=0;i<n;++i){
        cin >> v[i];
        re[v[i]] = i;
    }
    int total = 0;
    for(int i=1;i<=n;++i){
        if(re[i]<re[i-1]) total++;
    }
    cout << total+1 <<endl;
}
//4 2 1 5 3

//1 2 3 4 5
//2 1 4 0 3
