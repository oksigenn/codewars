#include <stdio.h>

/*https://www.codewars.com/kata/51e04f6b544cf3f6550000c1
5 kyu
*/

int beeramid(double bonus, double price)
{
    int n = 1;
    int levels = 0;

    if (bonus < price)
    {
        return 0;
    }

    while (bonus >= price * n * n)
    {
        bonus -= n * n * price;
        levels++;
        n++;
    }

    return levels;
}
