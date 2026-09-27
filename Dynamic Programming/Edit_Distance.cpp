#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005] = {};
int main(){
    memset(dp, 1e9, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    int l1 = s1.size(), l2 = s2.size();

    for(int i=0;i<=l1;++i){
        for(int j=0;j<=l2;++j){
            if(i==0||j==0) dp[i][j] = max(i, j);
            else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
        }
    }
    cout << dp[l1][l2] << endl;
}
