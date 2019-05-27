//http://br.spoj.com/problems/ENERGIA/ 
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector < vector <int> > &adj, vector <int> &vis, int &visited){
	vis[node] = 1;
	visited++;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if(vis[adj[node][i]] == -1) dfs(adj[node][i], adj, vis, visited);
	}

	return;
} 

int main(){

	int teste = 0;

	while(true){

		teste++;

		//Variables
		int e, l;

		//Get inputs
		scanf("%d %d\n" , &e, &l);
		if(e == 0 and l == 0) break;
		vector < vector <int> > adj(e);

		for(int i = 0 ; i < l ; i++){
			int x, y;
			scanf("%d %d\n" , &x, &y);
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
		}

		//Visit everyone
		vector <int> vis(e, -1);
		int visited = 0;
		dfs(0, adj, vis, visited);

		cout << "Teste " << teste << endl;
		if(visited == e) cout << "normal" << endl;
		else cout << "falha" << endl;
		cout << endl;

	}

	return 0;
}
