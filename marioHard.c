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

        
       // Aqui a lógica é mais simples pois, a escada necessariamente começa da esquerda, então não precisa calcular os espaços primeiro
       //Então o L começa como 0 se L for menor i + 1; i++, inicialmente na primeira linha o L vai ser 0 e o i vai ser 1 
       // Então ele vai imprimi #
       //Já na segunda execução, o L vai ser 1 que vai ser igual ao I
       // Então ele pula para próxima linha, assim sucessivamente, e como começa da esquerda não precisa calcular espaço
       
       for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        }

        printf("\n");

    }


}