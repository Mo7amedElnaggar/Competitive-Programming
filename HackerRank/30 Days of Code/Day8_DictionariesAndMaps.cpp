#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n ;
    cin >> n ;
    map<string , ll> mp ; // I will Save all here.
    while(n--){
        string name  ;
        ll num ;
        cin >> name >> num ;
        mp[name] = num ;
    }
    string query ;
    while(cin >> query){
        if(mp.count(query)) // return true if query exists in mp
            cout << query << "=" << mp[query] << endl;
        
        else cout << "Not found" << endl;
    }
    return 0 ;
}

