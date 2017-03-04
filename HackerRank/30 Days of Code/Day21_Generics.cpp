#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
// C++ Templetes
template <class ANY>
void printArray(vector<ANY> array){
    for(int i = 0 ; i < (int) array.size() ; i++)
        cout << array[i] << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n;
    cin >> n;
    vector<int> int_vector(n);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        int_vector[i] = value;
    }

    cin >> n;
    vector<string> string_vector(n);
    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;
        string_vector[i] = value;
    }

    printArray<int>(int_vector);
    printArray<string>(string_vector);


    return 0 ;
}
