#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TEXTO 120
#define TAM_HISTORICO 250
#define MAX_FILA 100

/* -------------------- ESTRUTURAS -------------------- */

/* Fila de espera de um livro */
typedef struct {
    int codigos[MAX_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

/* No da lista encadeada de cilentes */
typedef struct Cliente {
    int codigo;
    char dados[TAM_TEXTO];
    int codigoLivroEmprestado;
    int codigoLivroNaFila;
    struct Cliente *prox;
} Cliente;

/* No da lista encadeada de livros. */
typedef struct Livro {
    int codigo;
    char descricao[TAM_TEXTO];
    int estoque;
    Fila espera;
    struct Livro *prox;
} Livro;

/* No da pilha de historico. O topo aponta para a operacao mais recente. */
typedef struct Historico {
    char operacao[TAM_HISTORICO];
    struct Historico *prox;
} Historico;

/* -------------------- PROTOTIPOS -------------------- */

/* Entrada de dados */
int lerInteiro(const char mensagem[]);
void lerTexto(const char mensagem[], char texto[], int tamanho);

/* Clientes: lista encadeada */
Cliente *buscarCliente(Cliente *inicioClientes, int codigo);
void cadastrarCliente(Cliente **inicioClientes, Historico **topo);
void listarClientes(Cliente *inicioClientes);

/* Livros: lista encadeada */
Livro *buscarLivro(Livro *inicioLivros, int codigo);
void cadastrarLivro(Livro **inicioLivros, Historico **topo);
void listarLivros(Livro *inicioLivros);

/* Fila de espera */
void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
int filaCheia(Fila *fila);
int clienteNaFila(Fila *fila, int codigoCliente);
int inserirFila(Fila *fila, int codigoCliente);
int removerFila(Fila *fila, int *codigoCliente);
void consultarFila(Livro *livro, Cliente *inicioClientes);

/* Emprestimos e devolucoes */
void realizarEmprestimo(Livro *inicioLivros, Cliente *inicioClientes, Historico **topo);
void realizarDevolucao(Livro *inicioLivros, Cliente *inicioClientes, Historico **topo);
void consultarEmprestimos(Cliente *inicioClientes);

/* Pilha de historico */
void empilharHistorico(Historico **topo, const char operacao[]);
void mostrarHistorico(Historico *topo);

/* Liberacao de memoria */
void liberarClientes(Cliente *inicioClientes);
void liberarLivros(Livro *inicioLivros);
void liberarHistorico(Historico *topo);

/* -------------------- FUNCAO PRINCIPAL -------------------- */

int main() {
    Cliente *inicioClientes = NULL;
    Livro *inicioLivros = NULL;
    Historico *topoHistorico = NULL;

    int opcao;
    int codigo;
    Cliente *clienteEncontrado;
    Livro *livroEncontrado;

    do {
        printf("\n========== SISTEMA DE BIBLIOTECA - VERSAO 8 ==========\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Cadastrar livro\n");
        printf("3 - Listar clientes\n");
        printf("4 - Listar livros\n");
        printf("5 - Buscar cliente\n");
        printf("6 - Buscar livro\n");
        printf("7 - Realizar emprestimo / entrar na fila\n");
        printf("8 - Realizar devolucao\n");
        printf("9 - Consultar emprestimos\n");
        printf("10 - Exibir historico de operacoes\n");
        printf("11 - Consultar fila de espera de um livro\n");
        printf("0 - Sair\n");

        opcao = lerInteiro("Escolha uma opcao: ");

        switch (opcao) {
            case 1:
                cadastrarCliente(&inicioClientes, &topoHistorico);
                break;

            case 2:
                cadastrarLivro(&inicioLivros, &topoHistorico);
                break;

            case 3:
                listarClientes(inicioClientes);
                break;

            case 4:
                listarLivros(inicioLivros);
                break;

            case 5:
                codigo = lerInteiro("Digite o codigo do cliente: ");
                clienteEncontrado = buscarCliente(inicioClientes, codigo);

                if (clienteEncontrado == NULL) {
                    printf("Cliente nao encontrado.\n");
                } else {
                    printf("\nCliente encontrado!\n");
                    printf("Codigo: %d\n", clienteEncontrado->codigo);
                    printf("Dados: %s\n", clienteEncontrado->dados);

                    if (clienteEncontrado->codigoLivroEmprestado == -1) {
                        printf("Emprestimo: nenhum\n");
                    } else {
                        printf("Livro emprestado: %d\n",
                               clienteEncontrado->codigoLivroEmprestado);
                    }

                    if (clienteEncontrado->codigoLivroNaFila == -1) {
                        printf("Fila de espera: nenhuma\n");
                    } else {
                        printf("Aguardando livro: %d\n",
                               clienteEncontrado->codigoLivroNaFila);
                    }
                }
                break;

            case 6:
                codigo = lerInteiro("Digite o codigo do livro: ");
                livroEncontrado = buscarLivro(inicioLivros, codigo);

                if (livroEncontrado == NULL) {
                    printf("Livro nao encontrado.\n");
                } else {
                    printf("\nLivro encontrado!\n");
                    printf("Codigo: %d\n", livroEncontrado->codigo);
                    printf("Descricao: %s\n", livroEncontrado->descricao);
                    printf("Estoque disponivel: %d\n",
                           livroEncontrado->estoque);
                    printf("Pessoas na fila: %d\n",
                           livroEncontrado->espera.quantidade);
                }
                break;

            case 7:
                realizarEmprestimo(inicioLivros, inicioClientes,
                                   &topoHistorico);
                break;

            case 8:
                realizarDevolucao(inicioLivros, inicioClientes,
                                  &topoHistorico);
                break;

            case 9:
                consultarEmprestimos(inicioClientes);
                break;

            case 10:
                mostrarHistorico(topoHistorico);
                break;

            case 11:
                codigo = lerInteiro("Digite o codigo do livro: ");
                livroEncontrado = buscarLivro(inicioLivros, codigo);

                if (livroEncontrado == NULL) {
                    printf("Livro nao encontrado.\n");
                } else {
                    consultarFila(livroEncontrado, inicioClientes);
                }
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida. Escolha uma opcao do menu.\n");
        }

    } while (opcao != 0);

    /* Toda memoria reservada com malloc deve ser liberada. */
    liberarClientes(inicioClientes);
    liberarLivros(inicioLivros);
    liberarHistorico(topoHistorico);

    printf("Memoria liberada. Sistema encerrado.\n");
    return 0;
}

/* -------------------- FUNCOES DE ENTRADA -------------------- */

/* Le um numero inteiro e repete a leitura se a entrada for invalida. */
int lerInteiro(const char mensagem[]) {
    char linha[80];
    int valor;
    char sobra;

    while (1) {
        printf("%s", mensagem);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            return 0;
        }

        if (sscanf(linha, " %d %c", &valor, &sobra) == 1) {
            return valor;
        }

        printf("Entrada invalida. Digite somente um numero inteiro.\n");
    }
}

/* Le um texto completo, inclusive com espacos. */
void lerTexto(const char mensagem[], char texto[], int tamanho) {
    size_t comprimento;

    printf("%s", mensagem);

    if (fgets(texto, tamanho, stdin) == NULL) {
        texto[0] = '\0';
        return;
    }

    comprimento = strlen(texto);

    if (comprimento > 0 && texto[comprimento - 1] == '\n') {
        texto[comprimento - 1] = '\0';
    } else {
        /* Descarta o restante caso o texto seja maior que o vetor. */
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
            /* continua descartando */
        }
    }
}

