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
    if(n & 1)
        cout << "Weird" << endl;
    else if(n >= 6 && n <= 20)
        cout << "Weird" << endl;
    else
        cout << "Not Weird" << endl;

    return 0 ;
}

