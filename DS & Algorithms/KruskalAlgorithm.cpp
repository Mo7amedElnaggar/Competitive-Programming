// Kruskal Algorithm which can find Minmum Spanning Tree
// Greedy Algorithm
// See : http://www.geeksforgeeks.org/greedy-algorithms-set-2-kruskals-minimum-spanning-tree-mst/
// Iam using Disjoint Set Data Structures
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
vector<int> node , Rank ; // used for DisjOintSet
vector<pair<int , pair<int , int> > > EdjList ;
// Edge List Which is a Graph representation that can store u , v and cost which can take to move
// from first node to second node ;

// return the Root node of the set where b node exists in.
int findSet(int b){
    if(b == node[b])
        return b ;
    return node[b] = findSet(node[b]) ; // more optimization
}

// return true if two nodes a , b are in the same set.
bool isSameSet(int a , int b){
    return findSet(a) == findSet(b) ;
}

// assign a , b in the Same Set where set has greater number of nodes
void UnionSet(int a , int b){
    int x = findSet(a) ; // find the Root of a’s Set.
    int y = findSet(b) ; // find the root of b’s Set.

    if(x == y) return ; // you are trying to put a , b which already in the Same set

    if(Rank[x] > Rank[y]) node[y] = x ; // X is Biggest Root node
    else {
        // Y is the Biggest Root node or they are the Same number of Nodes
        node[x] = y ;
        if(Rank[y] == Rank[x]) Rank[y]++ ; // increasing Y by one
    }
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    int n , m; // number of nodes and number of Edges between nodes respectively;
    cin >> n >> m;
    // assign Rank and nodes to n  and EdjList ;
    node.resize(n + 1) ;
    Rank.resize(n + 1) ;
    EdjList = vector<pair<int , pair<int , int> > > (m) ;
    // fill every Root node with itSelf and initialize its rank with Zero
    for(int i = 1 ; i <= n ; i++)
        node[i] = i , Rank[i] = 0 ;

    for(int i = 0 ; i < m ; i++){
        int a , b , cost ;
        cin >> a >> b >> cost ;
        EdjList[i] = make_pair(cost , make_pair(a , b)) ;
    }

    // sort edge increasingly
    sort(EdjList.begin() , EdjList.end()) ;
    ll totalCost = 0 ; // total Cost which you can Connect all Nodes
    for(int i = 0 ; i < m ; i++){
        int firstNode = EdjList[i].second.first ;
        int secondNode = EdjList[i].second.second ;
        int cost = EdjList[i].first ;

        // if there are not in the Same set then at them
        if(!isSameSet(firstNode , secondNode)){
            UnionSet(firstNode , secondNode) ;
            totalCost += cost ;
        }
    }

    // printing Total Cost
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
