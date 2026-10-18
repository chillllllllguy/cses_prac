#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    //upper
    vector<int> v;
    for(int i=0;i<n;++i){
        int a;
        cin >> a;

        if(v.empty()){
            v.push_back(a);
        }
        else if(upper_bound(v.begin(), v.end(), a)==v.end()) v.push_back(a);
        else{
            int k = upper_bound(v.begin(), v.end(), a) - v.begin();
            v[k] = a;
            int n1 = v.size();
            while(k<=n1-2&&v[k]>v[k+1]){
                swap(v[k], v[k+1]);
                ++k;
            }
        }
        

    }
    cout << v.size() << endl;
}
