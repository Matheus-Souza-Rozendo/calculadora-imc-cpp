#include <bits/stdc++.h>

using namespace std;

//função que retorna true se a string passada for um numero e false caso contrario
bool valida_apenas_numeros(string entrada){
    for(int i=0;i<entrada.size();i++){
        if((!isdigit(entrada[i]))&&(entrada[i]!='.')){
            return false;
        }
    }
    return true;
}

//função para a leitura de apenas numeros reais, caso ocorra um outro tipo de dado, a funçao acusa um erro
float ler_numeros_reais(){
    string entrada;
    leitura:
    try{
        cin >> entrada;
        if(!valida_apenas_numeros(entrada)){
            throw(entrada);
        }
    }catch(string msg){
        cout << msg << " Não é um valor valido " <<endl;
        system("pause");
        goto leitura;
        cout << endl << endl;
    }
    return stof(entrada);
}


void classifica_IMC(float IMC){
    if(IMC < 18.5){
        cout << "Abaixo do Peso";
    }else{
        if(IMC <=24.9){
            cout << "Peso Normal";
        }else{
            if(IMC<=29.9){
                cout << "Sobrepeso";
            }else{
                if(IMC<=34.9){
                    cout << "Obesidade Grau I";
                }else{
                    if(IMC<=39.9){
                        cout << "Obesidade Grau II";
                    }else{
                        cout << "Obesidade Grau III";
                    }
                }
            }
        }
    }
}

int main(){
setlocale(LC_ALL, "ptb");
int op=1;
float altura,peso,IMC;
string entrada;
while(op!=0){
    inicio:
    system("cls");
    cout << "Digite sua altura em metros: ";
    altura = ler_numeros_reais();
    cout << "Digite seu peso em Kg: ";
    peso = ler_numeros_reais();
    IMC = peso/(altura*altura);
    cout << "IMC: " << IMC << endl;
    classifica_IMC(IMC);
    cout << endl;
    system("pause");
    comando:
    system("cls");
    cout << endl << "Digite 0 para sair ou 1 para continuar\nOp: ";
    op = ler_numeros_reais();
}
return 0;

}
