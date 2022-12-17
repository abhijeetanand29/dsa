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
    int n,x;
    cin>>n>>x;
    vv w(n);

    F(i,0,n) cin>>w[i];

    sort(all(w));
    int ans = 0;
    int i,j;
    for( i = 0, j = n-1; i<j; ){
        if(w[i] + w[j] <= x){
            ans++;
            i++;
            j--;
        }
        else{
            j--;
            ans++;
        }
    }
    if(i ==j) ans++;
    cout<<ans<<endl;
}

int main(){
    int t;
    t = 1;
    while(t--) solve();

    return 0;
}