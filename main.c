#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} Carta;

void calcularIndicadores(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

float getValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return -1;
    }
}

int main() {
    Carta carta1 = {"Brasil", 211000000, 8515767.0, 7300000000000.0, 27};
    Carta carta2 = {"Japao", 126000000, 377975.0, 4900000000000.0, 20};

    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    int escolha1, escolha2;
    float valor1_C1, valor2_C1, valor1_C2, valor2_C2;
    float soma1, soma2;

    printf("Bem-vindo ao Super Trunfo: Batalha Final!\n\n");

    // Menu do primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    printf("1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Demografica\n6. PIB per Capita\n");
    printf("Digite o numero do atributo: ");
    scanf("%d", &escolha1);

    // Menu do segundo atributo
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1. Populacao\n"); break;
                case 2: printf("2. Area\n"); break;
                case 3: printf("3. PIB\n"); break;
                case 4: printf("4. Pontos Turisticos\n"); break;
                case 5: printf("5. Densidade Demografica\n"); break;
                case 6: printf("6. PIB per Capita\n"); break;
            }
        }
    }
    printf("Digite o numero do segundo atributo: ");
    scanf("%d", &escolha2);

    // Coleta os valores para cada carta
    valor1_C1 = getValorAtributo(carta1, escolha1);
    valor2_C1 = getValorAtributo(carta1, escolha2);
    valor1_C2 = getValorAtributo(carta2, escolha1);
    valor2_C2 = getValorAtributo(carta2, escolha2);

    // Impressão dos valores
    printf("\nComparacao entre %s e %s\n", carta1.nome, carta2.nome);
    printf("Atributo %d: %s = %.2f | %s = %.2f => Vencedora: %s\n", escolha1,
        carta1.nome, valor1_C1, carta2.nome, valor1_C2,
        (escolha1 == 5) ? (valor1_C1 < valor1_C2 ? carta1.nome : carta2.nome)
                        : (valor1_C1 > valor1_C2 ? carta1.nome : carta2.nome));

    printf("Atributo %d: %s = %.2f | %s = %.2f => Vencedora: %s\n", escolha2,
        carta1.nome, valor2_C1, carta2.nome, valor2_C2,
        (escolha2 == 5) ? (valor2_C1 < valor2_C2 ? carta1.nome : carta2.nome)
                        : (valor2_C1 > valor2_C2 ? carta1.nome : carta2.nome));

    // Soma e vencedor final
    soma1 = valor1_C1 + valor2_C1;
    soma2 = valor1_C2 + valor2_C2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    if (soma1 == soma2)
        printf("\nResultado final: Empate!\n");
    else
        printf("\nResultado final: %s venceu!\n", soma1 > soma2 ? carta1.nome : carta2.nome);

    return 0;
}
