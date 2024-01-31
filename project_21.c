// FALTA ENCONTRAR O BUG NA FORMULA DO CALCULO DA SERIE

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade_level(int count_letters, int count_sentences, int count_words);
void print_grade();

int main(void)
{
// solicitar um texto ao usuário através de get_string
    string text = get_string ("Text: ");

    int num_of_letters = count_letters (text);// contar letras do texto - assumaindo que pode ser minúscula ou maiúscula
    int num_of_words = count_words (text);// contar palavras do texto - qualquer caractere separado por um espaço deve ser contado como uma palavra
    int num_of_sentences = count_sentences(text);// ocorrência de ponto final, ponto de exclamação ou ponto de interrogação indica o fim de uma frase.
    int level = grade_level (num_of_letters, num_of_words, num_of_sentences);

    print_grade (grade_level);//imprimir como output "Grade X - X corresponde a série calculada pela fórmula de Coleman-Liau

}
int count_letters (string text)
{
    int num_of_letters = 0;
    for (int i = 0; i < strlen (text); i++ )
    {
        if (isalpha(text[i]))
        {
            num_of_letters += 1;
        }
    }
    return num_of_letters;
}

int count_words (string text)
{
    int num_of_words = 0;
    for (int i = 0; i < strlen (text); i++ )
    {
        if (text[i] == ' ')
        {
            num_of_words += 1;
        }
    }
    return num_of_words + 1;
}

int count_sentences (string text)
{
    int num_of_sentences = 0;
    for (int i = 0; i < strlen (text); i++ )
    {
        if (text[i] == '!' || text [i] == '?' || text [i] == '.')
        {
            num_of_sentences += 1;
        }

    }
    return num_of_sentences;
}

int grade_level(int count_letters, int count_sentences, int count_words)
{
    float S = (count_letters / (float) count_words) * 100;
    float L = (count_sentences / (float) count_words) * 100;

    return round (0.0588 * L * 0.296 * S - 15.8);
}

void print_grade (int grade_level)
{
    if (grade_level <= 1)
    {
        printf ("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf ("Grade 16+\n");
    }
    else
    {
        printf ("Grade %i\n", grade_level);
    }

}