/* -------------------- LISTA ENCADEADA DE CLIENTES -------------------- */

/* Percorre a lista ate encontrar o codigo ou chegar ao NULL. */
Cliente *buscarCliente(Cliente *inicioClientes, int codigo) {
    Cliente *atual = inicioClientes;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

/* Cria dinamicamente um novo no e o coloca no final da lista. */
void cadastrarCliente(Cliente **inicioClientes, Historico **topo) {
    Cliente *novo;
    Cliente *atual;
    char registro[TAM_HISTORICO];
    int codigo;

    codigo = lerInteiro("Codigo do cliente (maior que zero): ");

    if (codigo <= 0) {
        printf("O codigo deve ser maior que zero.\n");
        return;
    }

    if (buscarCliente(*inicioClientes, codigo) != NULL) {
        printf("Ja existe um cliente com esse codigo.\n");
        return;
    }

    novo = (Cliente *) malloc(sizeof(Cliente));

    if (novo == NULL) {
        printf("Erro: nao foi possivel reservar memoria.\n");
        return;
    }

    novo->codigo = codigo;
    lerTexto("Nome e outras informacoes do cliente: ",
             novo->dados, TAM_TEXTO);

    novo->codigoLivroEmprestado = -1;
    novo->codigoLivroNaFila = -1;
    novo->prox = NULL;

    if (*inicioClientes == NULL) {
        /* Se a lista esta vazia, o novo no se torna o primeiro. */
        *inicioClientes = novo;
    } else {
        /* Caso contrario, percorre ate o ultimo no. */
        atual = *inicioClientes;

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }

    printf("Cliente cadastrado com sucesso.\n");

    snprintf(registro, TAM_HISTORICO,
             "Cadastro de cliente - codigo %d", codigo);
    empilharHistorico(topo, registro);
}

/* Percorre e mostra todos os nos da lista de clientes. */
void listarClientes(Cliente *inicioClientes) {
    Cliente *atual = inicioClientes;

    if (inicioClientes == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("\n========== CLIENTES CADASTRADOS ==========\n");

    while (atual != NULL) {
        printf("\nCodigo: %d\n", atual->codigo);
        printf("Dados: %s\n", atual->dados);

        if (atual->codigoLivroEmprestado == -1) {
            printf("Livro emprestado: nenhum\n");
        } else {
            printf("Livro emprestado: %d\n",
                   atual->codigoLivroEmprestado);
        }

        if (atual->codigoLivroNaFila == -1) {
            printf("Fila de espera: nenhuma\n");
        } else {
            printf("Aguardando livro: %d\n", atual->codigoLivroNaFila);
        }

        atual = atual->prox;
    }
}

/* -------------------- LISTA ENCADEADA DE LIVROS -------------------- */

/* Busca um livro percorrendo os nos da lista. */
Livro *buscarLivro(Livro *inicioLivros, int codigo) {
    Livro *atual = inicioLivros;

    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

/* Cria dinamicamente um livro e o insere no final da lista. */
void cadastrarLivro(Livro **inicioLivros, Historico **topo) {
    Livro *novo;
    Livro *atual;
    char registro[TAM_HISTORICO];
    int codigo;
    int estoque;

    codigo = lerInteiro("Codigo do livro (maior que zero): ");

    if (codigo <= 0) {
        printf("O codigo deve ser maior que zero.\n");
        return;
    }

    if (buscarLivro(*inicioLivros, codigo) != NULL) {
        printf("Ja existe um livro com esse codigo.\n");
        return;
    }

    estoque = lerInteiro("Quantidade inicial em estoque: ");

    if (estoque < 0) {
        printf("O estoque nao pode ser negativo.\n");
        return;
    }

    novo = (Livro *) malloc(sizeof(Livro));

    if (novo == NULL) {
        printf("Erro: nao foi possivel reservar memoria.\n");
        return;
    }

    novo->codigo = codigo;
    novo->estoque = estoque;
    lerTexto("Descricao (titulo, autor, ano, categoria): ",
             novo->descricao, TAM_TEXTO);

    inicializarFila(&novo->espera);
    novo->prox = NULL;

    if (*inicioLivros == NULL) {
        *inicioLivros = novo;
    } else {
        atual = *inicioLivros;

        while (atual->prox != NULL) {
            atual = atual->prox;
        }

        atual->prox = novo;
    }

    printf("Livro cadastrado com sucesso.\n");

    snprintf(registro, TAM_HISTORICO,
             "Cadastro de livro - codigo %d", codigo);
    empilharHistorico(topo, registro);
}

/* Percorre e mostra todos os livros cadastrados. */
void listarLivros(Livro *inicioLivros) {
    Livro *atual = inicioLivros;

    if (inicioLivros == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\n========== LIVROS CADASTRADOS ==========\n");

    while (atual != NULL) {
        printf("\nCodigo: %d\n", atual->codigo);
        printf("Descricao: %s\n", atual->descricao);
        printf("Exemplares disponiveis: %d\n", atual->estoque);
        printf("Clientes na fila: %d\n", atual->espera.quantidade);

        atual = atual->prox;
    }
}

/* -------------------- FILA DE ESPERA (FIFO) -------------------- */

/* Prepara uma fila vazia para um livro novo. */
void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int filaVazia(Fila *fila) {
    return fila->quantidade == 0;
}

int filaCheia(Fila *fila) {
    return fila->quantidade == MAX_FILA;
}

/* Verifica se o cliente ja esta aguardando este livro. */
int clienteNaFila(Fila *fila, int codigoCliente) {
    int i;

    for (i = fila->inicio; i < fila->fim; i++) {
        if (fila->codigos[i] == codigoCliente) {
            return 1;
        }
    }

    return 0;
}

/* Insere o codigo no FINAL da fila. */
int inserirFila(Fila *fila, int codigoCliente) {
    if (filaCheia(fila)) {
        return 0;
    }

    fila->codigos[fila->fim] = codigoCliente;
    fila->fim++;
    fila->quantidade++;

    return 1;
}

/* Retira o codigo do INICIO e desloca os demais para a esquerda. */
int removerFila(Fila *fila, int *codigoCliente) {
    int i;

    if (filaVazia(fila)) {
        return 0;
    }

    *codigoCliente = fila->codigos[fila->inicio];

    for (i = 0; i < fila->quantidade - 1; i++) {
        fila->codigos[i] = fila->codigos[i + 1];
    }

    fila->quantidade--;
    fila->inicio = 0;
    fila->fim = fila->quantidade;

    return 1;
}

/* Mostra os clientes da fila na ordem em que solicitaram a reserva. */
void consultarFila(Livro *livro, Cliente *inicioClientes) {
    int i;
    Cliente *clienteEncontrado;

    if (filaVazia(&livro->espera)) {
        printf("Nao ha clientes aguardando este livro.\n");
        return;
    }

    printf("\nFila de espera do livro %d:\n", livro->codigo);

    for (i = livro->espera.inicio; i < livro->espera.fim; i++) {
        clienteEncontrado = buscarCliente(inicioClientes,
                                          livro->espera.codigos[i]);

        if (clienteEncontrado != NULL) {
            printf("%d - %s (codigo %d)\n",
                   i + 1,
                   clienteEncontrado->dados,
                   clienteEncontrado->codigo);
        }
    }
}

/* -------------------- EMPRESTIMOS E DEVOLUCOES -------------------- */

/* Empresta um exemplar se houver estoque e o cliente estiver livre. */
void realizarEmprestimo(Livro *inicioLivros, Cliente *inicioClientes,
                        Historico **topo) {
    int codigoLivro;
    int codigoCliente;
    int resposta;
    Livro *livro;
    Cliente *cliente;
    char registro[TAM_HISTORICO];

    codigoLivro = lerInteiro("Codigo do livro: ");
    codigoCliente = lerInteiro("Codigo do cliente: ");

    livro = buscarLivro(inicioLivros, codigoLivro);
    cliente = buscarCliente(inicioClientes, codigoCliente);

    if (livro == NULL) {
        printf("Livro nao encontrado.\n");
        return;
    }

    if (cliente == NULL) {
        printf("Cliente nao encontrado. Cadastre-o primeiro.\n");
        return;
    }

    if (cliente->codigoLivroEmprestado != -1) {
        printf("Este cliente ja possui um livro emprestado.\n");
        return;
    }

    if (cliente->codigoLivroNaFila != -1) {
        printf("Este cliente ja esta aguardando outro livro.\n");
        return;
    }

    if (livro->estoque > 0) {
        livro->estoque--;
        cliente->codigoLivroEmprestado = livro->codigo;

        printf("Emprestimo realizado com sucesso.\n");
        printf("Estoque disponivel: %d\n", livro->estoque);

        snprintf(registro, TAM_HISTORICO,
                 "Emprestimo - cliente %d - livro %d",
                 codigoCliente, codigoLivro);
        empilharHistorico(topo, registro);
    } else {
        printf("Este livro esta sem exemplares disponiveis.\n");
        resposta = lerInteiro("Deseja entrar na fila? (1 - Sim / 0 - Nao): ");

        if (resposta == 1) {
            if (filaCheia(&livro->espera)) {
                printf("A fila deste livro esta cheia.\n");
                return;
            }

            if (clienteNaFila(&livro->espera, codigoCliente)) {
                printf("Este cliente ja esta na fila deste livro.\n");
                return;
            }

            if (inserirFila(&livro->espera, codigoCliente)) {
                cliente->codigoLivroNaFila = codigoLivro;
                printf("Reserva registrada no final da fila.\n");
                printf("Posicao na fila: %d\n",
                       livro->espera.quantidade);

                /* Registrar reservas no historico como extensao. */
                snprintf(registro, TAM_HISTORICO,
                         "Reserva - cliente %d - livro %d",
                         codigoCliente, codigoLivro);
                empilharHistorico(topo, registro);
            }
        } else if (resposta == 0) {
            printf("Solicitacao cancelada.\n");
        } else {
            printf("Opcao de resposta invalida.\n");
        }
    }
}

/* Devolve o livro e, se houver fila, destina o exemplar ao primeiro. */
void realizarDevolucao(Livro *inicioLivros, Cliente *inicioClientes,
                       Historico **topo) {
    int codigoCliente;
    int codigoLivro;
    int codigoProximo;
    Cliente *cliente;
    Cliente *proximoCliente;
    Livro *livro;
    char registro[TAM_HISTORICO];

    codigoCliente = lerInteiro("Codigo do cliente que esta devolvendo: ");
    cliente = buscarCliente(inicioClientes, codigoCliente);

    if (cliente == NULL) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    if (cliente->codigoLivroEmprestado == -1) {
        printf("Este cliente nao possui livro emprestado.\n");
        return;
    }

    codigoLivro = cliente->codigoLivroEmprestado;
    livro = buscarLivro(inicioLivros, codigoLivro);

    if (livro == NULL) {
        printf("Livro relacionado ao emprestimo nao foi encontrado.\n");
        return;
    }

    /* Primeiro, encerra o emprestimo do cliente atual. */
    cliente->codigoLivroEmprestado = -1;

    printf("Devolucao registrada para o livro %d.\n", codigoLivro);

    /* Se existe fila, o exemplar e destinado ao primeiro da fila. */
    if (removerFila(&livro->espera, &codigoProximo)) {
        proximoCliente = buscarCliente(inicioClientes, codigoProximo);

        if (proximoCliente != NULL &&
            proximoCliente->codigoLivroEmprestado == -1) {
            proximoCliente->codigoLivroNaFila = -1;
            proximoCliente->codigoLivroEmprestado = livro->codigo;

            printf("Proximo cliente atendido: %s (codigo %d).\n",
                   proximoCliente->dados, proximoCliente->codigo);
            printf("O exemplar foi destinado a esse cliente.\n");
        } else {
            /* Situacao de seguranca para nao perder o exemplar. */
            if (proximoCliente != NULL) {
                proximoCliente->codigoLivroNaFila = -1;
            }

            livro->estoque++;
            printf("Nao foi possivel destinar o exemplar ao proximo cliente.\n");
            printf("O exemplar voltou para o estoque.\n");
        }
    } else {
        livro->estoque++;
        printf("Nao havia fila. O exemplar voltou para o estoque.\n");
    }

    printf("Estoque disponivel: %d\n", livro->estoque);

    snprintf(registro, TAM_HISTORICO,
             "Devolucao - cliente %d - livro %d",
             codigoCliente, codigoLivro);
    empilharHistorico(topo, registro);
}

/* Lista todos os clientes que possuem livros emprestados. */
void consultarEmprestimos(Cliente *inicioClientes) {
    Cliente *atual = inicioClientes;
    int encontrou = 0;

    while (atual != NULL) {
        if (atual->codigoLivroEmprestado != -1) {
            printf("Cliente: %s | Codigo: %d | Livro: %d\n",
                   atual->dados,
                   atual->codigo,
                   atual->codigoLivroEmprestado);
            encontrou = 1;
        }

        atual = atual->prox;
    }

    if (!encontrou) {
        printf("Nao existem emprestimos ativos.\n");
    }
}

/* -------------------- PILHA DE HISTORICO (LIFO) -------------------- */

/* Insere uma nova operacao no TOPO da pilha. */
void empilharHistorico(Historico **topo, const char operacao[]) {
    Historico *novo = (Historico *) malloc(sizeof(Historico));

    if (novo == NULL) {
        printf("Aviso: nao foi possivel guardar esta operacao no historico.\n");
        return;
    }

    strcpy(novo->operacao, operacao);

    /* O novo no aponta para o antigo topo e passa a ser o novo topo. */
    novo->prox = *topo;
    *topo = novo;
}

/* Percorre a pilha do topo para baixo: mais recente primeiro. */
void mostrarHistorico(Historico *topo) {
    Historico *atual = topo;
    int numero = 1;

    if (topo == NULL) {
        printf("O historico esta vazio.\n");
        return;
    }

    printf("\n========== HISTORICO DE OPERACOES ==========\n");

    while (atual != NULL) {
        printf("%d - %s\n", numero, atual->operacao);
        atual = atual->prox;
        numero++;
    }
}

/* -------------------- LIBERACAO DE MEMORIA -------------------- */

/* Libera todos os nos da lista de clientes. */
void liberarClientes(Cliente *inicioClientes) {
    Cliente *atual = inicioClientes;
    Cliente *auxiliar;

    while (atual != NULL) {
        auxiliar = atual;
        atual = atual->prox;
        free(auxiliar);
    }
}

/* Libera todos os nos da lista de livros. */
void liberarLivros(Livro *inicioLivros) {
    Livro *atual = inicioLivros;
    Livro *auxiliar;

    while (atual != NULL) {
        auxiliar = atual;
        atual = atual->prox;
        free(auxiliar);
    }
}

/* Libera todos os nos da pilha de historico. */
void liberarHistorico(Historico *topo) {
    Historico *atual = topo;
    Historico *auxiliar;

    while (atual != NULL) {
        auxiliar = atual;
        atual = atual->prox;
        free(auxiliar);
    }
}
