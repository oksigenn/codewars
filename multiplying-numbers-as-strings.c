#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*https://www.codewars.com/kata/55911ef14065454c75000062
4 kyu
*/

    char *multiply(char *a, char *b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);
    int resultLen = len1 + len2;
    int *result = (int *)calloc(resultLen, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int product = (a[i] - '0') * (b[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    char *res = (char *)malloc((resultLen + 1) * sizeof(char));
    int index = 0;

    for (int i = 0; i < resultLen; i++)
    {
        if (index == 0 && result[i] == 0)
        {
            continue;
        }
        res[index++] = result[i] + '0';
    }

    res[index] = '\0';

    if (index == 0)
    {
        res[0] = '0';
        res[1] = '\0';
    }

    free(result);
    return res;
}

int main()
{
    char a[] = "123";
    char b[] = "456";
    char *result = multiply(a, b);

    printf("%s\n", result);

    free(result);

    return 0;
}
