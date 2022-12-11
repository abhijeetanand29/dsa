#include<bits/stdc++.h>
#define ll long long
#define vv vector<int>
#define ff first
#define ss second
#define pr pair<int,int>
#define inp cin>>
#define out cout<<
#define el endl
#define F(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int main(){
    ios::sync_with_stdio (0); 
    cin.tie (0);
    int n,m;
    cin>>n>>m;
    vector<int> ans (n+1, 0); 
    set<int> alive;
    for (int i=1;i<=n+5; i++) alive.insert(i); 
    while (m--) {
        int l, r, w; cin>>l>>r>>w;
        
        auto iter = alive.lower_bound(l);
        while(*iter <= r && iter != alive.end()){
            if(*iter != w){
                ans[*iter] = w;
                auto kill = iter;
                iter++;
                alive.erase(kill);
            }
            else iter++;
        }
    }
    for (int i = 1; i<=n;i++) cout<<ans [i]<<" ";
    cout<<endl;
}

