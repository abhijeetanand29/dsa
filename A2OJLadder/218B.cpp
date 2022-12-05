#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> seats(m);
    for(long long i = 0; i < m ; i++) cin>>seats[i];
    long long cost1 = 0;
    long long p = n;
    long long i = 0;
    vector<long long> temp =seats;
    sort(seats.begin(),seats.end(),greater<int>());
    if(m== 1){
        while(p--){
            cost1 += seats[0];
            seats[0]--;
        }
    }
    else{
        while(p){
                cost1 += seats[0];
                seats[0]--;
                if(seats[0] < seats[1]) sort(seats.begin(),seats.end(),greater<int>());
                p--;
            }
    }
    
    p = n;
    i = 0;
    long long cost2 = 0;
    sort(temp.begin(),temp.end());
    if(m== 1){
        while(p--){
            cost2 += temp[0];
            temp[0]--;
        }
    }
    else{
        while(p){
                cost2 += temp[0];
                temp[0]--;
                if(temp[0] == 0) temp[0] = INT_MAX;
                if(temp[0] > temp[1]) sort(temp.begin(),temp.end());
                p--;
            }
    }
    cout<<cost1<<" "<<cost2;

    return 0;
}