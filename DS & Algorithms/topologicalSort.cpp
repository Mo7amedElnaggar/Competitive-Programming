/*
 * Topological Sort
 * is a linear ordering of the vertices in the DAG so
 * that vertex u comes before vertex v if edge (u → v) exists in the DAG.
 * Every DAG has at least one and possibly more topological sort(s).
 * see : https://en.wikipedia.org/wiki/Topological_sorting
 * see : http://www.geeksforgeeks.org/topological-sorting/
 * see : Competitive Programming 3 Book
 * this Solution just get one of topological sort order ( one only )
 */
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;
int n , m ; // number of nodes in Graph , number of Edges respectively
vector<int> topo ; // used to store topological in reverse order ;
/* u can use stack if you want it in right order */
vector<bool> VIS;
vector<vector<int> > AdjList ; // graph representation

void topologicalSort(int u){
    VIS[u] = 1 ; // mark it as VISITED ;
    // browse all of its childs
    for(int i = 0 ; i < (int)AdjList[u].size() ; i++){
        int v = AdjList[u][i] ;
        if(!VIS[v]) topologicalSort(v) ; // VISIT it Right now
    }

    topo.push_back(u) ; // insert 'u' in topological sort vector
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    cin >> n >> m ; // take input from user
    // initialize
    AdjList = vector<vector<int> > (n + 1) ;
    VIS = vector<bool> (n + 1 , 0) ;
    topo.clear() ;

    //Edges input
    for(int i = 1 ; i <= m ; i++){
        int a , b , cost ; // if u want to use cost ; but i dont use it right now
        cin >> a >> b ;
        /* This is Directed Graph so , ..... */
        /* There is a path from a --> b only */
        AdjList[a].push_back(b) ;
    }
    // call topological sort function
    for(int i = 1 ; i <= n ; i++){
        if(!VIS[i]) // if not visited just visit it
            topologicalSort(i) ;
    }
    // just print out one order of topological sort
    for(int i = 0 ; i < (int)topo.size() ; i++)
        cout << topo[i] <<  " " ;

    cout << endl;

    return 0 ;
}

