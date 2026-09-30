#include <bits/stdc++.h>
using namespace std;
int n, m;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
char c[4] = {'R', 'D', 'U', 'L'};
int a[1005][1005] = {};
tuple<int, int, char> parent[1005][1005] = {};
int si, sj, ei, ej;
int ans = 0;
vector<string> s(1005);
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> s[i];
        for(int j=0;j<m;++j){
            if(s[i][j]=='A'){
                si = i;
                sj = j;
            }
        }
    }
    queue<tuple<int, int>> q;
    q.push({si, sj});
    a[si][sj] = 1;
    //string s2;
    while(!q.empty()){
        int ii, ji;
        tie(ii, ji) = q.front();
        q.pop();
        //a[ii][ji] = 1;
        for(int k=0;k<4;++k){
            int iii = ii+dir[k][0], jii = ji+dir[k][1];
            if(iii<0||jii<0||iii>=n||jii>=m) continue;
            else if(s[iii][jii]=='B'){
                ei = iii;
                ej = jii;
                parent[iii][jii] = {ii, ji, c[k]};
                ans = 1;
                break;
            }
            else if(a[iii][jii]==0&&s[iii][jii]!='#'){
                a[iii][jii] = 1;
                parent[iii][jii] = {ii, ji, c[k]};
                q.push({iii, jii});
            }
        }
        if(ans) break;
    }
    if(!ans)cout << "NO" << endl;
    else{
        cout << "YES\n";
        int iii, jii;
        char c1;
        tie(iii, jii, c1) = parent[ei][ej];
        string s1;
        s1 += c1;
        while(iii!=si||jii!=sj){
            int k=iii, l=jii;
            //char c2;
            tie(iii, jii, c1) = parent[k][l];
            s1 += c1;
        }
        cout << s1.size() <<endl;
        reverse(s1.begin(), s1.end());
        cout << s1 << endl;
    }


}
