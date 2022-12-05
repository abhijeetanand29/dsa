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
class SGTree{
    vector<int> seg;
    public:
    SGTree(int n){
        seg.resize(4*n+10);
    }

    void build(int a[], int ind, int low, int high){
        if(low == high){
            seg[ind] = a[low];
            return;
        }

        int mid = (high + low) / 2;

        build(a, 2*ind + 1, low, mid);
        build(a, 2*ind + 2, mid+1, high);

        seg[ind] = min( seg[2*ind + 1], seg[2*ind + 2] );
    }

    int query(int ind, int low, int high, int l, int r ){
        
        if(high < l || low > r){
            return INT_MAX;
        }

        if(l <= low && high <= r){
            return seg[ind];
        }

        int mid = low + ( high - low ) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = ( low + high ) / 2;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind + 2, mid + 1, high, i, val);

        seg[ind] = min( seg[2*ind + 1], seg[2*ind + 2] );
    }

};


void solve(){
    int n;
    cin>>n;
    int a[n];
    F(i,0,n) cin>>a[i];
    SGTree S1(n);
    S1.build(a, 0, 0, n-1);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>> type;
        if(type == 1){
            int l,r;
            cin>>l>>r;
            cout<<S1.query(0, 0, n-1, l, r)<<endl;
        }
        else if (type == 2){
            int i, val;
            cin>> i>> val;
            S1.update(0, 0, n-1, i, val);
            a[i] = val;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}