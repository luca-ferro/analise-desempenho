#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniforme() {
    double u = rand() / ((double) RAND_MAX + 1);
    // limitando entre (0,1]
    u = 1.0 - u;

    return (u);
}

int main() {
    // Na exponencial, o valor de E[X] = 1/l
    // E[X] = 5
    // 1/l = 5
    // l = 1/5
    // l = 0.2
    double l;
    printf("Informe o tempo médio (em segundos): ");
    scanf("%lF", &l);
    l = 1.0/l;

    // Variáveis para cálculo da média final
    double soma = 0.0;
    double qtd_valores_gerados = 1000000;

    // Iniciando a semente para a geração dos 
    // números pseudo-aleatórios
    int semente = time(NULL);
    // int semente = 10
    srand(semente);

    int i;
    for (i = 0; i < qtd_valores_gerados; i++){
        double valor = (-1.0/l) * log(uniforme());
        // printf("%lF\n", valor);
        // getchar();
        soma += valor;
    }

    printf("Média: %lF\n", (soma/qtd_valores_gerados));

    return 0;
}