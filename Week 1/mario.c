#include <cs50.h>
#include <stdio.h>

void print_row(int brick);

int main(void)
{
    // take height
    int height;
    do{
       height = get_int("What's the height? " );
    }
    while(height <= 0);

    //make pyramid
    for(int i = 1; i <= height; i++)
    {
        for(int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        print_row(i);
        printf("\n");
    }
 }
void print_row(int brick)
{
    //make more columns
    for(int i = 0; i < brick; i++)
    {
        printf("#");
    }
}
