#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*https://www.codewars.com/kata/55983863da40caa2c900004e
4 kyu
*/

int* create_array(long long num, int* size){
    int rank = 0;
    long long tmp = num;
    while (tmp>0)
    {
        rank++;
        tmp/=10;
    }
    *size = rank;
    int* array = malloc(rank  * sizeof(int));

    for (int i = rank - 1; i >= 0; i--)
    {
        array[i] = num % 10;
        num /= 10;
    }
    
    return array;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sort_subarray(int* digits, int start, int size) {
    qsort(digits + start, size - start, sizeof(int), compare);
}

long long join_array(int* array, int size){
    long long result = 0;
    int rank = 1;
    for (int i = 0; i < size; i++)
    {
        result = array[i] + result * 10;
        rank *= 10;
    }

    return result;
}

long long next_bigger_number(long long n) {
    int size;
    int* digits = create_array(n, &size);

    int i = size - 2;

    while (i>=0 && digits[i] >= digits[i+1])
    {
        i--;
    }

    if (i == -1)
    {
        free(digits);
        return -1;
    }

    int j = size - 1;

    while (digits[j] <= digits[i])
    {
        j--;
    }
    int tmp = digits[i];
    digits[i] = digits[j];
    digits[j] = tmp;

    sort_subarray(digits, i + 1, size);

    long long result = join_array(digits, size);
    free(digits);
    
    
    return result;
    }