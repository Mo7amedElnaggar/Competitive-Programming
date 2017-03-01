/*
 * Dijkstra Algorithm
 * is Greedy Algorithm
 * see : http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
 * used to Find Shortest path between two nodes ( sourse , any Node ) ;
 */
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
int n , m ; // number of nodes in graph , number of Edges
vector<vector<pair<int , int > > > AdjList ; // Graph representation used to store Graph
// using pairs ( first --> to node , to -> cost)

// function return minmum cost from 'u' to 'v'
int DijKstra(int u , int v){
    vector<int> can(n + 1 , 1e5) ; // used to store the cost from u to node[i] ;
    priority_queue<pair<int , int> > pq ; // store (node , cost);

    // push 'v' as source node
    pq.push(make_pair(0 , u)) ; // cost now is ZERO
    while(!pq.empty()){
        int newV = pq.top().second ;
        int cost = -1 * pq.top().first ; // Negative because i will push value negative
        pq.pop() ;
        /* Why --> Because default sorting for priority queue is decreasingly
         * see priority queue implementation
         */
        if(newV == v) return cost ; // this is Min Cost u can get
        for(int i = 0 ; i < AdjList[newV].size() ; i++){
            int newV2 = AdjList[newV][i].first ;
            int cost2 = AdjList[newV][i].second ;
            if(can[newV2] > (cost + cost2))
                pq.push(make_pair(-(cost + cost2) , newV2)) ;
        }
    }

    return -1 ; // indicator that you can’t go from 'u' as source node to 'v' as target node
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    cin >> n >> m ; // number of nodes in graph , number of Edges respectively
    // intialize
    AdjList = vector<vector<pair<int , int> > > (n + 1) ;
    for(int i = 0 ; i < m ; i++){
        int a , b , cost ;
        cin >> a >> b >> cost ;
        /* This is undirected graph so easly you can go from a to b and also from b to a */
        AdjList[a].push_back(make_pair(b , cost)) ;
        AdjList[b].push_back(make_pair(a , cost)) ;
    }
    int a , b ; // representing source node and target node
    cin >> a >> b ;
    cout << DijKstra(a , b) << endl;


    /*
     *              Sample input
     *              input :
     *              5 6
     *              1 2 2
     *              2 5 5
     *              2 3 4
     *              1 4 1
     *              4 3 3
     *              3 5 1
     *              1 5
     *
     *              expected output :
     *              5
     */


    return 0 ;
}

