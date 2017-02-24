// UVA 439 
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

ll dx[] = {-2 , -2 , -1 , -1 , 1 , 1 , 2 , 2};
ll dy[] = {-1 , 1 , -2 , 2 , -2 , 2 , -1 , 1};

bool isValid(int i , int j){
    return (i >= 1 && j >= 1 && i <= 8 && j <= 8) ;
}

ll getMin(int i , int j , int r , int c){
    queue<pair<ll , pair<ll , ll> > > q ;
    vector<vector<bool> > VIS(9 , vector<bool>(9 , 0)) ;
    q.push(make_pair(0 , make_pair(i , j))) ;
    VIS[i][j] = 1 ;
    while(!q.empty()){
        ll x = q.front().second.first , y = q.front().second.second ;
        ll cost = q.front().first ;
        q.pop() ;
        if(x == r && y == c) return cost ;
        for(int k = 0 ; k < 8 ; k++){
            ll newX = x + dx[k] , newY = y + dy[k] ;
            if(isValid(newX , newY) && !VIS[newX][newY]){
 //               cout << "NEW : " << newX << " " << newY << endl;
                VIS[newX][newY] = 1 ;
                q.push(make_pair(cost + 1 , make_pair(newX , newY))) ;
            }
        }

    }
    return -1 ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ;

    string a , b;
    while(cin >> a >> b){
        int i = a[0] - 'a' + 1 , j = a[1] - '0' ;
        int r = b[0] - 'a' + 1 , c = b[1] - '0' ;
        cout << "To get from " << a << " to " << b << " takes " ;
        cout << getMin(i , j , r , c) << " knight moves." << endl;
    }


    return 0 ;
}
