#include <bits/stdc++.h>
#include "leitura_dados.h"
#include "Pessoa.h"

using namespace std;



int main(){
setlocale(LC_ALL, "ptb");

//declaração de variaveis
int op;
float dados;
Pessoa *pessoa = new Pessoa();
string erro;

Inicio:
    system("cls");

//leitura de dados
try{
    cout << "Digite o valor da altura em metros" << endl;
    cout << "altura: ";
    dados=ler_numeros_reais();
    if(!pessoa->Set_Altura(dados)){
        erro = "altura invalida";
       throw erro;
    }

    cout << "Digite o valor do peso em kg" << endl;
    cout << "peso: ";
    dados=ler_numeros_reais();
    if(!pessoa->Set_Peso(dados)){
       erro = "peso invalido";
       throw erro;
    }
}catch(string msg){
    cout << endl << endl << msg <<endl;
    system("pause");
    goto Inicio;
}

//saida do programa
cout << endl << endl << "IMC: " << pessoa->get_imc() << endl;
cout << pessoa->classifica_imc()  << endl;
system("pause");

//rotina menu
 menu:
    system("cls");
    cout << endl << endl << endl;
    cout << "Digite 1 para continuar\nDigite 0 para sair\nopção: ";
    op = ler_numeros_reais();
    cout << endl;
    switch(op){
        case 1:
            goto Inicio;
            break;
        case 0:
            break;
        default:
            cout << "Comando invalido\n";
            system("pause");
            goto menu;
            break;
    }

return 0;

}
