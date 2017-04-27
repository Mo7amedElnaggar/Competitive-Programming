#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

bool endsWithGmail(string email) {
   return email.find("@gmail.com") != -1 ;
}

int main() {
    int nTest ;
    cin >> nTest;

    vector<string> emailGmail ;
    while(nTest--){
        string name , email ;
        cin >> name >> email ;

        if(endsWithGmail(email)) {
           emailGmail.push_back(name) ;
        }
    }

    sort(emailGmail.begin() , emailGmail.end()) ;

    for(int i = 0 ; i < (int)emailGmail.size() ; ++i) {
       cout << emailGmail[i] << endl;
    }

    return 0;
}

