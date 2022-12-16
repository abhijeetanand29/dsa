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
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n];
    F(i,0,n){
        cin>>a[i];
    }
    int b[m];
    F(i,0,m){
        cin>>b[i];
    }

    int c[n+m];

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < n || j < m){
        if(i < n && j < m){
            if(a[i] < b[j]){
                c[k] = a[i];
                i++;
            }
            else{
                c[k] = b[j];
                j++;
            }
        }
        else if(i < n){
            c[k] = a[i];
            i++;
        }
        else {
            c[k] = b[j];
                j++;
        }
        k++;
    }

    F(l,0,m+n){
        cout<<c[l]<<" ";
    }
    cout<<endl;
}

int main(){
    // int t;
    int t = 1;
    while(t--) solve();

    return 0;
}