#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;


int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int i = 4 ;
    double d = 4.0 ;
    string s = "HackerRank " ;

    // your Code
    int i2  ;
    double d2 ;
    string s2 ;
    cin >> i2 >> d2 ;
    getline(cin , s2) ;
    getline(cin , s2) ;

    // print
    cout << i + i2 << endl;
    cout << fixed << setprecision(1) << d + d2 << endl;
    cout << s << s2 << endl;


    return 0 ;
}

