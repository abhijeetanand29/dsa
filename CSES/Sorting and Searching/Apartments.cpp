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
#define all(a) a.begin(), a.end()
using namespace std;



void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    
    vv s(n);
    vv a(m);

    int ans = 0;

    F(i,0,n) cin>>s[i];

    F(i,0,m) cin>>a[i];

    sort(all(s));
    sort(all(a));

    int i = 0;
    int j = 0;

    while(i < n && j < m){
        if( s[i] >= a[j] - k && s[i] <=a[j] + k){
            ans++;
            i++;
            j++;
        }
        else if(s[i] >= a[j] + k){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<ans<<endl;

}

int main(){
    int t;
    t = 1;
    while(t--) solve();

    return 0;
}