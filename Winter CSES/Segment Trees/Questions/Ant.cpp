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

inline int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}

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

        seg[ind] = gcd( seg[2*ind + 1], seg[2*ind + 2] );
    }

    int query(int ind, int low, int high, int l, int r ){
        
        if(high < l || low > r){
            return 0;
        }

        if(l <= low && high <= r){
            return seg[ind];
        }

        int mid = low + ( high - low ) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return gcd(left, right);
    }

    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = ( low + high ) / 2;
        if(i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind + 2, mid + 1, high, i, val);

        seg[ind] = gcd( seg[2*ind + 1], seg[2*ind + 2] );
    }

};

void solve(){
    int n;
    cin>>n;
    int a[n];
    map<int,vv> mp;
    F(i,0,n){
        cin>>a[i];
        mp[a[i]].push_back(i);
    }

    
    SGTree st(n);
    st.build(a,0,0,n-1);

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans = 0;
        l--; r--;
        int rangeGcd = st.query(0,0,n-1,l,r);

        if(!mp[rangeGcd].empty()) ans = upper_bound(mp[rangeGcd].begin(), mp[rangeGcd].end(), r) - lower_bound(mp[rangeGcd].begin(), mp[rangeGcd].end(), l);
        cout<<r-l+1-ans<<endl;
        
    }
    
}

int main(){
    int t;
    t = 1;
    while(t--) solve();

    return 0;
}