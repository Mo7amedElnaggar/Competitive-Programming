#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

int main(){
   int t;
   cin >> t;
   for(int i = 0 ; i < t ; i++){
       int n , k ;
       cin >> n >> k ;
       ll mx = 0 ;
       for(int a = 1 ; a <= n ; a++){
          for(int b = a + 1 ; b <= n ; b++){
             if (a == b) continue ;
             if(mx < (a & b) && (a & b) < k)
                mx = (a & b) ;
          }
       }

       cout << mx << endl;

   }

    return 0;
}

