#include <bits/stdc++.h>
using namespace std;
int n, m;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int a[1005][1005] = {};
vector<string> s(1005);
void bfs(int i, int j){
    a[i][j] = 1;
    for(int k=0;k<4;++k){
        int ii = i+dir[k][0], ji = j+dir[k][1];
        if(ii<0||ji<0||ii>=n||ji>=m) continue;

        if(a[ii][ji]==0&&s[ii][ji]=='.') bfs(ii, ji);
    }
    return ;
}
int main(){
    
    cin >> n >> m;
    
    for(int i=0;i<n;++i) cin >> s[i];
    int total = 0;
    
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(a[i][j]==0&&s[i][j]=='.'){
                total++;
                bfs(i, j);
            }
        }
    }
    cout << total << endl;
}
