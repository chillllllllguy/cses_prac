#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n+5, 1000005);
    //dp[0] = 1;
    string s;
    dp[0] = 0;
    for(int i=1;i<=9;++i) dp[i] = 1;
    for(int i=10;i<=n;++i){
        s = to_string(i);
        for(int j=1;j<=9;++j){
            if(s.find(to_string(j))!=string::npos){
                dp[i] = min(dp[i], dp[i-j]+1);
            }
        }
    }
    
    cout << dp[n] << endl;
}
