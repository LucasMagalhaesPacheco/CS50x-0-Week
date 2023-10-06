#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2)
    {
        printf("Player 1 wins!");

    } else if (score1 < score2)
    {
       printf("Player 2 wins!");
    } else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int pontuacao = 0;
    //Este for faz com que o código passe por todas as palavras antes de finalizar;
    // Por isso word[i]
    for(int i = 0; word[i]; i++)
    {
        char character = toupper(word[i]);
        //If em questão mostra que se o character for maior ou igual a A maisculo, ou Menos ou igual Z minusculo é para entrar
        if(character >= 'A' && character <= 'Z') {
           // Aqui vamos percorrer as letras, temos que salientar que cada letra é um Número na Tabela ASCLI
           // Sendo assim o código vai fazer seguinte ele vai adicionar o número da pontuação baseado nos Points acima,
           // E como ele vai saber isso? Cada letra tem um indice.
           // no código utilizamos o character - "A", para descobri no array dos Points, aonde aquela letra fica
           // Vemos no exemplo abaixo
           pontuacao += POINTS[character - 'A'];
           //resumidamente seria:
           //Se letra for 'A', então 'A' - 'A' resulta em 0, o que significa que estamos olhando para a primeira letra do alfabeto ('A').
           //Se letra for 'B', então 'B' - 'A' resulta em 1, o que significa que estamos olhando para a segunda letra do alfabeto ('B').
           //Se letra for 'C', então 'C' - 'A' resulta em 2, indicando a terceira letra do alfabeto ('C').
        }
    }

    return pontuacao;
}
