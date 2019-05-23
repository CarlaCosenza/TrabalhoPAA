#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {

  int n, total;
  int num;
  char lado;
  int D[32], E[32];

while(scanf("%d", &n)>=0){
  total=0;
  for(int i=0; i<32; i++){
    E[i]=D[i]=0;
  }
  while (n--) {
    cin>>num>>lado;
    if(lado=='D') {
            if(E[num-30]>0){
                E[num-30]--;
                total++;
            }
            else D[num-30]++;
    }
    else{
            if(D[num-30]>0){
                D[num-30]--;
                total++;
            }
            else E[num-30]++;
    }
  }
  cout<<total<<endl;
}
	return 0;
}
