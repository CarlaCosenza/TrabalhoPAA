#include <iostream>
#include <string>
#define MAX 10010
using namespace std;
int vertical[MAX];
int horizontal[MAX];

int resolve(int m, int n, int l, string modo){
    int respVertical = 0;
    int respHorizontal = 0;
    int qtdV = MAX;
    int qtdH = MAX;
    if(modo == "vertical"){ //deve-se somar atÈ chegar em "n"
        qtdV = (m*100)/l;
        //cout << "caso vertical: com qtdV = " << qtdV << endl;
        while(vertical[n] > 0 && qtdV > 0){
            //cout << "preencheu uma coluna com tamanho " << n << endl;
            qtdV--;
            //cout << "qtdV = " << qtdV << endl;
            vertical[n]--;
            respVertical++;
        }


        for(int i = n-1; i >= (n-1)/2; i--){
            if(i == n-i && qtdV > 0){
                    if(vertical[i] > 1 && qtdV > 0){
                        vertical[i] -= 2;
                        qtdV--;
                        //cout << "qtdV = " << qtdV << endl;
                        respVertical+=2;
                        i++;
                    }
            }
            else if(vertical[i] > 0 && vertical[n-i] > 0 && qtdV > 0){
                //cout << "preencheu uma coluna com tamanhos " << (n-i) <<" e "<< i << endl;
                vertical[i]--;
                vertical[n-i]--;
                qtdV--;
                //cout << "qtdV = " << qtdV << endl;
                respVertical+=2;
                i++;
            }
        }

        if(qtdV != 0) return -1;
        else return respVertical;

    }
    else if(modo == "horizontal"){ //deve-se somar atÈ chegar em "m"
        qtdH = (n*100)/l;
        //cout << "caso horizontal: com qtdH = " << qtdH << endl;
        while(horizontal[m] > 0 && qtdH > 0){
            //cout << "preencheu uma linha com tamanho " << m << endl;
            qtdH--;
            //cout << "qtdH = " << qtdH << endl;
            horizontal[m]--;
            respHorizontal++;
        }

        for(int i = m-1; i >= (m-1)/2; i--){
            //cout << "i = " << i << " e m-i = " << m-i << endl;
            if(i == m-i && qtdH > 0){
                    if(horizontal[i] > 1 && qtdH > 0){
                        horizontal[i] -= 2;
                        qtdH--;
                        //cout << "qtdH = " << qtdH << endl;
                        respHorizontal+=2;
                        i++;
                    }
            }
            else if(horizontal[i] > 0 && horizontal[m-i] > 0 && qtdH > 0){
                //cout << "preencheu uma linha com tamanhos " << (m-i) <<" e "<< i << endl;
                horizontal[i]--;
                horizontal[m-i]--;
                qtdH--;
                //cout << "qtdH = " << qtdH << endl;
                respHorizontal+=2;
                i++;
            }
        }

        if(qtdH != 0) return -1;
        else return respHorizontal;
    }
}

int main(){
    int n, m, l, k;
    cin >> m >> n; // m = largura; n = altura
    while(!(n == 0 && m == 0)){
        int valor;

        cin >> l;
        cin >> k;

        for(int i = 0; i < k; i++){
            cin >> valor;
            horizontal[valor]++; // Aqui È somado mais 1 para cada t·bua de mesmo comprimento
            vertical[valor]++; // Tanto para o preenchimento vertical quanto o horizontal
        }

        // Devemos agora verificar se a largura da t·bua È m˙ltiplo de uma das dimensıes do sal„o

        int respV = -1;
        int respH = -1;

        if((m*100)%l == 0 || (n*100)%l == 0){
                if((m*100)%l == 0){
                    respV = resolve(m, n, l, "vertical"); //As tabuas s„o colocadas na vertical
                }
                if((n*100)%l == 0){
                    respH = resolve(m, n, l, "horizontal"); //As tabuas s„o colocadas na horizontal
                }

                if(respV == -1 && respH == -1) cout << "impossivel" << endl;
                else if(respV != -1 && respH != -1){
                    if(respV < respH) cout << respV << endl;
                    else cout << respH << endl;
                }
                else if(respV == -1 && respH != -1) cout << respH << endl;
                else if(respH == -1 && respV != -1) cout << respV << endl;
        }
        else{
            cout << "impossivel" << endl;
        }
        cin >> m >> n;

        for(int i = 0; i < 10010; i++){
            horizontal[i] = 0;
            vertical[i] = 0;
        }
    }


}
