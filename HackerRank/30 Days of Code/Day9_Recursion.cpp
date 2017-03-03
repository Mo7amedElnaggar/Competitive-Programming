#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll Factorial(int n){
    if(n == 1)
        return 1 ;
    return n * Factorial(n - 1) ;
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n ;
    cin >> n ;

    cout << Factorial(n) << endl;

    return 0 ;
}
