/*
 * UVA : 572 Oil Deposits
 * Link : https://uva.onlinejudge.org/external/5/572.pdf
 * using FloodFill
 */
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
int n , m ; // Height and Width respectively in grid
vector<vector<char> > grid ; // Adjacency Matrix -> Graph representation
vector<vector<bool> > VIS ; // flags to check if i visited this coordinates before.
// Directions
int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1} ;
int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1} ;

// Check whether i get out from the grid or not
bool isValid(int r , int c){
    return (r >= 0 && c >= 0 && r < n && c < m) ;
}

void FloodFill(int r , int c){ // r , c coordinates and ch is Alphapetic
    if(!isValid(r , c) || VIS[r][c] || grid[r][c] != '@') return ;

    //int ans = 1 ;
    VIS[r][c] = 1 ; // Mark it as VISITED co-ordinates
    for(int i = 0 ; i < 8 ; i++)
        FloodFill(r + dx[i] , c + dy[i]) ;
}


int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    while(cin >> n >> m && (n || m)){
        // intializing Data
        grid = vector<vector<char> > (n , vector<char>(m)) ;
        VIS = vector<vector<bool> > (n , vector<bool>(m , 0)) ;
        // input from user
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> grid[i][j] ;

        int output = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!VIS[i][j] && grid[i][j] != '*')
                    output++ , FloodFill(i , j) ;
            }
        }

        // output
        cout << output << endl;
    }

    /*
     *                      Sample input and Output
     *                      input:
     *                      1 1
     *                      *
     *                      3 5
     *                      *@*@*
     *                      **@**
     *                      *@*@*
     *                      *@*@*
     *                      1 8
     *                      @@****@*
     *                      5 5
     *                      ****@
     *                      *@@*@
     *                      *@**@
     *                      @@@*@
     *                      @@**@
     *                      0 0
     *
     */


    return 0 ;
}

