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

void build(vector<pair<int,pair<int,int>>>& seg, string a, int ind, int low, int high){
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

int query(vector<pair<int,pair<int,int>>>& seg, int ind, int low, int high, int l, int r ){
    if(high < l || low > r){
        return 0;
    }

    if(l <= low && high <= r){
        int ans1 = seg[ind].ff;
        int ans2 = min(seg[2*ind + 1].ss.ff, seg[2*ind+2].ss.ss);
        return ans1 + ans2;
    }

    int mid = low + ( high - low ) / 2;
    int left = query(seg, 2*ind+1, low, mid, l, r);
    int right = query(seg, 2*ind+2, mid+1, high, l, r);
    int ans1 = left + right;
    int ans2 = min(seg[2*ind + 1].ss.ff, seg[2*ind+2].ss.ss);
    return ans1 + ans2;
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    vector<pair<int,pair<int,int>>> seg(4*n+10);
    F(i,0,4*n+10){
        seg[i].ff = 0;
        seg[i].ss.ff = 0;
        seg[i].ss.ss = 0;
    }

    build(seg, s, 0, 0, n-1);

    // F(i,0,4*n+10) cout<<seg[i].ff<<" "; cout<<endl;

    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        cout<<2*query(seg,0,0,n-1,l,r)<<endl;
    }
}

int main(){
    int t;
    t = 1;
    while(t--) solve();

    return 0;
}