#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int n;
int main(){
    cin >> n;
    vector<LL> lis;
    for(int i=0;i<n;++i){
        LL a;
        cin >> a;
        if(lis.empty()) lis.push_back(a);
        else{
            auto k = lower_bound(lis.begin(), lis.end(), a);
            if(k==lis.end()){
                lis.push_back(a);

            }
            else{
                *k = a;
            }
        }
    }
    cout << lis.size() << endl;
}
