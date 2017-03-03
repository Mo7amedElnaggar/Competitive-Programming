#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n ; // size of Array
    cin >> n ;
    int A[n] ; // Array
    // input array
    for(int i = 0 ; i < n ; i++)
        cin >> A[i] ;

    // printing in Reverse order
    for(int i = n - 1 ; i >= 0 ; --i)
        cout << A[i] << " " ;


    return 0 ;
}

