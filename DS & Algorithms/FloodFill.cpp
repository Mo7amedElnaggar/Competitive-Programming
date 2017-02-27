// FloodFill  --> Graph theory
#include <bits/stdc++.h>

// move in 8 directons {
//  left    up-left
//  right   up-right
//   down   down-left
//  up      down-right
//}

using namespace std ;
typedef long long ll ;

int n , m ;
// Directions
int dx[] = {-1 , -1 , -1 , 0 , 0 , 1 , 1 , 1} ;
int dy[] = {-1 , 0 , 1 , -1 , 1 , -1 , 0 , 1} ;

vector<vector<char> > grid ; // 2-D Vector Represent users Grid
vector<vector<bool> > VIS ; // Mark visited x , y so it dont visit it again
bool isValid(int i , int j){
    // check if its out of the grid boundery or not ?
    return (i >= 0 && i < n && j >= 0 && j < m) ;
}

ll FloodFill(int r , int c , char ch){
    if(isValid(r , c) || VIS[r][c] || grid[r][c] != ch) return 0 ;

    int ans = 1 ;
    VIS[r][c] = 1 ; // mark it 1 so i can not visit it later

    for(int i = 0 ; i < 8 ; i++){
        int newR = dx[i] + r ;
        int newC = dy[i] + c ;
        ans += FloodFill(newC , newR , ch) ;
    }

    return ans ;
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif


    return 0 ;
}
