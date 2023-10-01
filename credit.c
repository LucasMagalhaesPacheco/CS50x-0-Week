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

    // Aqui faremos a verificação dos digitos do cartão, a multiplicação dos digitos Impares também
    //Para isso fazemos um While que enquanto a condição do Numero do cartão for maior que zero
    // Sendo que ele vai passar por todos os números em cada rodada do Loop até não sobra nenhum.
    //Isso vem pelo fato do NumeroDoCartao dividido por 10

    while(numeroDoCartao > 0)
    {
      // O Digito do cartão seria o resto da sua divisão por 10, então pegaria sempre o último digito
     digito =  numeroDoCartao % 10;

     //aqui para tiramos o último digito do cartão utilizamos o seguinte ideia o numeroDoCartão divido por 10, se um exemplo prático
     // se o número fosse 1234 nessa divisão ele viraria 123, tirando o último digito
     numeroDoCartao /= 10;

     // Aqui faremos o seguinte, para o cálculo de um cartão de crédito ser funcional,
     //Precisamos multiplicar todos os números impáres do código para isso utilizamos o comprimento
     // Aqui fazemos uma verificação simples de Par e Impar, todo número Impar acaba com 0
     if(comprimento % 2 == 1)
     {
        digito *= 2; //aqui temos o digito do cartão 2, o digito que pegamos no resto da divisão

        // Aqui então entramos em um segundo If dentro do If, esse If é que para o calculo do cartão de crédito funcionar
        //O número não pode ser maior que 9, afinal tem digitos de 1 a 9, então utilizamos a lógica
        // Que se o número for maior que 9 ele diminui 9, então vamos supor que o digito é 12 ele se torna 3.
        if(digito > 9) {
            digito -= 9;
        }

        }
        //Primeiramente essa linha ela serve para somar os digitos que são calculados depois de todos esses processos feitos acima
        //Para assim termos certeza que é dá o digito correto, ou seja no final possa dá um digito terminado em zero ou não.
        soma +=  digito;
        //Já aqui no comprimento vemos diretamente em que número em questão o código está.
        // Se está no primeiro digito, segundo digito, etc.
        comprimento++;

    }

    // Aqui fazemos a verificação, se o resto da divisão não for igual a 0, ou seja um número exato o cartão de crédito não é válido
    //Para um cartão de crédito ser válido o valor total das suas somas, depois de todo nosso algoritmo
    // Seja pós a multiplicação dos números Impares, subtração dos números impares maiores que 9
    // É que essa soma de digitos se torne um número divisível por 10
    // Então se o resto da divisão por 10 for diferente que 0, o cartão é inválido.

    if (soma % 10 == 0)
    {


      // Nessa lógica utilizamos o While repetidas vezes, para ele sempre ir cortando os números até sobrar 1
      // Por isso a lógica se aplica até o número ser menor que 10 e é executado, enquanto for maior ou igual a 10.
      // Como vemos utilizamos o número do cartão original, então precisamos daquela variável lá em cima que ajude nisso.
     while (primeiroDigito >= 10)
    {
        primeiroDigito /= 10;
    }

    // Aqui fazemos uma lógica para encontrar o primeiro e o segundo digito do cartão
    // Aqui é a mesma lógica do While Anterior, porém ele encontra o primeiro e segundo digito
    //Por isso é maior ou igual a 100.
    // Se notar precisamos do número original, então a variável lá em cima que adicionamos é colocada
    while(primeiroSegundoDigito >= 100)
    {
        primeiroSegundoDigito /= 10;
    }

    // Aqui fazemos um contador para sabermos quantos números tem o cartão em questão
    int contador = 0;

    // Aqui fazemos uma verificação para contar os digitos do cartão no contador, então se o cartão tem 13 digitos
    // Ou 16 digitos ele vai mostrar aqui
    //Se notarmos precisamos do número original do cartão sem nenhum loop
    // Por isso é utilizado a variável lá em cima.
    while(numeroDoCartaoContador != 0)
    {
     numeroDoCartaoContador /= 10;
     contador++;
    }
    // Aqui fazemos finalmente as últimas verificações de cada bandeira dos cartões

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
        printf("INVALID\n"); // Neste caso é caso o cartão seja válido mas não encaixe em nenhuma bandeira
    }

    } else
    {
        printf("INVALID\n"); // E neste último caso é se o cartão não é valido.
    }


}