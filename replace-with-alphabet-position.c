#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/*https://www.codewars.com/kata/546f922b54af40e1e90001da
6 kyu
*/

char weight(char s)
{
    int weight = tolower(s) - 96;
    return weight;
}

char *alphabet_position(const char *text)
{
    char *result = malloc(strlen(text) * sizeof(char));
    if (isalpha(text[0]))
    {
        sprintf(result, "%d", weight(text[0]));
    }

    for (size_t i = 1; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            sprintf(result, "%s %d", result, weight(text[i]));
        }
    }

    return result;
}