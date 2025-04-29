#include <stdio.h>
#include <locale.h>

// Card structure
typedef struct {
    char state;
    unsigned short int code;
    unsigned long int population;
    unsigned int touristAttractions;
    float area;
    float gdp;
    float popDensity;
    float gdpPerCapita;
    float super;
} card;

//Simplifies the presentation of each card created
void showCard(card c[], int i){
    printf("----------------------\n");
    printf("Você inseriu os seguintes dados para a carta %c%d\n",
        c[i].state, c[i].code);
    printf("População: %lu\n", c[i].population);
    printf("Area: %.2f\n", c[i].area);
    printf("PIB: %.2f\n", c[i].gdp);
    printf("Atrações turísticas: %u\n", c[i].touristAttractions);
    printf("Densidade populacional: %.2f\n", c[i].popDensity);
    printf("PIB per capita: %.2f\n", c[i].gdpPerCapita);
    printf("Super: %.2f\n", c[i].super);
    printf("----------------------\n");
}

//Compares each card attribute and stores pontuation in an array named points
void compareCards (card c[], int points[]) {
    points[0] = (c[0].population > c[1].population);
    points[1] = (c[0].touristAttractions > c[1].touristAttractions);
    points[2] = (c[0].area > c[1].area);
    points[3] = (c[0].gdp > c[1].gdp);
    points[4] = (c[0].popDensity < c[1].popDensity);
    points[5] = (c[0].gdpPerCapita > c[1].gdpPerCapita);
    points[6] = (c[0].super > c[1].super);
}

int main() {
    
    setlocale(LC_ALL, "Portuguese");

    card gameCard[2] = {0};
    int points[7];
    
    for (int i=0; i < 2; i++) {
        gameCard[i].state = 'A';
        gameCard[i].code = i + 1;
        
        printf("Insira os dados da carta %c%u\n",
            gameCard[i].state, gameCard[i].code);
        
            printf("população: ");
        scanf("%lu", &gameCard[i].population);
        
        printf("Area: ");
        scanf("%f", &gameCard[i].area);
        
        printf("PIB: ");
        scanf("%f", &gameCard[i].gdp);
        
        printf("Atrações turísticas: ");
        scanf("%u", &gameCard[i].touristAttractions);
        printf("\n");

        // Population Density calculus
        gameCard[i].popDensity = (float)gameCard[i].population /
        gameCard[i].area;

        //GDP Per Capita calculus   
        gameCard[i].gdpPerCapita = gameCard[i].gdp /
            (float)gameCard[i].population;

        // Super calculus
        gameCard[i].super = 1/gameCard[i].popDensity +
            gameCard[i].population +
            gameCard[i].area +
            gameCard[i].gdp +
            gameCard[i].touristAttractions +
            gameCard[i].gdpPerCapita;
            
        showCard(gameCard, i);
    }

    //Call function to compare cards
    compareCards(gameCard, points);

    //Show the comparison results
    char* atributos[] = {
        "População", "Atrações Turísticas", "Área", "PIB",
        "Densidade Populacional", "PIB per Capita", "Super"
    };
    
    for (int i = 0; i < 7; i++) {
        printf("%s: Carta %d venceu\n", atributos[i], points[i] ? 1 : 2);
    }
    
    return 0;
}
