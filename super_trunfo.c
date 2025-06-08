#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

float calcular_densidade(unsigned long int populacao, float area) {
    return populacao / area;
}

float calcular_pib_per_capita(float pib, unsigned long int populacao) {
    return pib / populacao;
}

float calcular_super_poder(Carta c) {
    float densidade = c.densidade_populacional;
    float inverso_densidade = (densidade != 0) ? 1.0 / densidade : 0;

    return (float)c.populacao + c.area + c.pib + (float)c.pontos_turisticos +
           c.pib_per_capita + inverso_densidade;
}

void ler_carta(Carta *carta) {
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Código: ");
    scanf("%d", &carta->codigo);

    printf("Nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("População: ");
    scanf("%lu", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    carta->densidade_populacional = calcular_densidade(carta->populacao, carta->area);
    carta->pib_per_capita = calcular_pib_per_capita(carta->pib, carta->populacao);
    carta->super_poder = calcular_super_poder(*carta);
}

int comparar_maior(float a, float b) {
    return a > b ? 1 : 0;
}

int comparar_menor(float a, float b) {
    return a < b ? 1 : 0;
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    ler_carta(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    ler_carta(&carta2);

    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", comparar_maior((float)carta1.populacao, (float)carta2.populacao));
    printf("Área: Carta 1 venceu (%d)\n", comparar_maior(carta1.area, carta2.area));
    printf("PIB: Carta 1 venceu (%d)\n", comparar_maior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", comparar_maior((float)carta1.pontos_turisticos, (float)carta2.pontos_turisticos));
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", comparar_menor(carta1.densidade_populacional, carta2.densidade_populacional));
    printf("PIB per Capita: Carta 1 venceu (%d)\n", comparar_maior(carta1.pib_per_capita, carta2.pib_per_capita));
    printf("Super Poder: Carta 1 venceu (%d)\n", comparar_maior(carta1.super_poder, carta2.super_poder));

    return 0;
}
