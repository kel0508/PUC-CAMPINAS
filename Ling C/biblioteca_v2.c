#include <stdio.h>
#define MAX_TITULOS 3
#define TAM_TEXTO 120

int main(){
    // guarda os codigos
    int codigos[MAX_TITULOS] = {0};
    // guarda o estoque
    int estoque[MAX_TITULOS] = {0};
    // guarda as descricoes
    char descricao1[TAM_TEXTO];
    char descricao2[TAM_TEXTO];
    char descricao3[TAM_TEXTO]
    // variaveis do cadastro
    int qntTitulos = 0;
    int novoCodigo;
    int novoEstoque;
    int codigoRepetido;
    // cadastra ate 3 livros
    while(qntTitulos < MAX_TITULOS){
        printf("\nDigite o codigo do livro: ");
        scanf("%d", &novoCodigo);
        // começa como nao repetido
        codigoRepetido = 0;
        // verifica se o codigo e negativo
        if(novoCodigo < 0){
            printf("Erro: o codigo deve ser positivo!\n");
            continue;
        }
        // verifica se o codigo ja existe
        for(int i = 0; i < qntTitulos; i++){
            if(codigos[i] == novoCodigo){
                codigoRepetido = 1;
            }
        }
        // mostra erro se o codigo repetir
        if(codigoRepetido == 1){
            printf("Erro: esse codigo ja foi cadastrado.\n");
            continue;
        }
        // guarda o codigo
        codigos[qntTitulos] = novoCodigo;
        // limpa o enter do scanf
        getchar();
        // pede a descricao
        printf("Digite a descricao do livro:\n");
        printf("(Titulo; Autor; Ano; Categoria)\n");
        // guarda a descricao de acordo com a posicao
        if(qntTitulos == 0){
            fgets(descricao1, TAM_TEXTO, stdin);
        }
        else if(qntTitulos == 1){
            fgets(descricao2, TAM_TEXTO, stdin);
        }
        else if(qntTitulos == 2){
            fgets(descricao3, TAM_TEXTO, stdin);
        }
        // pede o estoque
        printf("Digite a quantidade de exemplares em estoque: ");
        scanf("%d", &novoEstoque);
        // verifica se o estoque e negativo
        while(novoEstoque < 0){
            printf("Erro: o estoque nao pode ser negativo.\n");
            printf("Digite novamente a quantidade em estoque: ");
            scanf("%d", &novoEstoque);
        }
        // guarda o estoque
        estoque[qntTitulos] = novoEstoque;
        // aumenta a quantidade de livros
        qntTitulos++;
      
        printf("\nLivro cadastrado com sucesso!\n");
        // mostra o acervo
        printf("\n\n====================================\n");
        printf("          ACERVO DA BIBLIOTECA\n");
        printf("====================================\n");
        // guarda o total de exemplares
        int qtdExemplares = 0;
        // percorre os livros cadastrados
        for(int i = 0; i < qntTitulos; i++){
            printf("\nCodigo: %d\n", codigos[i]);
            // mostra a descricao
            if(i == 0){
                printf("Descricao: %s", descricao1);
            }
            else if(i == 1){
                printf("Descricao: %s", descricao2);
            }
            else if(i == 2){
                printf("Descricao: %s", descricao3);
            }
            // mostra o estoque
            printf("Estoque: %d\n", estoque[i]);
            // soma o estoque
            qtdExemplares = qtdExemplares + estoque[i];
        }
        printf("\n------------------------------------\n");
        printf("Total de titulos: %d\n", qntTitulos);
        printf("Total de exemplares: %d\n", qtdExemplares);
        // busca de livro
        int codigoBusca;
        int posBusca = -1;
      
        printf("\n====================================\n");
        printf("             BUSCA DE LIVRO\n");
        printf("====================================\n");

        printf("\nDigite o codigo do livro que deseja buscar: ");
        scanf("%d", &codigoBusca);
      
        // procura o codigo
        for(int i = 0; i < qntTitulos; i++){
            if(codigos[i] == codigoBusca){
                // guarda a posicao encontrada
                posBusca = i;
            }
        }
        // verifica se encontrou o livro
        if(posBusca == -1){
            printf("Livro nao encontrado no acervo.\n");
        }
        else{
            printf("\nLivro encontrado!\n");
            printf("Codigo: %d\n", codigos[posBusca]);
            // mostra a descricao encontrada
            if(posBusca == 0){
                printf("Descricao: %s", descricao1);
            }
            else if(posBusca == 1){
                printf("Descricao: %s", descricao2);
            }
            else if(posBusca == 2){
                printf("Descricao: %s", descricao3);
            }
            // verifica o estoque
            if(estoque[posBusca] == 0){
                printf("Situacao: temporariamente indisponivel.\n");
            }
            else{
                printf("Situacao: disponivel.\n");
                printf("Quantidade em estoque: %d\n",
                       estoque[posBusca]);
            }
        }
    }
    return 0;
}
