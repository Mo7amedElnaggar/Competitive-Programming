#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

class Difference {
    private:
    vector<int> elements;

    public:
    int maximumDifference;
    Difference(vector<int> all){
        elements = all ;
    }
    void computeDifference(){
        sort(elements.begin() , elements.end()) ;
        maximumDifference = abs(elements[elements.size() - 1] - elements[0]) ;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0 ;
}
