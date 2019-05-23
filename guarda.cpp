#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
float D, VF, VG;
float X;
float a, b;
while(scanf("%f %f %f", &D, &VF, &VG)>=0){
  X=sqrt(1-VF*VF/(VG*VG));
  a=D/(VG*X);
    b=12/VF;
  if(a<=b) cout<<"S"<<endl;
  else cout<<"N"<<endl;
}
	return 0;
}
