#ifndef PESSOA_H
#define PESSOA_H
#include <bits/stdc++.h>

using namespace std;

class Pessoa{
    public:
        Pessoa();
        bool Set_Peso(float p);
        bool Set_Altura(float h);
        float get_imc();
        string classifica_imc();
    private:
        void calcular_imc();
        float peso=-1;
        float altura=-1;
        float imc=-1;
};

Pessoa::Pessoa(){
}

bool Pessoa::Set_Peso(float p){
    if(p>0 && p <=500){
        peso = p;
        return true;
    }
    return false;
}

bool Pessoa::Set_Altura(float h){
    if(h>0 && h<=3){
        altura=h;
        return true;
    }
    return false;
}

float Pessoa::get_imc(){
    calcular_imc();
    return imc;
}

string Pessoa::classifica_imc(){
    if(imc==-1){
        calcular_imc();
    }
    if(imc>0 && imc < 18.5){
        return "Abaixo do Peso";
    }else{
        if(imc <=24.9){
            return "Peso Normal";
        }else{
            if(imc<=29.9){
                return "Sobrepeso";
            }else{
                if(imc<=34.9){
                    return "Obesidade Grau I";
                }else{
                    if(imc<=39.9){
                        return "Obesidade Grau II";
                    }else{
                        return "Obesidade Grau III";
                    }
                }
            }
        }
    }

    return "valor de altura e peso invalidos";
}

void Pessoa::calcular_imc(){
    if(peso!=-1 && altura!=-1){
        imc = peso/(altura*altura);
    }else{
        imc = -1;
    }
}


#endif // PESSOA_H
