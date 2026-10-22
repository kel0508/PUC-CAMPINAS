
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

void alterarEstoque(Livro *livro, int valor);
void registrarEmprestimo(Usuario *usuario, int codigoLivro);
void encerrarEmprestimo(Usuario *usuario);

int main() {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];

    int qtdLivros = 0;
    int qtdUsuarios = 0;
    int codigoBusca;
    int posBusca;
    int disponivel;
    int qtdExemplares;
    int indiceLivro;
    int indiceUsuario;
    int novoEstoque;
    int codigoLivro;

    // cadastra ate 3 livros
    while (qtdLivros < MAX_LIVROS) {
        qtdLivros = cadastrarLivro(livros, qtdLivros);
    }

    // mostra os livros
    listarLivros(livros, qtdLivros);

    // busca um livro
    printf("\nDigite o codigo do livro para buscar: ");
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

        disponivel = disponibilidadeLivro(livros[posBusca].estoque);

        if (disponivel == 1) {
            printf("Situacao: disponivel.\n");
        }
        else {
            printf("Situacao: temporariamente indisponivel.\n");
        }
    }

    // mostra o total de exemplares
    qtdExemplares = calcularQtdExemplares(livros, qtdLivros);

    printf("\nTotal de livros: %d\n", qtdLivros);
    printf("Total de exemplares: %d\n", qtdExemplares);

    // cadastra ate 3 usuarios
    while (qtdUsuarios < MAX_USUARIOS) {
        qtdUsuarios = cadastrarUsuario(usuarios, qtdUsuarios);
    }

    // mostra os usuarios
    listarUsuarios(usuarios, qtdUsuarios);

    // altera o estoque de um livro
    printf("\n====================================\n");
    printf(" ALTERACAO DE ESTOQUE\n");
    printf("====================================\n");

    printf("Digite o codigo do livro: ");
    scanf("%d", &codigoBusca);

    indiceLivro = buscarLivro(livros, qtdLivros, codigoBusca);

    if (indiceLivro == -1) {
        printf("Livro nao encontrado.\n");
    }
    else {
        printf("Estoque atual: %d\n", livros[indiceLivro].estoque);

        printf("Digite o novo estoque: ");
        scanf("%d", &novoEstoque);

        while (novoEstoque < 0) {
            printf("Erro: o estoque nao pode ser negativo.\n");
            printf("Digite o novo estoque: ");
            scanf("%d", &novoEstoque);
        }

        // altera o livro original
        alterarEstoque(&livros[indiceLivro], novoEstoque);

        // mostra o estoque atualizado
        printf("Estoque atualizado: %d\n",
               livros[indiceLivro].estoque);

        // permite fazer uma segunda alteracao
        printf("\nDigite outro valor para o estoque: ");
        scanf("%d", &novoEstoque);

        while (novoEstoque < 0) {
            printf("Erro: o estoque nao pode ser negativo.\n");
            printf("Digite outro valor para o estoque: ");
            scanf("%d", &novoEstoque);
        }

        alterarEstoque(&livros[indiceLivro], novoEstoque);

        printf("Estoque atualizado novamente: %d\n",
               livros[indiceLivro].estoque);
    }

    // registra um emprestimo
    printf("\n====================================\n");
    printf(" EMPRESTIMO DE LIVRO\n");
    printf("====================================\n");

    printf("Digite o codigo do usuario: ");
    scanf("%d", &codigoBusca);

    indiceUsuario = -1;

    // procura o usuario
    for (int i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigo == codigoBusca) {
            indiceUsuario = i;
        }
    }

    if (indiceUsuario == -1) {
        printf("Usuario nao encontrado.\n");
    }
    else if (usuarios[indiceUsuario].codigoLivroEmprestado != -1) {
        printf("Este usuario ja possui um livro emprestado.\n");
    }
    else {
        printf("Digite o codigo do livro para emprestimo: ");
        scanf("%d", &codigoLivro);

        indiceLivro = buscarLivro(livros, qtdLivros, codigoLivro);

        if (indiceLivro == -1) {
            printf("Livro nao encontrado.\n");
        }
        else if (disponibilidadeLivro(livros[indiceLivro].estoque) == 0) {
            printf("Livro sem exemplares disponiveis.\n");
        }
        else {
            // registra o livro no usuario
            registrarEmprestimo(&usuarios[indiceUsuario], codigoLivro);

            // diminui o estoque do livro
            alterarEstoque(&livros[indiceLivro],
                           livros[indiceLivro].estoque - 1);

            printf("\nEmprestimo registrado!\n");
            printf("Codigo do usuario: %d\n",
                   usuarios[indiceUsuario].codigo);
            printf("Livro emprestado: %d\n",
                   usuarios[indiceUsuario].codigoLivroEmprestado);
            printf("Estoque atualizado: %d\n",
                   livros[indiceLivro].estoque);
        }
    }

    // encerra um emprestimo
    printf("\n====================================\n");
    printf(" DEVOLUCAO DE LIVRO\n");
    printf("====================================\n");

    printf("Digite o codigo do usuario: ");
    scanf("%d", &codigoBusca);

    indiceUsuario = -1;

    // procura o usuario
    for (int i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigo == codigoBusca) {
            indiceUsuario = i;
        }
    }

    if (indiceUsuario == -1) {
        printf("Usuario nao encontrado.\n");
    }
    else if (usuarios[indiceUsuario].codigoLivroEmprestado == -1) {
        printf("Este usuario nao possui livro emprestado.\n");
    }
    else {
        // guarda o codigo do livro antes de encerrar o emprestimo
        codigoLivro = usuarios[indiceUsuario].codigoLivroEmprestado;

        // encerra o emprestimo do usuario
        encerrarEmprestimo(&usuarios[indiceUsuario]);

        // procura o livro devolvido
        indiceLivro = buscarLivro(livros, qtdLivros, codigoLivro);

        if (indiceLivro != -1) {
            alterarEstoque(&livros[indiceLivro],
                           livros[indiceLivro].estoque + 1);
        }

        printf("Devolucao registrada!\n");
        printf("Livro emprestado: %d\n",
               usuarios[indiceUsuario].codigoLivroEmprestado);

        if (indiceLivro != -1) {
            printf("Estoque atualizado: %d\n",
                   livros[indiceLivro].estoque);
        }
    }

    // mostra os dados finais
    printf("\n====================================\n");
    printf(" ACERVO FINAL\n");
    printf("====================================\n");

    listarLivros(livros, qtdLivros);

    printf("\n====================================\n");
    printf(" USUARIOS FINAIS\n");
    printf("====================================\n");

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

    livros[qtdLivros].codigo = novoCodigo;

    // solicita o estoque
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novoEstoque);

    while (novoEstoque < 0) {
        printf("Erro: o estoque nao pode ser negativo.\n");
        printf("Digite novamente: ");
        scanf("%d", &novoEstoque);
    }

    livros[qtdLivros].estoque = novoEstoque;

    // limpa o enter
    getchar();

    // solicita a descricao
    printf("Digite a descricao (Titulo; Autor; Ano; Categoria):\n");
    fgets(livros[qtdLivros].descricao, TAM_TEXTO, stdin);

    printf("Livro cadastrado com sucesso!\n");

    return qtdLivros + 1;
}

