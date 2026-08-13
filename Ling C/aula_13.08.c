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

int main(){
    int idade;
    
    printf("Digite sua idade:");
    scanf("%d", &idade);
    
    if(idade <= 19){
        printf("Jovem!");
    }
    else if (idade < 60){ //se ele chegar nessa linha, ele ja é maior que 19, então precisa validar de novo
        printf("Adulto!");
    }
    else{
        printf("Idoso!");
    }
    return 0;
}

int main(){
    // equilátero: 3 lados iguais
    // isoceles: 2 lados iguais
    // escaleno: todos os lados diferentes
    int n1, n2, n3;
    
    printf("Digite o 1° num:");
    scanf("%d", &n1);
    
    menor = n1;
    
    printf("Digite o 2° num:");
    scanf("%d", &n2);
    
    printf("Digite o 3° num:");
    scanf("%d", &n3);

    if(n1 == n2 && n2 == n3){
        printf("equilátero!");
    }
    else if(n1 == n2 || n2 == n3 || n1 == n3){
        printf("isoceles!");
    }
    else{
        printf("escaleno!");
    }
    return 0;
}
