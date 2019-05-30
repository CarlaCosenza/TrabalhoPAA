//https://br.spoj.com/problbems/PAL/
#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > findPalindromes(int start, int end, string &s){
	
	vector < vector <int> > palindromes;
	for(int i = start ; i <= end ; i++){
		vector <int> v(end-start+1, 0);
		v[i] = 1;
		palindromes.push_back(v);
	}

	for(int i = start ; i < end ; i++){
		if(s[i] == s[i+1]) palindromes[i][i+1] = 1;
	}

	for(int k = 2 ; k <= end ; k++){
		for(int i = start ; i + k <= end ; i++){
			if(s[i] == s[i+k] and palindromes[i+1][i+k-1] == 1) palindromes[i][i+k] = 1;
		}
	}

	return palindromes;
}

int find(int start, int end, string &s, vector <vector <int> > &palindromes, vector <int> &dp){
	if(start > end) return 0;
	if(dp[start] != -1) return dp[start];
	int ans = 1e7;
	for(int i = start ; i <= end ; i++){
		if(palindromes[start][i]){
			ans = min(ans, 1+ find(i+1, end, s, palindromes, dp));
		}
	}

	dp[start] = ans;
	return ans;
}

int main(){

	int teste = 0;

	while(true){

		teste++;

		//Variables
		int n;
		string s;

		//Get inputs
		scanf("%d\n", &n);
		if(n == 0) break;
		vector <int> dp(n, -1);
		cin >> s;

		vector < vector <int> > palindromes = findPalindromes(0, n-1, s);
		int ans = find(0, n-1, s, palindromes, dp);

		cout << "Teste " << teste << endl;
		cout << ans << endl << endl;

	}


	return 0;
}
