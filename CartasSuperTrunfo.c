#include <stdio.h> // Para entrada e saída de dados (printf, scanf)
#include <string.h> // Para manipulação de strings (strcspn)

// Estrutura para representar uma carta
typedef struct {
    char estado[3]; // Ex: "MG"
    int codigo;
    char nome[50];
    unsigned long int populacao; // unsigned long int para população
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder; // Novo atributo para o Super Poder
} Carta;

// Função para ler os dados de uma carta
void lerDadosCarta(Carta *carta, int numero_carta) {
    printf("\n--- Entrada de Dados para a Carta %d ---\n", numero_carta);
    printf("Estado (2 letras, ex: MG): ");
    scanf("%s", carta->estado);
    printf("Codigo: ");
    scanf("%d", &carta->codigo);
    printf("Nome: ");
    getchar(); // Consumir o newline pendente após o scanf do código
    fgets(carta->nome, sizeof(carta->nome), stdin); // Ler nome com espaços
    // Remover o newline (\n) que fgets pode adicionar
    carta->nome[strcspn(carta->nome, "\n")] = 0; // strcspn encontra o primeiro \n
    printf("Populacao: ");
    scanf("%lu", &carta->populacao); // %lu para unsigned long int
    printf("Area (em km2): ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para calcular Densidade Populacional e PIB per Capita
void calcularAtributosDerivados(Carta *carta) {
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0.0; // Evita divisão por zero
    }

    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0.0; // Evita divisão por zero
    }
}

// Função para calcular o Super Poder
void calcularSuperPoder(Carta *carta) {
    // Atenção na conversão de tipos!
    // A população é unsigned long int, então a convertemos para float.
    // O inverso da densidade populacional precisa ser tratado para evitar divisão por zero.
    float inverso_densidade = 0.0;
    if (carta->densidade_populacional > 0) {
        inverso_densidade = 1.0 / carta->densidade_populacional;
    }

    carta->super_poder = (float)carta->populacao + carta->area + carta->pib +
                          (float)carta->pontos_turisticos + carta->pib_per_capita +
                          inverso_densidade;
}

int main() {
    Carta carta1, carta2;

    // 1. Inserir dados das duas cartas
    lerDadosCarta(&carta1, 1);
    lerDadosCarta(&carta2, 2);

    // 2. Calcular Densidade Populacional e PIB per Capita para ambas
    calcularAtributosDerivados(&carta1);
    calcularAtributosDerivados(&carta2);

    // 3. Calcular o Super Poder para ambas
    calcularSuperPoder(&carta1);
    calcularSuperPoder(&carta2);

    // 4. Exibir os resultados das comparações
    printf("\n--- Comparacao de Cartas ---\n");

    // Comparação da População (maior valor vence)
    printf("Populacao: Carta %d venceu (%d)\n",
           (carta1.populacao > carta2.populacao) ? 1 : 2,
           (carta1.populacao > carta2.populacao) ? 1 : 0);

    // Comparação da Área (maior valor vence)
    printf("Area: Carta %d venceu (%d)\n",
           (carta1.area > carta2.area) ? 1 : 2,
           (carta1.area > carta2.area) ? 1 : 0);

    // Comparação do PIB (maior valor vence)
    printf("PIB: Carta %d venceu (%d)\n",
           (carta1.pib > carta2.pib) ? 1 : 2,
           (carta1.pib > carta2.pib) ? 1 : 0);

    // Comparação dos Pontos Turisticos (maior valor vence)
    printf("Pontos Turisticos: Carta %d venceu (%d)\n",
           (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 2,
           (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : 0);

    // Comparação da Densidade Populacional (menor valor vence)
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 2,
           (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : 0);

    // Comparação do PIB per Capita (maior valor vence)
    printf("PIB per Capita: Carta %d venceu (%d)\n",
           (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 2,
           (carta1.pib_per_capita > carta2.pib_per_capita) ? 1 : 0);

    // Comparação do Super Poder (maior valor vence)
    printf("Super Poder: Carta %d venceu (%d)\n",
           (carta1.super_poder > carta2.super_poder) ? 1 : 2,
           (carta1.super_poder > carta2.super_poder) ? 1 : 0);

    return 0;
}
