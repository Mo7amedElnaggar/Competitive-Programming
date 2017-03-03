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

    for(int i = 1 ; i <= 10 ; i++)
        cout << n << " x " << i << " = " << n * i << endl;

    return 0 ;
}