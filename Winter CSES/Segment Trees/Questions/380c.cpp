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

void build(vector<pair<int,pair<int,int>>>& seg, int a[], int ind, int low, int high){
    if(low == high){
        seg[ind].ff = 0;
        if(a[low] == '(')seg[ind].ss.ff = 1;
        else seg[ind].ss.ss = 1;
        return;
    }

    int mid = (low + high) / 2;
    build(seg, a, 2*ind+1, low , mid);
    build(seg, a, 2*ind+2, mid+1 , high);

    seg[ind].ff += min(seg[2*ind + 1].ss.ff, seg[2*ind+2].ss.ss);
    seg[ind].ff += seg[2*ind+1].ff;
    seg[ind].ff += seg[2*ind+2].ff;
    
    if(seg[2*ind + 1].ss.ff < seg[2*ind+2].ss.ss){
        seg[2*ind+2].ss.ss -= seg[2*ind + 1].ss.ff;
        seg[2*ind + 1].ss.ff = 0;
    }
    else{
        seg[2*ind + 1].ss.ff -= seg[2*ind+2].ss.ss;
        seg[2*ind + 2].ss.ss = 0;
    }
    seg[ind].ss.ff += seg[2*ind + 1].ss.ff;
    seg[ind].ss.ff += seg[2*ind + 2].ss.ff;
    seg[ind].ss.ss += seg[2*ind + 1].ss.ss;
    seg[ind].ss.ss += seg[2*ind + 2].ss.ss;
}

void solve(){
    
    
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}