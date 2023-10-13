#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to cipher a character using the Caesar cipher
char cipherCesar(char c, int key) {
      // aqui na função que está dentro daquele loop recebemos os caracteres de i
    // Então vamos retornar as mensagens, sendo assim:
    if (isalpha(c)) { // verificamos se é uma letra do alfabeto

        char base = isupper(c) ? 'A' : 'a'; // verificamos se é maiúsculo ou minúsculo, sendo ? e : algo como if e else. Se caso for maiúsculo ele vai transformar a base em 'A', se minúsculo vai transformar a base em 'a'.
       // Aqui, c é o caractere principal que queremos modificar
       // Quando subtraímos pela base, fazemos assim: vamos pegar a letra 'D' - 'A', ele vai mostrar que é o número 3, pois o 'D' é 3 letras depois do 'A'
       // Se sua Key for 3, ele vai fazer 3 + 3, então chegando na sexta letra do alfabeto
       // Depois fazemos o resto da divisão por 26% para não sair dos 26 dígitos
       // Por fim, utilizamos + a base para retornar o 1 que tiramos anteriormente.
        return (c - base + key) % 26 + base;
    }
    return c; // retornamos o caracter
}

int main(int argc, string argv[]) {
     // Se a pessoa não digitou nenhum dígito para começar sua cifra, mandamos para ele de volta o código com erro
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

   // aqui transformamos o primeiro argumento em uma chave;
    string key = argv[1];
     // Aqui iremos verificar se o dígito comentado é um número inteiro que não seja negativo
    // Para assim a cifra funcionar
    for (int i = 0; i < strlen(key); i++) {
        if (!isdigit(key[i])) {
            printf("Usage: ./caesar key\n");
            return 1; // Aqui é para retornar o erro pro usuário
        }
    }

     // Aqui utilizamos a função Atoi,
    // Usamos principalmente utilizando na tabela ASCII para encontrarmos dígitos
    // Como recebemos realmente um dígito, utilizamos ela para assim só converter a string de maneira correta
    int k = atoi(key);

     // Agora eu peço ao usuário a mensagem a ser criptografada
    string plaintext = get_string("plaintext: ");

    // Aqui colocamos a mensagem antes do loop só para organizar
    printf("ciphertext: ");


    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        char ciphered_char = cipherCesar(plaintext[i], k);
        printf("%c", ciphered_char);
    }

    printf("\n");

    return 0;
}