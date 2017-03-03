#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int t ;
    cin >> t ;
    while(t--){
        string s ;
        cin >> s ;
        string evenPart = "" , oddPart = "" ;
        for(int i = 0 ; i < (int)s.size() ; i++){
            if(i & 1) oddPart += s[i] ;
            else  evenPart += s[i] ;
        }
        cout << evenPart << " " << oddPart << endl;
    }

    return 0 ;
}