#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> a(n+1);
    for(long long i = 1; i<=n;i++){
        long long val;
        cin>>val;
        a[val] = i;
    }
    long long m;
    cin>>m;
    long long p = 0,v = 0;
    for(long long i = 0; i<m; i++){
        long long q;
        cin>>q;
        p += a[q];
        v += n-a[q]+1;
    }
    cout<<p<<" "<<v;    

    
    return 0;
}