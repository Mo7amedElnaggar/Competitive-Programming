#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

string toBinary(ll n){
    string res = "" ;
    while(n)
        res += (n % 2 ? "1" : "0") , n /= 2 ;

    if(res.empty()) res ="0" ;

    reverse(res.begin() , res.end()) ;

    return res ;
}

ll maxNumberOfConsecutive1(string binaryNumber){
    // using two Pointer technique
    ll idx1 = 0 , idx2 = 0 , res = 0 ;
    for(int i = 0 ; i < (int) binaryNumber.size() ; i++){
        if(binaryNumber[i] == '1') idx2++ ;
        else res = max(res , idx2 - idx1) , idx1 = idx2 = i + 1 ;
    }
    res = max(res , idx2 - idx1) ;
    return res ;
}


int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif

    ll n ;
    cin >> n ;

    cout << maxNumberOfConsecutive1(toBinary(n)) << endl;


    return 0 ;
}
