#include <stdio.h>
#include <string.h>

#define MAX 20
#define TAM_NOME 60

// Matriz que armazena ate 20 nomes de usuarios.
char fila[MAX][TAM_NOME];

// Indices e quantidade de usuarios na fila circular.
int inicio = 0;
int fim = 0;
int quantidade = 0;

int fila_vazia() {
    return quantidade == 0;
}

int fila_cheia() {
    return quantidade == MAX;
}

// Adiciona o nome na proxima posicao disponivel.
void enfileirar(char nome[]) {
    if (fila_cheia()) {
        printf("Fila cheia! Nao e possivel adicionar usuarios.\n");
        return;
    }

    if (nome[0] == '\0') {
        printf("Nome invalido.\n");
        return;
    }

    strcpy(fila[fim], nome);
    fim = (fim + 1) % MAX;
    quantidade++;
    printf("%s entrou na fila!\n", nome);
}

// Atende sempre o usuario que entrou primeiro (FIFO).
void desenfileirar() {
    if (fila_vazia()) {
        printf("Fila vazia! Nao ha usuarios para atender.\n");
        return;
    }

    printf("Usuario atendido: %s\n", fila[inicio]);
    inicio = (inicio + 1) % MAX;
    quantidade--;
}

// Consulta o primeiro sem remove-lo.
void consultar_primeiro() {
    if (fila_vazia()) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Proximo usuario: %s\n", fila[inicio]);
}

// Mostra os nomes na ordem correta, mesmo apos o vetor circular voltar ao inicio.
void mostrar_fila() {
    if (fila_vazia()) {
        printf("A fila esta vazia.\n");
        return;
    }

    printf("\n===== FILA DE ESPERA =====\n");
    for (int i = 0; i < quantidade; i++) {
        int posicao = (inicio + i) % MAX;
        printf("%d - %s\n", i + 1, fila[posicao]);
    }
    printf("=========================\n");
}

void mostrar_quantidade() {
    printf("Usuarios na fila: %d de %d\n", quantidade, MAX);
}

// Descarta caracteres que sobraram na entrada, evitando problemas no menu.
void limpar_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main() {
    int opcao;
    char nome[TAM_NOME];

    do {
        printf("\n===== TICKETQUEUE =====\n");
        printf("1 - Entrar na fila\n");
        printf("2 - Atender proximo usuario\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Mostrar quantidade de usuarios\n");
        printf("5 - Consultar proximo usuario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida.\n");
            limpar_entrada();
            opcao = -1;
            continue;
        }
        limpar_entrada();

        switch (opcao) {
            case 1:
                if (fila_cheia()) {
                    printf("Fila cheia!\n");
                    break;
                }

                printf("Digite o nome do usuario: ");
                if (fgets(nome, sizeof(nome), stdin) == NULL) {
                    printf("Entrada encerrada.\n");
                    return 0;
                }
                if (strchr(nome, '\n') == NULL) {
                    limpar_entrada();
                }
                nome[strcspn(nome, "\n")] = '\0';
                enfileirar(nome);
                break;

            case 2:
                desenfileirar();
                break;
            case 3:
                mostrar_fila();
                break;
            case 4:
                mostrar_quantidade();
                break;
            case 5:
                consultar_primeiro();
                break;
            case 0:
                printf("Encerrando TicketQueue...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}