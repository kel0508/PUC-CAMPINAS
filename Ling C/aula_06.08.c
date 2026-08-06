#include <stdio.h>

int main(){
    /*para colocar cometarios*/
    printf("hello world!!\n");
    /*\n serve para quebrar linhas*/

    /*declaração de variáveis --> tipo_variavel nome_variavel ;
    tipos de variáveis:
    char - caracter (A, ! 0, #0
    int - numero inteiro
    float - numero com precisão simples (1.2, 2.5)
    double - numeros com precisão dupla (2.59, 5.99)*/

    int idade = 10, meses, ano;
    float altura;
    char nome[] = "Raquel";
    double peso;
    return 0;

    /*quando for exibir a variavel no print, deve se chamar cada tipo de dado com sua formatação específica
    usando o sinal de % e a letra específica para a leitura de cada tipo de dado:
    int - print("%d", idade)
    float - print("%f", altura)
    char - print("%c", nome*/
}
