#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n < 1 || n > 8);

    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < n; j++) {

            if(j >= n - 1 - i) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        //Pegando a ideia do Código anterior aqui queremos fazer uma escada do outro lado para se completarem 
         // Aqui é o espaço entre as escadas, se tu notar ele está dentro do loop maior.
        printf("  ");

        // Aqui como é uma escada no canto esquerdo, ele tem que no começo criar a # e depois ele tem que colocar os espaços em branco,
        // No segundo processo ele faz o mesmo mas adiciona duas Hashtags pois em duas interações apenas o i que começa com 0 e agora é um chega no número
        //E assim sucessivamente, mas este sempre acaba quando chega no 0, afinal é um número inteiro não negativo.
         
        for(int l = n; l > 0; l--){
            if(n - l <= i) {
                printf("#");
            } else {
                printf(" ");
            }
        }

        printf("\n");

    }


}