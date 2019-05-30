//https://br.spoj.com/problems/MINIMO/
#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int mini(int a, int b){
	if(a == -1 and b == -1) return -1;
	if(a == -1) return b;
	if(b == -1) return a;
	return min(a, b);
}

int add(int a, int b){
	if(a == -1 or b == -1) return -1;
	return a+b;
}

void floydWarshallModified(vector < vector <int> > &adj, vector < vector < vector <int> > > &paths){

	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <=n ; j++){
			paths[0][i][j] = adj[i][j];
			if(i == j) paths[0][i][j] = 0;
		}
	}

	for(int k = 1 ; k <= n ; k++){
		for(int j = 1 ; j <= n ; j++){
			for(int i = 1 ; i <= n ; i++){
				if(i == j) paths[k][i][j] = 0;
				else paths[k][i][j] = mini(paths[k-1][i][j], add(paths[k-1][i][k], paths[k-1][k][j]));
			}
		}
	}

}

int main(){

	int teste = 0;

	while(scanf("%d %d\n" , &n, &m) != EOF){
		teste++;
		
		//Initialize distances
		vector < vector <int> > adj;
		for(int i = 0 ; i < n+1 ; i++){
			vector <int> v(n+1, -1);
			adj.push_back(v);
		}
		vector < vector < vector <int> > > paths;
		for(int i = 0 ; i < n+1 ; i++){
			vector < vector <int> > v1;
			for(int j = 0 ; j < n+1 ; j++){
				vector <int> v(n+1, 1e6);
				v1.push_back(v);
			}
			paths.push_back(v1);
		}

		//Get inputs
		for(int i = 0 ; i < m ; i++){
			int u, v, w;
			scanf("%d %d %d\n", &u, &v, &w);
			adj[u][v] = mini(w, adj[u][v]);
		}
		scanf("%d\n" , &c);

		//Execute the Floyd Warshall modified
		floydWarshallModified(adj, paths);

		//Consultas
		cout << "Instancia " << teste << endl;
		for(int i = 0 ; i < c ; i++){
			int o, d, t;
			scanf("%d %d %d\n", &o, &d, &t);

			int ans = paths[t][o][d];
			cout << ans << endl;
		}
		cout << endl;

	}


	return 0;
}
