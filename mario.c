#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

// Aqui fazemos o loop a respeito da pergunta sempre retornando a ela, quando o resultado não é desejado ele retorna a pergunta
    do
    {
         n = get_int("Size: ");
    }
    while(n < 1 || n > 8);
// A lógica é a seguinte o primeiro dos Loops criamos as colunas.
    for(int i = 0; i < n; i++)
    {
// O Loop dentro do loop criaria então as colunas que o código teria, em vez de só as linhas.
        for(int j = 0; j < n; j++)
        {

       // Esse If, faria inicialmente o seguinte, enquanto J for maior que o numero de N - 1 - o número de I
        // Que graças ao loop anterior vai aumentando constantemente, em um exemplo prático:
        // Primeiro Loop meu valor de N é 5
        // Ele fará J = 0
        // N = 5
        // 1 = 1
        // I = 0
        // Ele vai fazer a verificação se nessa conta J é maior que N
        // Na primeira não vai ser, então espaço vazio
        // Na segunda não vai ser, então espaço vazio
        // Na terceira não vai ser, então espaço vazio
        // Na quarta ele vai se manter nisso até igualar, porém a única forma de Igualar é sobrando apenas um # na primeira linha
        // Se o código estivesse > n na primeira linha seria tudo coberto por espaços vazios.
        //Na segunda linha vai cobrindo tudo com espaços vazios, até só sobrar dois e assim sucessivamente.
            if(j >= n - 1 - i) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        // Aqui quebra a linnha
        printf("\n");



    }


}