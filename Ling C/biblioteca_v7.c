#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 3
#define MAX_USUARIOS 3
#define TAM_TEXTO 120

typedef struct {
    int codigos[MAX_USUARIOS];
    int inicio;
    int fim;
    int quantidade;
} Fila;

typedef struct {
    int codigo;
    char descricao[TAM_TEXTO];
    int estoque;
    Fila espera;
} Livro;

typedef struct {
    int codigo;
    char dados[TAM_TEXTO];
    int codigoLivroEmprestado;
} Usuario;

/* Prototipos */
int buscarLivro(Livro livros[], int qtdLivros, int codigo);
int buscarUsuario(Usuario usuarios[], int qtdUsuarios, int codigo);

int cadastrarLivro(Livro livros[], int qtdLivros);
int cadastrarUsuario(Usuario usuarios[], int qtdUsuarios);
void listarLivros(Livro livros[], int qtdLivros);
void listarUsuarios(Usuario usuarios[], int qtdUsuarios);
void consultarEmprestimos(Usuario usuarios[], int qtdUsuarios);

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
int filaCheia(Fila *fila);
int clienteNaFila(Fila *fila, int codigoUsuario);
int inserirFila(Fila *fila, int codigoUsuario);
int removerFila(Fila *fila, int *codigoUsuario);
void consultarFila(Livro *livro, Usuario usuarios[], int qtdUsuarios);

int emprestarLivro(Livro *livro, Usuario *usuario);
int devolverLivro(Livro *livro, Usuario *usuario,
                  Usuario usuarios[], int qtdUsuarios);
void solicitarEmprestimo(Livro livros[], int qtdLivros,
                         Usuario usuarios[], int qtdUsuarios);

