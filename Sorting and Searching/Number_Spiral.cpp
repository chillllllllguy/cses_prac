#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        LL x, y;
        cin >> x >> y;
        //LL Max = min(x, y);
        if(x<=y){
            if(y%2) cout << y*y - x+1 << endl;
            else cout << (y-1)*(y-1) + x << endl;
        }
        else if(x>y){
            if(x%2==0) cout << x*x - y + 1 << endl;
            else cout << (x-1)*(x-1) + y << endl;
        }
    }
}
