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
    public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n+10);
    }

    void build(int a[], int ind, int low, int high, int level){
        if(low == high){
            seg[ind] = a[low];
            return;
        }

        int mid = (high + low) / 2;

        build(a, 2*ind + 1, low, mid, level + 1);
        build(a, 2*ind + 2, mid+1, high, level + 1);

        if(level%2 == 0) seg[ind] = seg[2*ind + 1] | seg[2*ind + 2];
        else seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
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

    void update(int ind, int low, int high, int i, int val, int level){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = ( low + high ) / 2;
        if(i<=mid) update(2*ind+1, low, mid, i, val, level + 1);
        else update(2*ind + 2, mid + 1, high, i, val, level + 1);

        if(level%2 == 0) seg[ind] = seg[2*ind + 1] | seg[2*ind + 2];
        else seg[ind] = (seg[2*ind + 1]) ^ (seg[2*ind + 2]);
    }

};


void solve(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    int size = pow(2,n);
    int a[size];
    F(i,0,pow(2,n)) cin>>a[i];
    SGTree Sg(pow(2,n));
    if(n&1){
        Sg.build(a, 0, 0, size-1, 0);
    }
    else Sg.build(a, 0, 0, size-1, 1);
    while(q--){
        int i, val;
        cin>>i>>val;
        i--;
        if(n&1){
            Sg.update(0, 0, size - 1, i, val, 0);
        }
        else Sg.update(0, 0, size - 1, i, val, 1);
        
        a[i] = val;
        // F(i,0,4*size) cout<<Sg.seg[i]<<" "; cout<<endl;
        cout<<Sg.seg[0]<<endl;
    }
    
    
}

int main(){
    int t = 1;
    while(t--) solve();
    return 0;
}