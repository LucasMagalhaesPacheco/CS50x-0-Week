#include <cs50.h>
#include <stdio.h>


//Inicialmente imaginamos que o código leia de cima para baixo,
//Implementamos as funções nomeadas aqui.
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // aqui pegamos o valor total gasto
    int cents = get_cents();

    // Aqui fazemos as conta do troco com quarters que seria 25 centavos.
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Aqui é o valor dos cents com dimes que seria a moeda de 10 centavos
    // A multiplicação é para igualar o troco bem
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Aqui a mesma coisa, mas agora com as moedas de 5 centavos
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // E aqui com as moedas de um centavo
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Somamos todas as moedas, para ver o total do troco
    int coins = quarters + dimes + nickels + pennies;

    // Imprimos o troco
    printf("%i\n", coins);
}

int get_cents(void)
{
    // função que pede ao cliente o valor pago
    int cents;
    do
    {
        cents = get_int("Valor:  ");
    }
    while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{   
    // aqui calculamos o troco em cents em quarters
    int quarters;
    quarters = cents / 25;

    return quarters;
}

int calculate_dimes(int cents)
{
    // aqui calculamos o troco em dimes
    int dimes;
    dimes = cents / 10;

    return dimes;
}

int calculate_nickels(int cents)
{
  // aqui calculamos o troco em nickels
    int nickels;
    nickels = cents / 5;

    return nickels;
}

int calculate_pennies(int cents)
{
    // como o valor já esta em cents, não precisa calcular em pennies, então só retornamos.
    
    return cents;
}
