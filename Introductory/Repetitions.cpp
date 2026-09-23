#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    char pre = s[0];
    long long n = 1;
    long long Max = 1;
    for(int i=1;i<s.size();++i){
        if(pre!=s[i]){
            Max = max(Max, n);
            n = 1;
            pre = s[i];
        }
        else ++n;
    }
    Max = max(Max, n);
    cout << Max << endl;
}
