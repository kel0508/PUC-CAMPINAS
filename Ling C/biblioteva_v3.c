
#include <stdio.h>

#define MAX_TITULOS 3
#define TAM_TEXTO 120

// prototipos das funcoes
int cadastrarTitulo(
    int codigos[],
    int estoques[],
    char descricao1[],
    char descricao2[],
    char descricao3[],
    int qtdTitulos
);

void listarTitulos(
    int codigos[],
    int estoques[],
    char descricao1[],
    char descricao2[],
    char descricao3[],
    int qtdTitulos
);

int buscarTitulo(int codigos[], int qtdTitulos, int codigoBuscado);

int calcularQtdExemplares(int estoques[], int qtdTitulos);

int disponibilidadeTitulo(int qtdEstoque);

int main() {
    // guarda os codigos e os estoques
    int codigos[MAX_TITULOS] = {0};
    int estoques[MAX_TITULOS] = {0};

    // guarda as descricoes
    char descricao1[TAM_TEXTO];
    char descricao2[TAM_TEXTO];
    char descricao3[TAM_TEXTO];

    int qtdTitulos = 0;
    int codigoBusca;
    int posBusca;
    int disponivel;
    int qtdExemplares;

    // cadastra ate 3 titulos
    while (qtdTitulos < MAX_TITULOS) {
        qtdTitulos = cadastrarTitulo(
            codigos,
            estoques,
            descricao1,
            descricao2,
            descricao3,
            qtdTitulos
        );
    }

    // mostra todos os titulos
    listarTitulos(
        codigos,
        estoques,
        descricao1,
        descricao2,
        descricao3,
        qtdTitulos
    );

    // solicita o codigo para busca
    printf("\n====================================\n");
    printf(" BUSCA DE LIVRO\n");
    printf("====================================\n");

    printf("\nDigite o codigo do livro que deseja buscar: ");
    scanf("%d", &codigoBusca);

    // procura o titulo
    posBusca = buscarTitulo(codigos, qtdTitulos, codigoBusca);

    // mostra o resultado da busca
    if (posBusca == -1) {
        printf("\nTitulo nao encontrado.\n");
    }
    else {
        printf("\nTitulo encontrado!\n");
        printf("Codigo: %d\n", codigos[posBusca]);

        // mostra a descricao encontrada
        if (posBusca == 0) {
            printf("Descricao: %s", descricao1);
        }
        else if (posBusca == 1) {
            printf("Descricao: %s", descricao2);
        }
        else if (posBusca == 2) {
            printf("Descricao: %s", descricao3);
        }

        // verifica a disponibilidade
        disponivel = disponibilidadeTitulo(estoques[posBusca]);

        if (disponivel == 1) {
            printf("Situacao: disponivel.\n");
            printf("Quantidade em estoque: %d\n", estoques[posBusca]);
        }
        else {
            printf("Situacao: temporariamente indisponivel.\n");
        }
    }

    // calcula o total de exemplares
    qtdExemplares = calcularQtdExemplares(estoques, qtdTitulos);

    printf("\n====================================\n");
    printf(" RESUMO DO ACERVO\n");
    printf("====================================\n");
    printf("Total de titulos: %d\n", qtdTitulos);
    printf("Total de exemplares: %d\n", qtdExemplares);

    return 0;
}

// cadastra um titulo
int cadastrarTitulo(
    int codigos[],
    int estoques[],
    char descricao1[],
    char descricao2[],
    char descricao3[],
    int qtdTitulos
) {
    int novoCodigo;
    int novoEstoque;
    int codigoRepetido;

    // verifica o codigo
    while (1) {
        printf("\nDigite o codigo do livro: ");
        scanf("%d", &novoCodigo);

        codigoRepetido = 0;

        if (novoCodigo < 0) {
            printf("Erro: o codigo nao pode ser negativo.\n");
            continue;
        }

        // verifica se o codigo ja existe
        for (int i = 0; i < qtdTitulos; i++) {
            if (codigos[i] == novoCodigo) {
                codigoRepetido = 1;
            }
        }

        if (codigoRepetido == 1) {
            printf("Erro: esse codigo ja foi cadastrado.\n");
        }
        else {
            break;
        }
    }

    // guarda o codigo
    codigos[qtdTitulos] = novoCodigo;

    // solicita o estoque
    printf("Digite a quantidade de exemplares em estoque: ");
    scanf("%d", &novoEstoque);

    // impede estoque negativo
    while (novoEstoque < 0) {
        printf("Erro: o estoque nao pode ser negativo.\n");
        printf("Digite novamente a quantidade em estoque: ");
        scanf("%d", &novoEstoque);
    }

    // guarda o estoque
    estoques[qtdTitulos] = novoEstoque;

    // limpa o enter do scanf
    getchar();

    // solicita a descricao
    printf("Digite a descricao do livro:\n");
    printf("(Titulo; Autor; Ano; Categoria)\n");

    // guarda a descricao na posicao correta
    if (qtdTitulos == 0) {
        fgets(descricao1, TAM_TEXTO, stdin);
    }
    else if (qtdTitulos == 1) {
        fgets(descricao2, TAM_TEXTO, stdin);
    }
    else if (qtdTitulos == 2) {
        fgets(descricao3, TAM_TEXTO, stdin);
    }

    printf("\nLivro cadastrado com sucesso!\n");

    // devolve a nova quantidade de titulos
    return qtdTitulos + 1;
}

// lista todos os titulos
void listarTitulos(
    int codigos[],
    int estoques[],
    char descricao1[],
    char descricao2[],
    char descricao3[],
    int qtdTitulos
) {
    int qtdExemplares;

    // mostra o acervo
    printf("\n====================================\n");
    printf(" ACERVO DA BIBLIOTECA\n");
    printf("====================================\n");

    // percorre os titulos cadastrados
    for (int i = 0; i < qtdTitulos; i++) {
        printf("\nCodigo: %d\n", codigos[i]);

        // mostra a descricao
        if (i == 0) {
            printf("Descricao: %s", descricao1);
        }
        else if (i == 1) {
            printf("Descricao: %s", descricao2);
        }
        else if (i == 2) {
            printf("Descricao: %s", descricao3);
        }

        printf("Estoque: %d\n", estoques[i]);
    }

    // calcula o total de exemplares
    qtdExemplares = calcularQtdExemplares(estoques, qtdTitulos);

    printf("\n------------------------------------\n");
    printf("Total de titulos: %d\n", qtdTitulos);
    printf("Total de exemplares: %d\n", qtdExemplares);
}

// busca um titulo pelo codigo
int buscarTitulo(int codigos[], int qtdTitulos, int codigoBuscado) {
    // procura o codigo
    for (int i = 0; i < qtdTitulos; i++) {
        if (codigos[i] == codigoBuscado) {
            return i;
        }
    }

    // retorna -1 se nao encontrar
    return -1;
}

// calcula o total de exemplares
int calcularQtdExemplares(int estoques[], int qtdTitulos) {
    int qtdExemplares = 0;

    // soma os estoques
    for (int i = 0; i < qtdTitulos; i++) {
        qtdExemplares = qtdExemplares + estoques[i];
    }

    return qtdExemplares;
}

// verifica se o titulo esta disponivel
int disponibilidadeTitulo(int qtdEstoque) {
    if (qtdEstoque > 0) {
        return 1;
    }
    else {
        return 0;
    }
}
