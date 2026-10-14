//Z-Algorithm
#include <bits/stdc++.h>
using namespace std;
int z[1000005] = {};
vector<int> ans;
int main(){
    int l=0, r=0;
    string s, s1;
    cin >> s;
    int len = s.size();
    for(int i=1;i<len;++i){
        if(i<=r&&z[i-l]<r-i+1){
            z[i] = z[i-l];
        }
        else{
            l = i;
            if(i>r) r = i;
            while(r<len&&s[r-l]==s[r]) ++r;
            --r;
            z[l] = r-l+1;
        }
        if(z[i]==len-i)
            ans.push_back(len-i);
    }
    sort(ans.begin(), ans.end());
    for(auto a:ans) cout << a << " ";
    
    
}
