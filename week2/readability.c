#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text){
    int letters = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isalpha(text[i])) //verifica se o caractere é uma letra
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text){
    int spaces = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == ' ') //procura um espaço para encontrar o fim de uma palavra
        {
            spaces++;
        }
    }
    return spaces + 1; //somar um para contar a ultima palavra
}

int count_sentences(string text){
    int sentences = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')// final da sentença
        {
            sentences++;
        }
    }
     return sentences;
}

int main(void){

    string text = get_string("Text: ");

    int n_letters = count_letters(text);
    int n_words = count_words(text);
    int n_sentences = count_sentences(text);

    float L = (float) n_letters / n_words * 100;
    float S = (float) n_sentences / n_words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int level = round(index); //round arredonda float e double(#include <math.h>)

    if(level < 1){
        printf("Before Grade 1\n");
    }
    else if(level >= 1 && level <= 15){
        printf("Grade %i\n", level);
    }
    else{
        printf("Grade 16+\n");
    }
}
