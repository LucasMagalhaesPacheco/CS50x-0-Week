int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Describe your text: ");
    int letters = count_letters(s);
    int words = count_words(s);
    int sentences = count_sentences(s);

    float L = (letters * 100.0) / (float) words;
    float S = (sentences * 100.0) / (float) words;

   

    float Coleman = 0.05888 * L - 0.296 * S - 15.8;

    int result = round(Coleman);

    if (result >= 1 && result <= 16)
    {
        printf("Grade %i\n", result);
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; text[i]; i++)
    {
        // Para contar todas as letras de uma frase, precisamos descartar seus espaços, pontos e virgulas, já que são caracteres
        // especiais
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 0;
    // definimos uma variável para saber quando estamos dentro da palavra em questão, não queremos contar characteres unicamente
    // Queremos então contar a quantidade de frases então utilizamos isso.
    int insideWord = false;

    for (int i = 0; text[i]; i++)
    {

        // Inicialmente definimos se o caracter em questão é uma letra do alfabeto
        // A função vai voltar true se for um caracter então transforma o insideWord ou seja
        //Dentro da palavra em Verdadeiro
        if (isalpha(text[i]))
        {
            insideWord = true;
        }
        // Aqui vemos se estamos dentro de uma palavra com insideWord
        // Se estivermos ele vai passar e verificar se o último caracter encontra um espaço
        //Se ele encontrou, adicionamos +1 no numero de palavras
        // Então colocamos no final disso está dentro da palavra como false
        // Afinal estamos saindo dela.
        else if (text[i] == ' ' && insideWord)
        {
            words++;
            insideWord = false;
        }
    }

    // Aqui fora do For vamos analisar se estamos ainda dentro de uma frase, se estivermos vai contar;
    // Normalmente pq a última frase não tem espaço no final após o ponto
    if (insideWord)
    {
        words++;
    }

    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i]; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
