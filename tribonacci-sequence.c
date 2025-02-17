#include <stdlib.h>
/*https://www.codewars.com/kata/556deca17c58da83c00002db/
6 kyu
*/

long long *tribonacci(long long signature[3], int n)
{
    if (n == 0)
    {
        return NULL;
    }

    long long *array = (long long *)malloc(n * sizeof(long long));

    array[0] = signature[0];
    array[1] = signature[1];
    array[2] = signature[2];

    for (size_t i = 3; i < n; i++)
    {
        array[i] = array[i - 2] + array[i - 1] + array[i - 3];
    }

    return array;
}