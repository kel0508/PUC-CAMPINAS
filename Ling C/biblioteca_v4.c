
#include <stdio.h>

#define MAX_LIVROS 3
#define MAX_USUARIOS 3
#define TAM_TEXTO 120

// guarda os dados de cada livro
typedef struct {
    int codigo;
    char descricao[TAM_TEXTO];
    int estoque;
} Livro;

// guarda os dados de cada usuario
typedef struct {
    int codigo;
    char dados[TAM_TEXTO];
    int codigoLivroEmprestado;
} Usuario;

// prototipos das funcoes
int cadastrarLivro(Livro livros[], int qtdLivros);
void listarLivros(Livro livros[], int qtdLivros);
int buscarLivro(Livro livros[], int qtdLivros, int codigoBuscado);
int calcularQtdExemplares(Livro livros[], int qtdLivros);
int disponibilidadeLivro(int qtdEstoque);

int cadastrarUsuario(Usuario usuarios[], int qtdUsuarios);
void listarUsuarios(Usuario usuarios[], int qtdUsuarios);

int main() {
    // guarda os livros e os usuarios
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];

    int qtdLivros = 0;
    int qtdUsuarios = 0;
    int codigoBusca;
    int posBusca;
    int disponivel;
    int qtdExemplares;

    // cadastra ate 3 livros
    while (qtdLivros < MAX_LIVROS) {
        qtdLivros = cadastrarLivro(livros, qtdLivros);
    }

    // lista os livros
    listarLivros(livros, qtdLivros);

    // busca um livro
    printf("\n====================================\n");
    printf(" BUSCA DE LIVRO\n");
    printf("====================================\n");

    printf("Digite o codigo do livro que deseja buscar: ");
    scanf("%d", &codigoBusca);

    posBusca = buscarLivro(livros, qtdLivros, codigoBusca);

    if (posBusca == -1) {
        printf("Livro nao encontrado.\n");
    }
    else {
        printf("\nLivro encontrado!\n");
        printf("Codigo: %d\n", livros[posBusca].codigo);
        printf("Descricao: %s", livros[posBusca].descricao);
        printf("Estoque: %d\n", livros[posBusca].estoque);

        // verifica a disponibilidade
        disponivel = disponibilidadeLivro(livros[posBusca].estoque);

        if (disponivel == 1) {
            printf("Situacao: disponivel.\n");
        }
        else {
            printf("Situacao: temporariamente indisponivel.\n");
        }
    }

    // calcula o total de exemplares
    qtdExemplares = calcularQtdExemplares(livros, qtdLivros);

    printf("\nTotal de livros cadastrados: %d\n", qtdLivros);
    printf("Total de exemplares: %d\n", qtdExemplares);

    // cadastra ate 3 usuarios
    printf("\n====================================\n");
    printf(" CADASTRO DE USUARIOS\n");
    printf("====================================\n");

    while (qtdUsuarios < MAX_USUARIOS) {
        qtdUsuarios = cadastrarUsuario(usuarios, qtdUsuarios);
    }

    // lista os usuarios
    listarUsuarios(usuarios, qtdUsuarios);

    return 0;
}

// cadastra um livro
int cadastrarLivro(Livro livros[], int qtdLivros) {
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
        for (int i = 0; i < qtdLivros; i++) {
            if (livros[i].codigo == novoCodigo) {
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
    livros[qtdLivros].codigo = novoCodigo;

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
    livros[qtdLivros].estoque = novoEstoque;

    // limpa o enter do scanf
    getchar();

    // solicita a descricao
    printf("Digite a descricao do livro:\n");
    printf("(Titulo; Autor; Ano; Categoria)\n");

    fgets(livros[qtdLivros].descricao, TAM_TEXTO, stdin);

    printf("Livro cadastrado com sucesso!\n");

    // devolve a nova quantidade de livros
    return qtdLivros + 1;
}

// lista os livros
void listarLivros(Livro livros[], int qtdLivros) {
    printf("\n====================================\n");
    printf(" ACERVO DA BIBLIOTECA\n");
    printf("====================================\n");

    // percorre os livros cadastrados
    for (int i = 0; i < qtdLivros; i++) {
        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Descricao: %s", livros[i].descricao);
        printf("Estoque: %d\n", livros[i].estoque);
    }
}

// busca um livro pelo codigo
int buscarLivro(Livro livros[], int qtdLivros, int codigoBuscado) {
    // procura o codigo
    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].codigo == codigoBuscado) {
            return i;
        }
    }

    // retorna -1 se nao encontrar
    return -1;
}

// calcula o total de exemplares
int calcularQtdExemplares(Livro livros[], int qtdLivros) {
    int qtdExemplares = 0;

    // soma os estoques
    for (int i = 0; i < qtdLivros; i++) {
        qtdExemplares = qtdExemplares + livros[i].estoque;
    }

    return qtdExemplares;
}

// verifica se o livro esta disponivel
int disponibilidadeLivro(int qtdEstoque) {
    if (qtdEstoque > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// cadastra um usuario
int cadastrarUsuario(Usuario usuarios[], int qtdUsuarios) {
    // solicita o codigo do usuario
    printf("\nDigite o codigo do usuario: ");
    scanf("%d", &usuarios[qtdUsuarios].codigo);
    getchar();

    // solicita os dados do usuario
    printf("Digite os dados do usuario: ");
    fgets(usuarios[qtdUsuarios].dados, TAM_TEXTO, stdin);

    // indica que o usuario nao possui livro emprestado
    usuarios[qtdUsuarios].codigoLivroEmprestado = -1;

    printf("Usuario cadastrado com sucesso!\n");

    // devolve a nova quantidade de usuarios
    return qtdUsuarios + 1;
}

// lista os usuarios
void listarUsuarios(Usuario usuarios[], int qtdUsuarios) {
    printf("\n====================================\n");
    printf(" USUARIOS CADASTRADOS\n");
    printf("====================================\n");

    // percorre os usuarios cadastrados
    for (int i = 0; i < qtdUsuarios; i++) {
        printf("\nCodigo: %d\n", usuarios[i].codigo);
        printf("Dados: %s", usuarios[i].dados);

        if (usuarios[i].codigoLivroEmprestado == -1) {
            printf("Livro emprestado: nenhum\n");
        }
        else {
            printf("Codigo do livro emprestado: %d\n",
                   usuarios[i].codigoLivroEmprestado);
        }
    }
}
