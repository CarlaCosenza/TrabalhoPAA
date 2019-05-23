//https://br.spoj.com/problems/NUMERDOS/
#include <bits/stdc++.h>
using namespace std;

pair <string, string> divideString(string s){
	string a = "";
	string b = "";
	bool passedSpace = false;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == ' '){
			passedSpace = true;
			continue;
		}
		if(passedSpace) b.push_back(s[i]);
		else a.push_back(s[i]);
	}

	return make_pair(b, a);
}

vector < pair <string, string> > treatString(string s){
	vector < pair <string, string> > ans;
	string a = "";
	for(int i = 0 ; i <= s.size() ; i++){
		if(s[i] == ',' or i == s.size()){
			pair <string, string> p = divideString(a);
			ans.push_back(p);
			i++;
			a = "";
		}
		else{
			a.push_back(s[i]);
		}
	}

	return ans;
}

int getID(map < pair <string, string>, int> &autores, pair <string, string> &autor){
	if(autores.count(autor) > 0) return autores[autor];
	int id = autores.size();
	autores[autor] = id;
	return id;
}

void updateGraph(vector <vector <int> > &adj, map < pair <string, string>, int> &autores, vector < pair <string, string> > &paper){
	vector <int> ids;
	for(int i = 0 ; i < paper.size() ; i++) ids.push_back(getID(autores, paper[i]));
	for(int i = 0 ; i < ids.size() ; i++){
		for(int j = i+1 ; j < ids.size() ; j++){
			adj[ids[i]].push_back(ids[j]);
			adj[ids[j]].push_back(ids[i]);
		}
	}

	return;
}

int main(){

	map < pair <string, string>, int> autores;
	int n;
	int teste = 0;

	while(true){
		teste++;

		//Clearing previous test case
		autores.clear();
		vector <int> dist(100, 1e7);
		priority_queue <pair <int, int> > pq;
		vector <vector <int> > adj(100);

		//Recieving input
		scanf("%d\n" , &n);
		if(n == 0){
			break;
		}
		for(int i = 0 ; i < n ; i++){
			string s;
			getline(cin, s);
			s.pop_back();
			vector < pair<string, string> > au = treatString(s);	
			updateGraph(adj, autores, au);
		}

		//Dijkstra
		string l = "Erdos";
		string k = "P.";
		pair <string, string> p = make_pair(l, k);
		pq.push(make_pair(0, getID(autores, p)));
		dist[getID(autores, p)] = 0;
		while(!pq.empty()){
			int id = pq.top().second;
			int dis = -pq.top().first;
			pq.pop();
			for(int i = 0 ; i < adj[id].size() ; i++){
				int neigh = adj[id][i];
				if(dist[neigh] > dis + 1){
					dist[neigh] = dis+1;
					pq.push(make_pair(-dist[neigh], neigh));
				}
			}
		}

		//Print map
		cout << "Teste " << teste << endl;

		map < pair <string, string>, int>::iterator it;
		for(it = autores.begin() ; it != autores.end() ; it++){
			if(it->first.first == "Erdos" and it->first.second == "P.") continue;
			int id = it->second;
			if(dist[id] == 1e7){
				cout << it->first.second << " " << it->first.first << ": infinito" << endl;
			}
			else cout << it->first.second << " " << it->first.first << ": " << dist[id] << endl;
		}
		cout << endl;
	}


	return 0;
}
