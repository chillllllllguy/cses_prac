#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200005];
//vector<int> parnet(200005, 0);
int n;
int Max = 0;
int c1 = 0;
void dfs(int c, int pre, int len){
    if(vec[c].empty()){
        if(Max<len){
            Max = len;
            c1 = c;
        }
    }
    int k = 0;
    for(auto v:vec[c]){
        if(v == pre) continue;
        k = 1;
        dfs(v, c, len+1);
    }
    if(k==0){
        if(Max<len){
            Max = len;
            c1 = c;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n-1;++i){
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);

    }
    dfs(1, 0, 0);
    Max = 0;
    dfs(c1, 0, 0);
    cout << Max << endl;
}
