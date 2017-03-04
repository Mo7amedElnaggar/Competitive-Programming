#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

class AdvancedArithmetic {
public :
    virtual int divisorSum(int n) = 0 ;
};

class Calculator : public AdvancedArithmetic {
public:
    int divisorSum(int n){
        int sumDiv = 0 ;
        for(int i = 1 ; i <= n ; i++){
            if(n % i == 0) sumDiv += i ;
        }
        return sumDiv ;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator();
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;


    return 0 ;
}