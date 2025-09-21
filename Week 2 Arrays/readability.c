
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");

    int L = 0; // Letters
    int S = 0; // Sentences
    int W = 1; // Words start at 1

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            W++;
        }
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            S++;
        }
        else if (isalpha(text[i]))
        {
            L++;
        }
    }

    float L_avg = ((float) L / W) * 100;
    float S_avg = ((float) S / W) * 100;

    int index = round(0.0588 * L_avg - 0.296 * S_avg - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

