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

int mini(int a, int b, vv&arr){
    int w = ( b - a + 1 )/2;
    return min( mini(a,a+w-1,arr) , mini(a+w , b, arr));
}


void solve(){
    int n,q;
    cin>>n>>q;

    vv arr(n);

    F(i,0,n) cin>>arr[i];

    
    for(int i = 0; i < q; i++){
        int a,b;
        cin>>a>>b;
        int ct;
        for(ct = 0; pow(2,ct) <= n; ct++){}
        int k = pow(2,ct);
        cout<< min( mini(a, a + k - 1, arr) , mini( b-k+1,b,arr));
    }
}

int main(){
    int t=1;
    
    while(t--) solve();

    return 0;
}