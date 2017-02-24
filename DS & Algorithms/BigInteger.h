// Number More Than 1e3 Digit Doesnt Fit
#include <iostream>

using namespace std ;

int Arra[1001] ;

void Initial(string a){
	for(int i = 0 ; i < a.size() ; i++)
		Arra[i] = a[i] ;
	return ;
}

string Add(string a , string b){
    string res = "" ;
    for(int i = 0 ; i <= b.size() + 10 ; i++)
        res += "0" ;
    int ind1 = a.size() - 1 , ind2 = b.size() - 1 , ind3 = res.size() - 1 ;
    while(ind1 >= 0 || ind2 >= 0){
        int f = 0 , s = 0 ;
        if(ind1 >= 0) f = (a[ind1] - '0') ;
        if(ind2 >= 0) s = (b[ind2] - '0') ;
        //cout << f << " " << s << endl;
        int add = f + s + (res[ind3] - '0') ;
        //cout << add << endl;
        res[ind3] = char((add % 10) + '0') ;
        res[ind3 - 1] = char((add / 10) + '0') ;
        ind1-- , ind2-- , ind3-- ;
    }
    for(int i = 0 ; i < res.size() ; i++)
        if(res[i] != '0') return res.substr(i) ;

    return "ASD" ;
}

void Sub(string b){

}

void Multiple(string b){

}

void Divide(string b){

}

void Mod(string b){

}
