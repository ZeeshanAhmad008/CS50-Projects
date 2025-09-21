
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("enter number: ");
    }
    while(h <1 || h>8);

    for(int i = 0; i < h; i++)
    {

        for(int j=(h-1);j>i;j--)
        {
            printf(" ");
        }
        for(int k=0;k<=i;k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

