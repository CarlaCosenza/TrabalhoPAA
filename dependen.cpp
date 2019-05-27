//https://br.spoj.com/problems/DEPENDEN/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector < vector <int> > &adj, vector <int> &vis, int &size, int num, int &ans, int &value){
	vis[node] = num;
	for(int i = 0 ; i < adj[node].size() ; i++){
		if(vis[adj[node][i]] != num){
			dfs(adj[node][i], adj, vis, size, num, ans, value);
			size++;
		}
	}
	if(size > value){
		value = size;
		ans = node;
	}
}


int main(){

	while(true){

		//Variaveis
		int n, c, a;

		//Get Inputs
		scanf("%d\n", &n);
		if(n == 0) break;
		vector < vector <int> > adj(n);
		vector <int> vis(n, -1);

		for(int i = 1 ; i <= n ; i++){
			scanf("%d" , &c);
			for(int j = 0 ; j < c ; j++){
				scanf("%d" , &a);
				adj[i-1].push_back(a-1);
			}
		}

		int ans;
		int value = 0;
		int num = 0;

		for(int i = 0 ; i < n ; i++){
			int size = 0;
			dfs(i, adj, vis, size, num, ans, value);
			num++;
		}

		cout << ans+1 << endl;

	}


	return 0;
}
