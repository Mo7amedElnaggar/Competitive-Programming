#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

int main(){
	//freopen("input.in" , "rt" , stdin) ;
	//freopen("output.out" , "wt" , stdout) ;
    string S;
    cin >> S;
    
    try {
        int result = stoi(S) ;
        cout << result << endl;
    } catch (exception e) {
        cout << "Bad String" << endl;
    }
    
    return 0;
}