#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    //Declaração das variáveis que serão utilizadas neste projeto.
    char estado;
    char codigoCidade[3];
    char nomeCidade[50];
    int populacao, pontosTuristicos;
    float pib, area;

    printf("Digite a letra que representa o estado:\n");
    scanf("%c", &estado);
    printf("Digite agora o código da cidade(por exemplo, A01, A02, B01, B02)\n");
    scanf("%s", &codigoCidade);
    printf("Digite a população dessa cidade:\n");
    scanf("%i", &populacao);
    printf("Digite a área dessa cidade:\n");
    scanf("%f", area);
    printf("Digite os pontos turísticos dessa cidade:\n");
    scanf("%i", &pontosTuristicos);
    printf("Digite o PIB dessa cidade:\n");
    scanf("%f", pib);

    printf("Estado: %c\nCódigo da carta: %s\nNome da cidade: %s\nPopulação: %i\nÁrea: %f\nPIB: %f\nNúmero de pontos turísticos: %i\n", estado, codigoCidade, nomeCidade, populacao, area, pib, pontosTuristicos);
    return 0;
}
