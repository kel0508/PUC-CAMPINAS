/*escreva um programa para imprimir os numeros  entre 100 e 500 que
divididos por 11 forneçam resto igual a 5.*/

#include<stdio.h>
int main(){
    int inicio = 100;

    while (inicio <= 500){
        if(inicio % 11 == 5){
            printf("%d\n",inicio);
            inicio++;
        }
        else{
            inicio++;
        }
    }

    return 0;
}
/*a pooulação de um país A é de 80.000 com taxa de crescimento de 3% e a do país B seja de 200.000
com taxa de crescimento de 1.5, em quantos anos o país A vai se igualar ao país B.*/

#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    int i = 0, popA = 80000, popB = 200000;
    while (popA <= popB){
        popA = popA * 1.03;
        popB = popB * 1.015;
        i++;
        }
    printf("%d anos para igualar a população", i);
}

/*faça um programa que leia um numero n > 0. o seu programa deve ler uma sequencia de n e
impromir se a sequncia lida está crescente ou não*/

#include <stdio.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL,"Portuguese");
    int n, atual, anterior, i;
    bool crescente = true;

    printf("Digite a quantidade de números que vc quer digitar:");
    scanf("%d", &n);

    while(n < 0){
        printf("Valor inválido! digite um número válido!");
        scanf("%d", &n);
    }
    i = 1;
    while(i <= n){
        printf("Digite o número: ");
        scanf("%d", &atual);

        if(atual < anterior){
            crescente = false;
        }

        anterior = atual;
        i++;
    }
    if (crescente == true){
        printf("A sequência é crescente!");
    }
    else{
        printf("A sequência não é crescente!");
    }
}
