#include <stdlib.h>
#include <string.h>

char *dna_strand(const char *dna)
{
    int length = strlen(dna);
    char *string = malloc(length + 1);

    for (int i = 0; i < length; i++)
    {
        switch (dna[i])
        {
        case 'T':
            string[i] = 'A';
            break;
        case 'G':
            string[i] = 'C';
            break;
        case 'A':
            string[i] = 'T';
            break;
        case 'C':
            string[i] = 'G';
            break;
        }
    }
    string[length] = '\0';
    return string;
}