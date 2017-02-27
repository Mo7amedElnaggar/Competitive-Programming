// Strongly Connected Component
// Tarjan’s Algorithm
// See : http://www.geeksforgeeks.org/strongly-connected-components/
// See : 'Competitive Programming 3' implementation
#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

int nNode ; // number of nodes in Graph
int dfsNumberCounter = 0 , numSCC = 0 ;
vector<bool> VIS ; // Check if node is visited before ?!.
vector <int> dfs_num , dfs_low ;
vector<vector<pair<int , int> > > AdjList ; // Graph Representation Adjacency List ;
stack<int> S ;

void TarjanAlgo(int u){
    dfs_num[u] = dfs_low[u] = dfsNumberCounter++ ; // dfs_low[u] <= dfs_num[u]
    VIS[u] = 1 ; // mark it as Visited node
    for(int i = 0 ; i < (int)AdjList[u].size() ; i++){
        pair<int , int> v = AdjList[u][i] ;
        if (dfs_num[v.first] == 0)
            TarjanAlgo(v.first);
        if(VIS[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); // Update dfs_low
    }

    if(dfs_low[u] == dfs_num[u]){
        cout << "SCC : " << ++numSCC << endl; // this part is done after recursion
        while (1) {
            int v = S.top(); S.pop();
            VIS[v] = 0;
            cout << " " << v << endl;
            if (u == v) break;
        }
        printf("\n");
    }
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif


    return 0 ;
}
