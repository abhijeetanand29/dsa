#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int vis = 0;
    for(int i = 0; i<s.size(); i++){
        if(vis == 0 && s[i] == 'h'){
            vis++;
            continue;
        }
        if(vis == 1 && s[i] == 'e'){
            vis++;
            continue;
        }
        if(vis == 2 && s[i] == 'l'){
            vis++;
            continue;
        }
        if(vis == 3 && s[i] == 'l'){
            vis++;
            continue;
        }
        if(vis == 4 && s[i] == 'o'){
            vis++;
            continue;
        }
        if(vis == 5) break;
     }
     if(vis == 5) cout<<"YES";
     else cout<<"NO";

    return 0;
}