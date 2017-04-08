#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;


int main(){
   int d1 , d2 , m1 , m2 , y1 , y2 ;

   cin >> d1 >> m1 >> y1 ;
   cin >> d2 >> m2 >> y2 ;

   if(y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2)){
      cout << 0 << endl;
   } else if(y1 == y2 && m1 == m2){  // same year and month
      cout << abs(d1 - d2) * 15 << endl;
   } else if(y1 == y2) { // same year
      cout << abs(m1 - m2) * 500 << endl;
   } else { // fixed Fine
      cout << 10000 << endl;
   }


    return 0;
}

