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

        //Definimos uma variável para ter os bits corretos dentro do array ou seja um array de 8;
        int bits[BITS_IN_BYTE];


        //Temos que lembrar que o indice sempre é zero
        // Então se queremos uma Matriz do numero exato fazemos o valor menos ele, pois o indice 0 conta
        // Então se queremos uma matriz de 8 fazemos j menos 8
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            // O Bloco de código em questão vai se repetir 8 vezes
            // Aqui é a conta nos sempre queremos o resto da divisão por 2
            // Pois nela só é possível dois resultados, 1 ou 0, pois ela normalmente representa Bar e Impar[
            // E isso combina bastante com binários pois precisamos de 0 e 1.
            bits[j] = decimal % 2;
            // Aqui depois para acharmos o segundo digito fazemos isso dividindo o número por 2 repetidas vezes
            // Até que chegue no total de 8 digitos
            decimal /= 2;
        }

        //Aqui a lógica é semelhante que a anterior, aqui queremos imprimir da forma certo os números binários
        //Começamos da maneira inversa, fazemos que o 8 - 1 que da 7 digitos, o que é 8 digitos se contarmos do 0.
        // Então utilizamos nossa variável com numero 8 mesno 1 para percorremos todos os digitos
        //Definindo L como ela e fazemos o L repetir o loop se for igual ou menor que 0
        // Já que o último digito que queremos é o 0
        for(int l = BITS_IN_BYTE - 1; l >= 0; l--)
        {
            // Aqui por fim imprimos digitos, dos bits que fizemos no loop anterior com a variável 0.
           print_bulb(bits[l]);
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

