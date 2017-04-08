#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

string result[] = { "Not prime" , "Prime" };

bool isPrime(ll x){
   if(x == 2) return true ;
   if(x < 2 || x % 2 == 0)
      return false ;

   for(ll i = 3 ; i * i <= x ; i += 2){
      if(x % i == 0) return false ;
   }

   return true ;
}

int main(){
   int t ;
   cin >> t ;
   while(t--){
      ll n ;
      cin >> n ;
      cout << result[isPrime(n)] << endl;
   }

    return 0;
}

