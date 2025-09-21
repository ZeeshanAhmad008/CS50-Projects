#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
do {

 n = get_int("enter a number: ");
}
while(n<0);
 int coin=0;
 coin+=n/25;
 n%=25;
  coin+=n/10;
 n%=10;
  coin+=n/5;
 n%=5;

coin+=n;
printf("coins needed: %d\n", coin);
};

