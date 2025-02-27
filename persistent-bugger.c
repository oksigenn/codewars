#include <stdio.h>

/*https://www.codewars.com/kata/55bf01e5a717a0d57e0000ec
6 kyu
*/

int weight(int i)
{
    int weight = 1;

    int rank = 10;

    while (i > 0)
    {
        weight *= i % rank;
        i /= 10;
    }

    return weight;
}

int persistence(int n){
    int count = 0;
    
    while (n > 9)
    {
        n = weight(n);
        count++;
    }
    
    return count;
}