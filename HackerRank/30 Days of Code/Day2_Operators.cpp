#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;


int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    float mealCost , tipPercent , taxPercent ;
    cin >> mealCost >> tipPercent >> taxPercent ;

    float tip = mealCost * tipPercent / 100.0 ;
    float tax = mealCost * taxPercent / 100.0 ;
    int totalCost = round(mealCost + tip + tax) ;
    cout << "The total meal cost is " ;
    cout << totalCost ;
    cout << " dollars." << endl;

    return 0 ;
}

