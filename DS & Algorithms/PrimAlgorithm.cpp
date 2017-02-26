// Prim’s Algorithm which can find Minmum Spanning Tree
// Greedy Algorithm
// See :http://www.geeksforgeeks.org/greedy-algorithms-set-5-prims-minimum-spanning-tree-mst-2/
// using PRiority Queue
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

vector<vector<pair<int , int > > > AdjList ; // Graph representation to Store Node ;
// Read more about Adjacency List Graph Representation.
priority_queue<pair<int , int> > pq ; // used to store Cost , Node
vector<bool> VIS ; // flag if Node is Visited or not.

void Process(int node){
    VIS[node] = 1 ; // mark node is Visited.
    // For --> Browse all Nodes which you can Go from initial node.
    for(int i = 0 ; i < AdjList[node].size() ; i++){
        int toNode = AdjList[node][i].first ; // second node ;
        int cost = AdjList[node][i].second ; // Cost from node to secondNode ;
        // check if i Visited 'toNode' before
        if(!VIS[toNode])
            pq.push(make_pair(-cost , toNode)) ; // Negative Cost --> to Sort increasingly
            // Default for priority queue is sorting decreasingly
            // see Priority queue in Cplusplus.com --> Official site for C++
     }
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n , m; // number of nodes and number of Edges between nodes respectively;
    cin >> n >> m;
    // assign VIS Vector and AdjList 2D Vector
    VIS = vector<bool> (n + 1 , 0) ; // initialize nodes with 0 which indicator to not VISITED
    AdjList = vector<vector<pair<int , int> > > (n + 1) ;

    // loop to Enter m Edges
    for(int i = 0 ; i < m ; i++){
        int from , to , cost  ;
        cin >> from >> to >> cost ;
        AdjList[from].push_back(make_pair(to , cost)) ;
        AdjList[to].push_back(make_pair(from , cost)) ;
        /*
         * You Can go from 'from' to 'to' using 'cost'
         * and also you can go from 'to' to 'from' using same 'cost'  hhhhh
         * that’s called 'Undirected Graph'
         * see : http://mathinsight.org/definition/undirected_graph
         */
    }

    // MST total cost that you can traverse all Nodes using this Cost as 'MinCost'
    ll totalCost = 0 ; // initially 0 ;

    Process(1) ; // Process first Node ;
    while(!pq.empty()){
        int node = pq.top().second ;
        int cost = -1 * pq.top().first ; // multiple -1 because we pushed node in 'pq' with -Cost ;
        // Don't forget that 😅
        pq.pop() ;
        if(!VIS[node])
            totalCost += cost , Process(node) ;
    }

    // printing total Cost
    cout << totalCost << endl;


    /*          Sample input
     *  4 5
     *  1 2 10
     *  1 3 6
     *  1 4 5
     *  2 4 15
     *  3 4 4
     *          Sample Output
     *  19
     */


    return 0 ;
}
