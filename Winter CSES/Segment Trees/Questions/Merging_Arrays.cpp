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

void solve(){
    int n,m;
    cin>>n>>m;

    int a[n];
    int b[m];

    map<int,int> f;
    map<int,int> s;

    F(i,0,n){
        cin>>a[i];
        f[a[i]]++;
    }
    F(i,0,m){
        cin>>b[i];
        s[b[i]]++;
    }

    for(auto &it:f){
        if(s.find(it.first) != s.end()){
            auto iter = s.find(it.first);
            int num2 = *iter;
        }
    }


    
}

int main(){
    int t;
    t = 1;
    while(t--) solve();

    return 0;
}