#include<bits/stdc++.h>
using namespace std;

int main(){
    string a;
    string b;
    getline(cin,a);
    getline(cin,b);
    unordered_map<char,int> m,n;
    for(auto&it:a) if(it != ' ') m[it]++;

    for(auto&it:b) if(it != ' ') n[it]++;

    for(auto&it:n){
        if(m[it.first] < it.second){cout<<"NO";return 0;}
    }
    cout<<"YES";
    return 0;
}