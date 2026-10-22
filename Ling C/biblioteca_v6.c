
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
int cadastrarLivro(Livro livros[], int qtd);
int cadastrarUsuario(Usuario usuarios[], int qtd);
void listarLivros(Livro livros[], int qtd);
void listarUsuarios(Usuario usuarios[], int qtd);
int buscarLivro(Livro livros[], int qtd, int codigo);
int buscarUsuario(Usuario usuarios[], int qtd, int codigo);
int calcularQtdExemplares(Livro livros[], int qtd);
int emprestarLivro(Livro *livro, Usuario *usuario);
int devolverLivro(Livro *livro, Usuario *usuario);

int main() {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];

    int qtdLivros = 0;
    int qtdUsuarios = 0;
    int opcao;
    int codigo;
    int codigoUsuario;
    int posLivro;
    int posUsuario;
    int escolha;

    // controla o menu
    do {
        printf("\n========== BIBLIOTECA ==========\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Listar livros\n");
        printf("4 - Buscar registro\n");
        printf("5 - Emprestar livro\n");
        printf("6 - Devolver livro\n");
        printf("7 - Listar usuarios\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (qtdLivros == MAX_LIVROS) {
                    printf("Limite de livros atingido.\n");
                }
                else {
                    qtdLivros = cadastrarLivro(livros, qtdLivros);
                }
                break;

            case 2:
                if (qtdUsuarios == MAX_USUARIOS) {
                    printf("Limite de usuarios atingido.\n");
                }
                else {
                    qtdUsuarios = cadastrarUsuario(usuarios, qtdUsuarios);
                }
                break;

            case 3:
                listarLivros(livros, qtdLivros);
                printf("Total de exemplares: %d\n",
                       calcularQtdExemplares(livros, qtdLivros));
                break;

            case 4:
                printf("\n1 - Buscar livro\n");
                printf("2 - Buscar usuario\n");
                printf("Escolha: ");
                scanf("%d", &escolha);

                if (escolha == 1) {
                    printf("Digite o codigo do livro: ");
                    scanf("%d", &codigo);

                    posLivro = buscarLivro(livros, qtdLivros, codigo);

                    if (posLivro == -1) {
                        printf("Livro nao encontrado.\n");
                    }
                    else {
                        printf("\nLivro encontrado!\n");
                        printf("Codigo: %d\n", livros[posLivro].codigo);
                        printf("Descricao: %s", livros[posLivro].descricao);
                        printf("Estoque: %d\n", livros[posLivro].estoque);
                    }
                }
                else if (escolha == 2) {
                    printf("Digite o codigo do usuario: ");
                    scanf("%d", &codigo);

                    posUsuario = buscarUsuario(
                        usuarios, qtdUsuarios, codigo
                    );

                    if (posUsuario == -1) {
                        printf("Usuario nao encontrado.\n");
                    }
                    else {
                        printf("\nUsuario encontrado!\n");
                        printf("Codigo: %d\n", usuarios[posUsuario].codigo);
                        printf("Dados: %s", usuarios[posUsuario].dados);
                        printf("Livro emprestado: %d\n",
                               usuarios[posUsuario].codigoLivroEmprestado);
                    }
                }
                else {
                    printf("Opcao de busca invalida.\n");
                }
                break;

            case 5:
                printf("Digite o codigo do livro: ");
                scanf("%d", &codigo);

                printf("Digite o codigo do usuario: ");
                scanf("%d", &codigoUsuario);

                posLivro = buscarLivro(livros, qtdLivros, codigo);
                posUsuario = buscarUsuario(
                    usuarios, qtdUsuarios, codigoUsuario
                );

                // verifica os dois registros antes do emprestimo
                if (posLivro == -1) {
                    printf("Livro nao encontrado.\n");
                }
                else if (posUsuario == -1) {
                    printf("Usuario nao encontrado.\n");
                }
                else if (emprestarLivro(
                    &livros[posLivro],
                    &usuarios[posUsuario]
                )) {
                    printf("Emprestimo realizado com sucesso!\n");
                    printf("Estoque atual: %d\n",
                           livros[posLivro].estoque);
                    printf("Livro do usuario: %d\n",
                           usuarios[posUsuario].codigoLivroEmprestado);
                }
                else {
                    printf("Nao foi possivel realizar o emprestimo.\n");
                    printf("Verifique o estoque e os emprestimos do usuario.\n");
                }
                break;

            case 6:
                printf("Digite o codigo do usuario: ");
                scanf("%d", &codigoUsuario);

                posUsuario = buscarUsuario(
                    usuarios, qtdUsuarios, codigoUsuario
                );

                if (posUsuario == -1) {
                    printf("Usuario nao encontrado.\n");
                }
                else if (usuarios[posUsuario].codigoLivroEmprestado == -1) {
                    printf("Este usuario nao possui livro emprestado.\n");
                }
                else {
                    // procura o livro registrado no usuario
                    codigo = usuarios[posUsuario].codigoLivroEmprestado;
                    posLivro = buscarLivro(livros, qtdLivros, codigo);

                    if (posLivro == -1) {
                        printf("Livro do emprestimo nao encontrado.\n");
                    }
                    else if (devolverLivro(
                        &livros[posLivro],
                        &usuarios[posUsuario]
                    )) {
                        printf("Devolucao realizada com sucesso!\n");
                        printf("Estoque atual: %d\n",
                               livros[posLivro].estoque);
                        printf("Livro do usuario: %d\n",
                               usuarios[posUsuario].codigoLivroEmprestado);
                    }
                    else {
                        printf("Nao foi possivel realizar a devolucao.\n");
                    }
                }
                break;

            case 7:
                listarUsuarios(usuarios, qtdUsuarios);
                break;

            case 0:
                printf("Sistema encerrado.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

// cadastra um livro
int cadastrarLivro(Livro livros[], int qtd) {
    Livro novo;
    int pos;

    printf("Digite o codigo do livro: ");
    scanf("%d", &novo.codigo);

    // verifica se o codigo e valido
    if (novo.codigo <= 0) {
        printf("Erro: o codigo deve ser maior que zero.\n");
        return qtd;
    }

    // verifica se o codigo ja existe
    pos = buscarLivro(livros, qtd, novo.codigo);

    if (pos != -1) {
        printf("Erro: codigo de livro ja cadastrado.\n");
        return qtd;
    }

    printf("Digite o estoque: ");
    scanf("%d", &novo.estoque);

    if (novo.estoque < 0) {
        printf("Erro: o estoque nao pode ser negativo.\n");
        return qtd;
    }

    // limpa o enter antes de ler a descricao
    getchar();

    printf("Digite a descricao (Titulo; Autor; Ano; Categoria):\n");
    fgets(novo.descricao, TAM_TEXTO, stdin);

    // guarda o livro depois de validar os dados
    livros[qtd] = novo;

    printf("Livro cadastrado com sucesso!\n");

    return qtd + 1;
}

// cadastra um usuario
int cadastrarUsuario(Usuario usuarios[], int qtd) {
    Usuario novo;
    int pos;

    printf("Digite o codigo do usuario: ");
    scanf("%d", &novo.codigo);

    // verifica se o codigo e valido
    if (novo.codigo <= 0) {
        printf("Erro: o codigo deve ser maior que zero.\n");
        return qtd;
    }

    // verifica se o codigo ja existe
    pos = buscarUsuario(usuarios, qtd, novo.codigo);

    if (pos != -1) {
        printf("Erro: codigo de usuario ja cadastrado.\n");
        return qtd;
    }

    getchar();

    printf("Digite os dados do usuario: ");
    fgets(novo.dados, TAM_TEXTO, stdin);

    // indica que o usuario nao possui emprestimo
    novo.codigoLivroEmprestado = -1;

    // guarda o usuario depois de validar os dados
    usuarios[qtd] = novo;

    printf("Usuario cadastrado com sucesso!\n");

    return qtd + 1;
}

// lista os livros
void listarLivros(Livro livros[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Descricao: %s", livros[i].descricao);
        printf("Estoque: %d\n", livros[i].estoque);
    }
}

// lista os usuarios
void listarUsuarios(Usuario usuarios[], int qtd) {
    if (qtd == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\nCodigo: %d\n", usuarios[i].codigo);
        printf("Dados: %s", usuarios[i].dados);
        printf("Livro emprestado: %d\n",
               usuarios[i].codigoLivroEmprestado);
    }
}

// busca um livro pelo codigo
int buscarLivro(Livro livros[], int qtd, int codigo) {
    for (int i = 0; i < qtd; i++) {
        if (livros[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

// busca um usuario pelo codigo
int buscarUsuario(Usuario usuarios[], int qtd, int codigo) {
    for (int i = 0; i < qtd; i++) {
        if (usuarios[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

// calcula o total de exemplares
int calcularQtdExemplares(Livro livros[], int qtd) {
    int total = 0;

    for (int i = 0; i < qtd; i++) {
        total = total + livros[i].estoque;
    }

    return total;
}

// realiza o emprestimo
int emprestarLivro(Livro *livro, Usuario *usuario) {
    // verifica todas as regras antes de alterar os dados
    if (livro->estoque <= 0) {
        return 0;
    }

    if (usuario->codigoLivroEmprestado != -1) {
        return 0;
    }

    // atualiza o livro e o usuario
    livro->estoque = livro->estoque - 1;
    usuario->codigoLivroEmprestado = livro->codigo;

    return 1;
}

// realiza a devolucao
int devolverLivro(Livro *livro, Usuario *usuario) {
    // verifica se existe um emprestimo correspondente
    if (usuario->codigoLivroEmprestado == -1) {
        return 0;
    }

    if (usuario->codigoLivroEmprestado != livro->codigo) {
        return 0;
    }

    // atualiza o livro e o usuario
    livro->estoque = livro->estoque + 1;
    usuario->codigoLivroEmprestado = -1;

    return 1;
}
