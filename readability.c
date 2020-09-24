#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string input = get_string("Text: ");

    int all[3] = {0, 0, 0};
    all[0] = count_letters(input);
    all[1] = count_words(input);
    all[2] = count_sentences(input);

    double L = ((double) all[0] * 100) / (double) all[1]; //(all[0] / all[1]) * 100;
    double S = ((double) all[2] * 100) / (double) all[1]; //(all[2] / all[1]) * 100;

    double index = (0.0588 * L) - (0.296 * S) - 15.8;
    //Grade Number
    int i = (int)round(index);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}

int count_letters(string s)
{
    int letters = 0;//letters, words, sentences
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char ltr = s[i];
        //count letters
        if (isalpha(ltr)) //if i is alphabetic upper/lower
        {
            letters++;
        }

    }

    //ref: https://man.cs50.io/
    return letters;
}

int count_words(string s)
{
    int words = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char ltr = s[i];
        //count words
        if (ltr == ' ')
        {
            words++;
        }
    }
    //add one to account for last word which will not contain a space at the end
    return words + 1;
}

int count_sentences(string s)
{
    int sentences = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        char ltr = s[i];
        //count sentences
        if (ltr == '.' || ltr == '!' || ltr == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
