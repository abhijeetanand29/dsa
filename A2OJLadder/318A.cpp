#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;

    if(n&1){
        long long lastO = n/2 + 1;
        if(k <= lastO){
            cout<<2*k - 1;
            return 0;
        }
        else{
            cout<<2*(k-lastO);
            return 0;
        }
    }
    else{
        long long lastO = n/2;
        if(k <= lastO){
            cout<<2*k - 1;
            return 0;
        }
        else{
            cout<<2*(k-lastO );
            return 0;
        }
    }

    return 0;
}