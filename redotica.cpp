//http://br.spoj.com/problems/REDOTICA/
#include <bits/stdc++.h>
using namespace std;

int getHead(int node, vector <int> &head){
	if(node == head[node]) return node;
	head[node] = getHead(head[node], head);
	return head[node];
}

bool add(int node1, int node2, vector <int> &head, vector <int> &sz){
	node1 = getHead(node1, head);
	node2 = getHead(node2, head);
	if(node1 == node2) return false;
	if(sz[node1] < sz[node1]) swap(node1, node2);
	head[node2] = node1;
	sz[node1] += sz[node2];
	return true;
}

int main(){

	int teste = 0;

	while(true){

		teste++;

		//Variables
		int n, m;
		priority_queue < vector < int > > pq;
		vector < pair <int, int> > ans;
		vector <int> head;

		//Get inputs
		scanf("%d %d\n" , &n, &m);
		if(n == 0 and m == 0) break;
		for(int i = 0 ; i < n ; i++) head.push_back(i);
		vector <int> sz(n, 1);

		for(int i = 0 ; i < m ; i++){
			int x, y, z;
			scanf("%d %d %d\n" , &x, &y, &z);
			vector <int> v;
			v.push_back(-z);
			v.push_back(x-1);
			v.push_back(y-1);
			pq.push(v);
		}

		//Add edges
		while(!pq.empty()){
			vector <int> v = pq.top();
			if(add(v[1], v[2], head, sz)){
				if(v[1] > v[2]) swap(v[1], v[2]);
				ans.push_back(make_pair(v[1], v[2]));
			}
			pq.pop();
		}

		sort(ans.begin(), ans.end());

		//Print answer
		cout << "Teste " << teste << endl;
		for(int i = 0 ; i < ans.size() ; i++){
			cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
		}
		cout << endl;

	}


	return 0;
}
