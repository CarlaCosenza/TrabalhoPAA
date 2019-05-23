//https://br.spoj.com/problems/DESCULPA/
#include <bits/stdc++.h>
using namespace std;

int main(){

	int teste = 0;

	while(true){
		teste++;

		//Variables
		int c, f;
		vector < vector <int> > knapsack;
		vector <int> value;
		vector <int> weight;

		//Get inputs
		scanf("%d %d\n" , &c, &f);
		if(c == 0 and f == 0) break;
		for(int i = 0 ; i < f ; i++){
			int n, d;
			scanf("%d %d\n" , &n, &d);
			weight.push_back(n);
			value.push_back(d);
		}

		//Initiate the knapsack
		for(int i = 0 ; i <= value.size() ; i++){
			vector <int> v(c+1, 0);
			knapsack.push_back(v);
		}

		//Knapsack
		for(int i = 1 ; i <= value.size() ; i++){
			for(int j = 1 ; j <= c ; j++){
				if(j - weight[i-1] >= 0) knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-weight[i-1]] + value[i-1]);
				else knapsack[i][j] = knapsack[i-1][j];
			}
		}

		//Print answer
		cout << "Teste " << teste << endl;
		cout << knapsack[value.size()][c] << endl;
		cout << endl;

	}

	return 0;
}
