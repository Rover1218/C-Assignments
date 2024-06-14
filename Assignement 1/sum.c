#include <stdio.h>
int main()
{
    int i, sum = 0;
    for (i = 0; i < 10; i++)
    {
        sum += i;
    }
    printf("sum of 10 natural numbers is %d", sum);
    return 0;
}

/* WHILE LOOP
    int i=0, sum=0;
    while(i<10)
    {
        sum +=i;
        i++;
    }
    printf("sum of 10 natural numbers is %d", sum);  */

/* DO WHILE LOOP
     int i=0, sum=0;
   do
   {
       sum+=i;
       i++;
   }
    while(i<10);
    printf("sum of 10 natural numbers is %d", sum);
*/