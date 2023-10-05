#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Creditamos a variável do cartão de crédito
    long numeroDoCartao;
    do
    {
       numeroDoCartao = get_long("Digite o número do cartão de crédito: ");
    }
    while (numeroDoCartao <= 0);
    //Aqui criaremos uma variável reserva pro número do cartao que será útil no segundo loop do contador
    long numeroDoCartaoContador = numeroDoCartao;
    //Aqui criamos uma segunda variável com valor numero do cartão que será necessário para encontrar o primeiro digito
    long primeiroDigito = numeroDoCartao;
    //Aqui criamos uma terceira variável com valor do numero do cartão que será necessário para encontrar
    // o primeiro e o segundo digito
    long primeiroSegundoDigito = numeroDoCartao;

    int soma = 0;
    int comprimento = 0;
    int digito;

    while(numeroDoCartao > 0)
    {
      
     digito =  numeroDoCartao % 10;

    
     numeroDoCartao /= 10;

     
     if(comprimento % 2 == 1)
     {
        digito *= 2; 
        if(digito > 9) {
            digito -= 9;
        }

        }
        
        soma +=  digito;

        comprimento++;

    }

    if (soma % 10 == 0)
    {

     while (primeiroDigito >= 10)
    {
        primeiroDigito /= 10;
    }

    while(primeiroSegundoDigito >= 100)
    {
        primeiroSegundoDigito /= 10;
    }

    
    int contador = 0;

   
    while(numeroDoCartaoContador != 0)
    {
     numeroDoCartaoContador /= 10;
     contador++;
    }
    

    if((contador  == 13 || contador == 16) && (primeiroDigito == 4))
    {
      printf("VISA\n");
    } else if(contador == 15 && (primeiroSegundoDigito == 34 || primeiroSegundoDigito == 37) )
    {
        printf("AMEX\n");
    } else if(contador == 16 &&(primeiroSegundoDigito >= 51 && primeiroSegundoDigito < 56  ))
    {
        printf("MASTERCARD\n");
    } else
    {
        printf("INVALID\n"); 
    }

    } else
    {
        printf("INVALID\n"); 
    }


}