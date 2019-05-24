//https://br.spoj.com/problems/SALDO/
#include <bits/stdc++.h>
using namespace std;

int main(){

	int teste = 0;

	while(true){
		teste++;

		//Variaveis
		int n;
		vector <int> gols;
		int left, right, currentLeft, currentRight, currentSaldo, saldo;

		//Get inputs
		scanf("%d\n" , &n);
		if(n == 0) break;
		for(int i = 0; i < n ; i++){
			int x, y;
			scanf("%d %d\n" , &x, &y);
			gols.push_back(x-y);
		}

		//Analyze gols
		right = -1;
		currentRight = -1;
		left = 0;
		currentLeft = 0;
		saldo = -1;
		currentSaldo = 0;
		int counter = 0;
		while(counter < gols.size()){
			currentSaldo = currentSaldo + gols[counter];
			if(currentSaldo == saldo and currentSaldo > 0){
				if(counter-currentLeft > right-left){
					right = counter;
					left = currentLeft;
				}
			}
			if(currentSaldo > saldo and currentSaldo > 0){
				left = currentLeft;
				right = counter;
				saldo = currentSaldo;
			}

			if(currentSaldo < 0 or counter == gols.size()-1){
				currentSaldo = 0;
				currentLeft = counter+1;
			}
			counter++;
		}

		//Print answer
		cout << "Teste " << teste << endl;
		if(saldo == -1) cout << "nenhum" << endl << endl;
		else cout << left+1 << " " << right+1 << endl << endl;

	}


	return 0;
}
