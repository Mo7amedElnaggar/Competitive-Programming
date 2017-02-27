/*
 * UVA : 10946 - You want what filled?
 * Link : https://uva.onlinejudge.org/external/109/10946.pdf
 * using FloodFill
 */
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
int n , m ; // Height and Width respectively in grid
vector<vector<char> > grid ; // Adjacency Matrix -> Graph representation
vector<vector<bool> > VIS ; // flags to check if i visited this coordinates before.
// Directions
int dx[] = {-1 , 0 , 0 , 1} ;
int dy[] = {0 , -1 , 1 , 0} ;

// Check whether i get out from the grid or not
bool isValid(int r , int c){
    return (r >= 0 && c >= 0 && r < n && c < m) ;
}

int FloodFill(int r , int c , int ch){ // r , c coordinates and ch is Alphapetic
    if(!isValid(r , c) || VIS[r][c] || grid[r][c] != ch) return 0 ;

    int ans = 1 ;
    VIS[r][c] = 1 ; // Mark it as VISITED co-ordinates
    for(int i = 0 ; i < 8 ; i++)
        ans += FloodFill(r + dx[i] , c + dy[i] , ch) ;

    return ans ;
}

bool Comp(pair<char , int> a , pair<char , int> b){
    if(a.second == b.second)
        return a.first < b.first ;

    return a.second > b.second ;
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int test = 1 ; // for printing "Problem \(test++)"
    while(cin >> n >> m && (n || m)){
        // intializing Data
        grid = vector<vector<char> > (n , vector<char>(m)) ;
        VIS = vector<vector<bool> > (n , vector<bool>(m , 0)) ;
        // input from user
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> grid[i][j] ;

        vector<pair<char , int> > vec ; // used to store character and its Count numbers
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!VIS[i][j] && grid[i][j] != '.')
                    vec.push_back(make_pair(grid[i][j] , FloodFill(i , j , grid[i][j]))) ;
            }
        }

        // sort based on Function
        sort(vec.begin() , vec.end() , Comp) ;

        // output
        cout << "Problem " << test++ << ":" << endl;

        for(int i = 0 ; i < (int)vec.size() ; i++)
            cout << vec[i].first << " " << vec[i].second << endl;
    }

    /*
     *              Sample input and Output
     *              input :
     *              5 5
     *              ..AAA
     *              E.BBB
     *              ..AA.
     *              CC.DD
     *              CC.D.
     *              5 5
     *              ..AAA
     *              E.BBB
     *              ..AA.
     *              CC.DD
     *              CC.D.
     *              0 0
     *
     *              output :
     *              Problem 1:
     *              C 4
     *              A 3
     *              B 3
     *              D 3
     *              A 2
     *              E 1
     *              Problem 2:
     *              C 4
     *              A 3
     *              B 3
     *              D 3
     *              A 2
     *              E 1
     *
     */

    return 0 ;
}

