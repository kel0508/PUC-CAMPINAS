#include <stdio.h>
#define MAX_TITULOS 3

int main(){
    int codigos[MAX_TITULOS] = {0};
    int estoque[MAX_TITULOS] = {0};
    int qntTitulos = 0, novoCodigo, novoEstoque, codigoRepetido;

    while(qntTitulos < MAX_TITULOS){
        printf("\nDigite o codigo do livro: ");
        scanf("%d", &novoCodigo);

        codigoRepetido = 0;

        if(novoCodigo < 0){
            printf("Erro: o codigo deve ser positivo!\n");
            continue;
        }

        for(int i = 0; i < qntTitulos; i++){
          if(codigoRepetido == 1){
            codigoRepetido = 1;
          }
        }

        if(codigoRepetido == 1){
            printf("Erro: esse codigo ja foi cadastrado.\n");
            continue;
        }

        codigos[qntTitulos] = novoCodigo;

        printf("Digite a quantidade de exemplares em estoque: ");
        scanf("%d", &novoEstoque);

        while(novoEstoque < 0){
            printf("Erro: o estoque não pode ser negativo.");
            printf("Digite novamente a quantidade em estoque: ");
            scanf("%d", &novoEstoque);
        }

        estoque[qntTitulos] = novoEstoque;

        qntTitulos++;

        printf("Livro cadastrado com sucesso!");

        printf("\n\n====================================\n");
        printf("          ACERVO DA BIBLIOTECA\n");
        printf("====================================\n");

        int qtdExemplares = 0;

        for (int i = 0; i < qntTitulos; i++) {

        printf("\nCodigo: %d | Estoque: %d\n",
               codigos[i],
               estoque[i]);

        qtdExemplares = qtdExemplares + estoque[i];
        }

        printf("\n------------------------------------\n");
        printf("\nTotal de titulos: %d\n", qntTitulos);
        printf("Total de exemplares: %d\n", qtdExemplares);

        int codigoBusca;
        int posBusca = -1;

        printf("\n====================================\n");
        printf("             BUSCA DE LIVRO\n");
        printf("====================================\n");

        printf("\nDigite o codigo do livro que deseja buscar: ");
        scanf("%d", &codigoBusca);

        for (int i = 0; i < qntTitulos; i++) {

            if (codigos[i] == codigoBusca) {
                posBusca = i;
            }
        }

        if (posBusca == -1) {
            printf("Livro nao encontrado no acervo.\n");
        }

        else {
            printf("Livro encontrado!\n");
            printf("Codigo: %d\n", codigos[posBusca]);

            if (estoque[posBusca] == 0) {
                printf("Situacao: temporariamente indisponivel.\n");
            }

            else {
                printf("Situacao: disponivel.\n");
                printf("Quantidade em estoque: %d\n",
                   estoque[posBusca]);
            }
        }
    }
    return 0;
}
