#include <stdio.h>

int main(){
    char letra;
    printf("Digite 'M' para masculino e 'F' para feminino: ");
    scanf("%c", &letra);
    
    if (letra == 'F' || letra == 'f'){
        printf("Feminino");
    }
    else if (letra == 'M' || letra == 'm'){
        printf("Masculino");
    }
    else {
        print("Resposta inválida!")
    }
}

int main(){
    int num;
    
    scanf("%d", &num);
    if (num % 2 == 0){
        printf("par");
    }
    else{
        printf("impar");
    }
    return 0;
}

int main(){
    int num;
    
    scanf("%d", &num);
    if (num % 3 == 0 && num % 5 == 0){
        printf("divisível");
    }
    else{
        printf("não é divisível");
    }
    return 0;
}

int main(){
    int num1, num2, num3, menor;
    
    printf("Digite o 1° num:");
    scanf("%d", &num1);
    
    menor = num1;
    
    printf("Digite o 2° num:");
    scanf("%d", &num2);
    
    if(num2 < menor){
        menor = num2;
    }
    printf("Digite o 3° num:");
    scanf("%d", &num3);
    
    if(num3 < menor){
        menor = num3;
    }
    printf("O menor número é: %d", menor);
    
    return 0;
}
