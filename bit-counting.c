#include <stdlib.h>
#include <stdio.h>
/*https://www.codewars.com/kata/526571aae218b8ee490006f4
6 kyu
*/
size_t countBits(unsigned value)
{
    int ans = 0;
    int res = 0, pv = 1;
    int count = 0;

    while (value > 0)
    {
        res = value % 2;
        res == 1 ? count++ : count;
        ans = ans + res * pv;
        pv *= 10;
        value /= 2;
    }
    return count;
}
