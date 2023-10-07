#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);


int main(void)
{
    string sentence;
    // Aqui pedimos uma mensagem ao usuário

     sentence = get_string("Digite sua mensagem por gentileza: ");
     //Aqui fazemos um loop simples, utilizando a variável como N para encontrar

     for (int i = 0, n = strlen(sentence); i < n; i++)
     {
        // Convertemos então utilizando a tabela ASCII o código em um número.
        int decimal = sentence[i];

        // O For em questão vai fazer a seguinte configuração, se o numeros for menos que Bits em um Byte, ele vai continuar no loop
        //O que isso quer dizer que se o número for menor que 8 ele vai continuar, por sua vez
        // Como queremos exatos 8 digitos, podemos fazer assim pois a contagem do for começa com 0.

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
        // aqui fazemos a conta do código binário para converter o número em código binário, o bit é o resto da divisão do decimal
        // divido por 2, depois em seguida fazer o decimal divido por 2 repetidas vezes, até seu numero ser igual a 8.
        int bit = decimal % 2;
        decimal /= 2;
        // Bit é basicamente o digito do local em questão, para vermos quais luzes vai ligar no painel, é o número do indice em questão
        print_bulb(bit);
        }
        //Aqui é só pra pular a linha quando mudar o caracter da setença
        printf("\n");

     }


}

void print_bulb(int bit)
{
    // Aqui como um código binário tem 0 ou um 1, zero para imprimir as cores pretas, 1 para imprimir as coisas amarela!
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