int main() {
    Livro livros[MAX_LIVROS];
    Usuario usuarios[MAX_USUARIOS];

    int qtdLivros = 0;
    int qtdUsuarios = 0;
    int opcao;
    int codigo;
    int posLivro;

    do {
        printf("\n========== BIBLIOTECA - VERSAO 7 ==========\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar livro\n");
        printf("3 - Listar clientes\n");
        printf("4 - Listar livros\n");
        printf("5 - Realizar emprestimo / entrar na fila\n");
        printf("6 - Realizar devolucao\n");
        printf("7 - Consultar emprestimos\n");
        printf("8 - Consultar fila de espera de um livro\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n') {
                /* limpa a entrada */
            }
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1:
                if (qtdUsuarios == MAX_USUARIOS) {
                    printf("Limite de clientes atingido.\n");
                } else {
                    qtdUsuarios = cadastrarUsuario(usuarios, qtdUsuarios);
                }
                break;

            case 2:
                if (qtdLivros == MAX_LIVROS) {
                    printf("Limite de livros atingido.\n");
                } else {
                    qtdLivros = cadastrarLivro(livros, qtdLivros);
                }
                break;

            case 3:
                listarUsuarios(usuarios, qtdUsuarios);
                break;

            case 4:
                listarLivros(livros, qtdLivros);
                break;

            case 5:
                solicitarEmprestimo(livros, qtdLivros, usuarios, qtdUsuarios);
                break;

            case 6:
                printf("Digite o codigo do cliente: ");
                scanf("%d", &codigo);

                {
                    int posUsuario = buscarUsuario(usuarios, qtdUsuarios, codigo);

                    if (posUsuario == -1) {
                        printf("Cliente nao encontrado.\n");
                    } else if (usuarios[posUsuario].codigoLivroEmprestado == -1) {
                        printf("Este cliente nao possui livro emprestado.\n");
                    } else {
                        codigo = usuarios[posUsuario].codigoLivroEmprestado;
                        posLivro = buscarLivro(livros, qtdLivros, codigo);

                        if (posLivro == -1) {
                            printf("Livro do emprestimo nao encontrado.\n");
                        } else if (devolverLivro(&livros[posLivro],
                                                 &usuarios[posUsuario],
                                                 usuarios, qtdUsuarios)) {
                            printf("Devolucao registrada.\n");
                        } else {
                            printf("Nao foi possivel realizar a devolucao.\n");
                        }
                    }
                }
                break;

            case 7:
                consultarEmprestimos(usuarios, qtdUsuarios);
                break;

            case 8:
                printf("Digite o codigo do livro: ");
                scanf("%d", &codigo);
                posLivro = buscarLivro(livros, qtdLivros, codigo);

                if (posLivro == -1) {
                    printf("Livro nao encontrado.\n");
                } else {
                    consultarFila(&livros[posLivro], usuarios, qtdUsuarios);
                }
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

/* Procura um livro pelo codigo e devolve sua posicao no vetor.
   Se nao encontrar, devolve -1. */
int buscarLivro(Livro livros[], int qtdLivros, int codigo) {
    int i;

    for (i = 0; i < qtdLivros; i++) {
        if (livros[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

/* Procura um cliente pelo codigo e devolve sua posicao no vetor. */
int buscarUsuario(Usuario usuarios[], int qtdUsuarios, int codigo) {
    int i;

    for (i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

/* Cadastra livro e inicializa sua fila de espera. */
int cadastrarLivro(Livro livros[], int qtdLivros) {
    Livro novo;
    int pos;

    printf("Codigo do livro: ");
    scanf("%d", &novo.codigo);

    if (novo.codigo <= 0) {
        printf("O codigo deve ser maior que zero.\n");
        return qtdLivros;
    }

    pos = buscarLivro(livros, qtdLivros, novo.codigo);
    if (pos != -1) {
        printf("Este codigo ja esta cadastrado.\n");
        return qtdLivros;
    }

    printf("Quantidade em estoque: ");
    scanf("%d", &novo.estoque);

    if (novo.estoque < 0) {
        printf("O estoque nao pode ser negativo.\n");
        return qtdLivros;
    }

    getchar(); /* remove o ENTER deixado pelo scanf */

    printf("Descricao (titulo, autor, ano, categoria): ");
    fgets(novo.descricao, TAM_TEXTO, stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    inicializarFila(&novo.espera);

    livros[qtdLivros] = novo;
    printf("Livro cadastrado com sucesso.\n");

    return qtdLivros + 1;
}

/* Cadastra cliente. O valor -1 significa que ele nao tem emprestimo. */
int cadastrarUsuario(Usuario usuarios[], int qtdUsuarios) {
    Usuario novo;
    int pos;

    printf("Codigo do cliente: ");
    scanf("%d", &novo.codigo);

    if (novo.codigo <= 0) {
        printf("O codigo deve ser maior que zero.\n");
        return qtdUsuarios;
    }

    pos = buscarUsuario(usuarios, qtdUsuarios, novo.codigo);
    if (pos != -1) {
        printf("Este codigo ja esta cadastrado.\n");
        return qtdUsuarios;
    }

    getchar();

    printf("Nome e outras informacoes do cliente: ");
    fgets(novo.dados, TAM_TEXTO, stdin);
    novo.dados[strcspn(novo.dados, "\n")] = '\0';

    novo.codigoLivroEmprestado = -1;

    usuarios[qtdUsuarios] = novo;
    printf("Cliente cadastrado com sucesso.\n");

    return qtdUsuarios + 1;
}

/* Mostra todos os clientes cadastrados. */
void listarUsuarios(Usuario usuarios[], int qtdUsuarios) {
    int i;

    if (qtdUsuarios == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (i = 0; i < qtdUsuarios; i++) {
        printf("\nCodigo: %d\n", usuarios[i].codigo);
        printf("Dados: %s\n", usuarios[i].dados);

        if (usuarios[i].codigoLivroEmprestado == -1) {
            printf("Emprestimo: nenhum\n");
        } else {
            printf("Codigo do livro emprestado: %d\n",
                   usuarios[i].codigoLivroEmprestado);
        }
    }
}

/* Mostra os livros e seus exemplares disponiveis. */
void listarLivros(Livro livros[], int qtdLivros) {
    int i;

    if (qtdLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for (i = 0; i < qtdLivros; i++) {
        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Descricao: %s\n", livros[i].descricao);
        printf("Exemplares disponiveis: %d\n", livros[i].estoque);
        printf("Pessoas na fila: %d\n", livros[i].espera.quantidade);
    }
}

/* Lista os clientes que estao com algum livro emprestado. */
void consultarEmprestimos(Usuario usuarios[], int qtdUsuarios) {
    int i;
    int encontrou = 0;

    for (i = 0; i < qtdUsuarios; i++) {
        if (usuarios[i].codigoLivroEmprestado != -1) {
            printf("Cliente: %s | Codigo: %d | Livro: %d\n",
                   usuarios[i].dados,
                   usuarios[i].codigo,
                   usuarios[i].codigoLivroEmprestado);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nao existem livros emprestados no momento.\n");
    }
}

/* Deixa a fila em seu estado inicial: sem clientes. */
void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

/* Retorna 1 quando nao ha ninguem aguardando. */
int filaVazia(Fila *fila) {
    return fila->quantidade == 0;
}

/* Retorna 1 quando a fila atingiu sua capacidade. */
int filaCheia(Fila *fila) {
    return fila->quantidade == MAX_USUARIOS;
}

/* Verifica se o cliente ja esta aguardando este livro. */
int clienteNaFila(Fila *fila, int codigoUsuario) {
    int i;

    for (i = fila->inicio; i < fila->fim; i++) {
        if (fila->codigos[i] == codigoUsuario) {
            return 1;
        }
    }

    return 0;
}

/* INSERCAO: coloca o codigo do cliente no FINAL da fila. */
int inserirFila(Fila *fila, int codigoUsuario) {
    if (filaCheia(fila)) {
        return 0;
    }

    fila->codigos[fila->fim] = codigoUsuario;
    fila->fim++;
    fila->quantidade++;

    return 1;
}

/* REMOCAO: retira o primeiro cliente e desloca os demais.
   Assim, quem entrou primeiro continua sendo o proximo a ser atendido. */
int removerFila(Fila *fila, int *codigoUsuario) {
    int i;

    if (filaVazia(fila)) {
        return 0;
    }

    *codigoUsuario = fila->codigos[fila->inicio];

    for (i = 0; i < fila->quantidade - 1; i++) {
        fila->codigos[i] = fila->codigos[i + 1];
    }

    fila->quantidade--;
    fila->inicio = 0;
    fila->fim = fila->quantidade;

    return 1;
}

/* Exibe a fila na ordem em que os clientes serao atendidos. */
void consultarFila(Livro *livro, Usuario usuarios[], int qtdUsuarios) {
    int i;
    int posUsuario;

    if (filaVazia(&livro->espera)) {
        printf("Nao ha clientes na fila deste livro.\n");
        return;
    }

    printf("\nFila de espera do livro %d:\n", livro->codigo);

    for (i = livro->espera.inicio; i < livro->espera.fim; i++) {
        posUsuario = buscarUsuario(usuarios, qtdUsuarios,
                                   livro->espera.codigos[i]);

        if (posUsuario != -1) {
            printf("%d - %s (codigo %d)\n",
                   i + 1,
                   usuarios[posUsuario].dados,
                   usuarios[posUsuario].codigo);
        }
    }
}

/* Empresta um exemplar que ja esta disponivel. */
int emprestarLivro(Livro *livro, Usuario *usuario) {
    if (livro->estoque <= 0) {
        return 0;
    }

    if (usuario->codigoLivroEmprestado != -1) {
        return 0;
    }

    livro->estoque--;
    usuario->codigoLivroEmprestado = livro->codigo;

    return 1;
}

/* Registra a devolucao.
   Se houver fila, o exemplar vai diretamente para o primeiro cliente.
   Nesse caso, o estoque disponivel nao aumenta, pois o exemplar ja foi
   destinado ao proximo cliente. */
int devolverLivro(Livro *livro, Usuario *usuario,
                  Usuario usuarios[], int qtdUsuarios) {
    int codigoProximo;
    int posProximo;

    if (usuario->codigoLivroEmprestado != livro->codigo) {
        return 0;
    }

    usuario->codigoLivroEmprestado = -1;

    if (removerFila(&livro->espera, &codigoProximo)) {
        posProximo = buscarUsuario(usuarios, qtdUsuarios, codigoProximo);

        if (posProximo != -1 &&
            usuarios[posProximo].codigoLivroEmprestado == -1) {
            usuarios[posProximo].codigoLivroEmprestado = livro->codigo;

            printf("Proximo da fila: %s (codigo %d).\n",
                   usuarios[posProximo].dados, codigoProximo);
            printf("O exemplar foi destinado automaticamente a esse cliente.\n");
        } else {
            /* Caso de seguranca: se o cliente nao puder receber o livro,
               o exemplar volta para o estoque. */
            livro->estoque++;
            printf("O proximo cliente nao pode receber o livro.\n");
            printf("O exemplar voltou para o estoque.\n");
        }
    } else {
        livro->estoque++;
        printf("Nao havia fila. O exemplar voltou para o estoque.\n");
    }

    return 1;
}

/* Controla a solicitacao: empresta se houver estoque; caso contrario,
   oferece a entrada na fila de espera. */
void solicitarEmprestimo(Livro livros[], int qtdLivros,
                         Usuario usuarios[], int qtdUsuarios) {
    int codigoLivro;
    int codigoUsuario;
    int posLivro;
    int posUsuario;
    int resposta;
    int i;

    printf("Codigo do livro: ");
    scanf("%d", &codigoLivro);

    printf("Codigo do cliente: ");
    scanf("%d", &codigoUsuario);

    posLivro = buscarLivro(livros, qtdLivros, codigoLivro);
    posUsuario = buscarUsuario(usuarios, qtdUsuarios, codigoUsuario);

    if (posLivro == -1) {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (posUsuario == -1) {
        printf("Cliente nao encontrado. Cadastre-o antes de continuar.\n");
        return;
    }

    if (usuarios[posUsuario].codigoLivroEmprestado != -1) {
        printf("Este cliente ja possui um livro emprestado.\n");
        return;
    }

    if (clienteNaFila(&livros[posLivro].espera, codigoUsuario)) {
        printf("Este cliente ja esta na fila deste livro.\n");
        return;
    }

    /* Para manter o controle simples, cada cliente pode aguardar
       em apenas uma fila por vez. */
    for (i = 0; i < qtdLivros; i++) {
        if (i != posLivro && clienteNaFila(&livros[i].espera, codigoUsuario)) {
            printf("Este cliente ja esta aguardando outro livro.\n");
            return;
        }
    }

    if (livros[posLivro].estoque > 0) {
        if (emprestarLivro(&livros[posLivro], &usuarios[posUsuario])) {
            printf("Emprestimo realizado com sucesso.\n");
            printf("Estoque disponivel: %d\n", livros[posLivro].estoque);
        }
    } else {
        printf("Este livro esta sem exemplares disponiveis.\n");
        printf("Deseja entrar na fila de espera? (1 - Sim / 0 - Nao): ");
        scanf("%d", &resposta);

        if (resposta == 1) {
            if (inserirFila(&livros[posLivro].espera, codigoUsuario)) {
                printf("Cliente inserido no final da fila.\n");
                printf("Sua posicao na fila e: %d\n",
                       livros[posLivro].espera.quantidade);
            } else {
                printf("A fila esta cheia. Nao foi possivel inserir.\n");
            }
        } else {
            printf("Solicitacao cancelada.\n");
        }
    }
}
