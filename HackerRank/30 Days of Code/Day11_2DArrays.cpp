#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
int A[6][6] ;
ll maxSumHourglass(int k , int s){
    ll sumPattern = 0 ;
    //cout << k << " " << s << endl;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(i == 1 && (j == 0 || j == 2)) continue ;
            sumPattern += A[i + k][j + s] ;
        }
    }
    //cout << k + 2 << " " << s + 2 << endl << " ======= " << endl;

    return sumPattern ;
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    for(int i = 0 ; i < 6 ; i++)
        for(int j = 0 ; j < 6 ; j++)
            cin >> A[i][j] ;

    ll finalSum  = -1e18 ;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(!i && !j) finalSum = maxSumHourglass(0 , 0) ;
            else finalSum = max(maxSumHourglass(i , j) , finalSum) ;
        }
    }

    cout << finalSum << endl;


    return 0 ;
}