// lista os livros
void listarLivros(Livro livros[], int qtdLivros) {
    for (int i = 0; i < qtdLivros; i++) {
        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Descricao: %s", livros[i].descricao);
        printf("Estoque: %d\n", livros[i].estoque);
    }

    printf("\nTotal de exemplares: %d\n",
           calcularQtdExemplares(livros, qtdLivros));
}

// busca um livro pelo codigo
int buscarLivro(Livro livros[], int qtdLivros, int codigoBuscado) {
    for (int i = 0; i < qtdLivros; i++) {
        if (livros[i].codigo == codigoBuscado) {
            return i;
        }
    }

    return -1;
}

// calcula o total de exemplares
int calcularQtdExemplares(Livro livros[], int qtdLivros) {
    int qtdExemplares = 0;

    for (int i = 0; i < qtdLivros; i++) {
        qtdExemplares = qtdExemplares + livros[i].estoque;
    }

    return qtdExemplares;
}

// verifica a disponibilidade
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
    printf("\nDigite o codigo do usuario: ");
    scanf("%d", &usuarios[qtdUsuarios].codigo);
    getchar();

    printf("Digite os dados do usuario: ");
    fgets(usuarios[qtdUsuarios].dados, TAM_TEXTO, stdin);

    // indica que nao possui livro emprestado
    usuarios[qtdUsuarios].codigoLivroEmprestado = -1;

    printf("Usuario cadastrado com sucesso!\n");

    return qtdUsuarios + 1;
}

// lista os usuarios
void listarUsuarios(Usuario usuarios[], int qtdUsuarios) {
    for (int i = 0; i < qtdUsuarios; i++) {
        printf("\nCodigo: %d\n", usuarios[i].codigo);
        printf("Dados: %s", usuarios[i].dados);

        printf("Codigo do livro emprestado: %d\n",
               usuarios[i].codigoLivroEmprestado);
    }
}

// altera o estoque do livro original
void alterarEstoque(Livro *livro, int valor) {
    livro->estoque = valor;
}

// registra o emprestimo no usuario original
void registrarEmprestimo(Usuario *usuario, int codigoLivro) {
    usuario->codigoLivroEmprestado = codigoLivro;
}

// encerra o emprestimo do usuario original
void encerrarEmprestimo(Usuario *usuario) {
    usuario->codigoLivroEmprestado = -1;
}
