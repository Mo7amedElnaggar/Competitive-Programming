#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
//#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

using namespace std;

string alpha = "0123456789ABCDEF" ; // up to hexa decimal

// Convert from "AnyBase" to Decimal
ll toDecimal(string num , int fromBase) {
	ll res = 0 ;

	for(int i = num.size() - 1 ; i >= 0 ; --i) {
		res *= fromBase ;
		res += alpha.find(num[i]) ;
	}

	return res ;
}

// Convert from Decimal to "AnyBase"
string convertTo(ll decimal , int toBase) {
	// take decimal number and Convert it to anyBase
	// Convert to ->Binary , 3 , 4 , 5 , 6 , 7 , Octal , 9 , Decimal , .... , HexaDecimal
	// base --> which base do you want convert decimal to ?

	string res = "" ;
	while(decimal) {
		res = alpha[decimal % toBase] + res ;
		decimal /= toBase ;
	}

	return res ;
}


int main() {
	//freopen("input.in" , "rt" , stdin) ;
	//freopen("output.out" , "wt" , stdout) ;

	/*
	 *			Test Our Two Functions
	 */

	cout << toDecimal("A" , 16) << endl; // expected output -> 10
	cout << toDecimal("101" , 2) << endl; // expected output -> 5

	cout << convertTo(12 , 16) << endl; // Expected output -> C
	cout << convertTo(12 , 2) << endl; // expected output -> 1100
	cout << convertTo(10 , 2) << endl; // expected output -> 1010


	return 0;
}