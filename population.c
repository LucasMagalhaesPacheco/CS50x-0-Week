#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start; // Inicialmente começamos com começo de nossa civilização
    int end; // Aqui sua quantidade nos momentos finais
    int years = 0; // Aqui quantos anos levam para civilização chegar no final
    int gain; // Seu ganho de pessoas por ano
    int lose; // Sua perda de pessoas por ano
    
    do {
        start = get_int("Start Population: ");
    } while (start < 9); // Nenhuma população pode começar com menos de 9 pessoas

    // TODO: Prompt for end size
    do
    {
        end = get_int("End Population: ");
    }
    while (end < start); // O final não pode ser maior que o começo

    // TODO: Calculate number of years until we reach threshold

    while (start < end)
    {
        int result = 0;
        gain = start / 3; // calculo de ganho
        lose = start / 4; // calculo de perda
        result = gain - lose;
        start = start + result; // Soma dos fatores
        years++; // Quantidade de anos do começo chegar no final
    }

   printf("Years: %i\n", years);
}