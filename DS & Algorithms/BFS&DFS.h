#include <vector>
#include <queue>

using namespace std ;
typedef long long ll ;

int VIS[1001];
vector <vector<int> > AdjList(1001) ;

void BFS(int s){
	VIS[s] = 1 ;
	queue <int> q ;
	q.push(s) ;
	while(!q.empty()){
		int u = q.front() ;
		q.pop() ;
		for(int i : AdjList[u]){
			if(!VIS[i]) q.push(i) ;
		}
	}
}

void DFS(int u){
	VIS[u] = 1 ;
	for(int i : AdjList[u]){
		if(!VIS[i])
			DFS(i) ;
	}
}
