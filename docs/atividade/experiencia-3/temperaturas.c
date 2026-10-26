#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIAS 31

/* Le uma linha inteira, evitando aproveitar sobras de entradas longas. */
static int ler_linha(char *linha, size_t tamanho)
{
    if (fgets(linha, (int)tamanho, stdin) == NULL) {
        return 0;
    }
    if (strchr(linha, '\n') == NULL && !feof(stdin)) {
        int caractere;
        while ((caractere = getchar()) != '\n' && caractere != EOF) {
        }
        linha[0] = '\0';
    }
    return 1;
}

static int terminou_numero(const char *fim)
{
    while (isspace((unsigned char)*fim)) {
        fim++;
    }
    return *fim == '\0';
}

int main(void)
{
    float temperaturas[MAX_DIAS];
    char linha[128];
    char *fim;
    int dias;

    puts("TEMPERATURAS MAXIMAS DO MES");
    /* O mes determina quantas posicoes do vetor serao utilizadas. */
    for (;;) {
        printf("Quantidade de dias do mes (28 a 31): ");
        if (!ler_linha(linha, sizeof linha)) {
            fputs("\nEntrada encerrada. Analise cancelada.\n", stderr);
            return 1;
        }
        errno = 0;
        long valor = strtol(linha, &fim, 10);
        if (fim != linha && terminou_numero(fim) && errno == 0 &&
            valor >= 28 && valor <= MAX_DIAS) {
            dias = (int)valor;
            break;
        }
        puts("Entrada invalida: informe um inteiro entre 28 e 31.");
    }

    /* Cada indice representa um dia; a mensagem usa indice + 1. */
    for (int dia = 0; dia < dias; dia++) {
        for (;;) {
            printf("Maxima do dia %d em C (use ponto decimal): ", dia + 1);
            if (!ler_linha(linha, sizeof linha)) {
                fputs("\nEntrada encerrada. Analise cancelada.\n", stderr);
                return 1;
            }
            errno = 0;
            float valor = strtof(linha, &fim);
            if (fim != linha && terminou_numero(fim) && errno == 0 &&
                isfinite(valor)) {
                temperaturas[dia] = valor;
                break;
            }
            puts("Entrada invalida: informe uma temperatura numerica finita.");
        }
    }

    /* A referencia inicial vem dos dados, permitindo valores negativos. */
    float maior = temperaturas[0];
    float menor = temperaturas[0];
    int dia_maior = 0;
    int dia_menor = 0;
    double soma = 0.0;
    for (int dia = 0; dia < dias; dia++) {
        soma += temperaturas[dia];
        /* Comparacoes estritas preservam o primeiro dia em empates. */
        if (temperaturas[dia] > maior) {
            maior = temperaturas[dia];
            dia_maior = dia;
        }
        if (temperaturas[dia] < menor) {
            menor = temperaturas[dia];
            dia_menor = dia;
        }
    }

    puts("\nDIA | MAXIMA (C)");
    puts("----+-----------");
    for (int dia = 0; dia < dias; dia++) {
        printf("%3d | %10.2f\n", dia + 1, temperaturas[dia]);
    }
    printf("\nMedia das maximas: %.2f C\n", soma / dias);
    printf("Maior maxima: %.2f C (dia %d)\n", maior, dia_maior + 1);
    printf("Menor maxima: %.2f C (dia %d)\n", menor, dia_menor + 1);
    return 0;
}
