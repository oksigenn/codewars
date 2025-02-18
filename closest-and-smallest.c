#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*https://www.codewars.com/kata/5868b2de442e3fb2bb000119/
5 kyu
*/

int weight(int num) {
    int weight = 0;
    while (num > 0) {
        weight += num % 10;
        num /= 10;
    }
    return weight;
}

char *closest(const char *strng) {
    if (strlen(strng) == 0) {
        return strdup("{{0,0,0},{0,0,0}}");
    }
    
    int numbers[100], weights[100], indices[100];
    int count = 0;
    
    const char *ptr = strng;
    while (*ptr) {
        while (*ptr == ' ') ptr++;
        if (!*ptr) break;
        numbers[count] = strtol(ptr, (char**)&ptr, 10);
        weights[count] = weight(numbers[count]);
        indices[count] = count;
        count++;
    }
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (weights[j] > weights[j + 1] || (weights[j] == weights[j + 1] && indices[j] > indices[j + 1])) {
                int tmp;
                
                tmp = weights[j]; weights[j] = weights[j + 1]; weights[j + 1] = tmp;
                tmp = numbers[j]; numbers[j] = numbers[j + 1]; numbers[j + 1] = tmp;
                tmp = indices[j]; indices[j] = indices[j + 1]; indices[j + 1] = tmp;
            }
        }
    }
    
    int min_diff = INT_MAX;
    int best_i = 0, best_j = 1;
    for (int i = 1; i < count; i++) {
        int diff = weights[i] - weights[i - 1];
        if (diff < min_diff) {
            min_diff = diff;
            best_i = i - 1;
            best_j = i;
        }
    }
    
    char *result = malloc(50);
    sprintf(result, "{{%d, %d, %d}, {%d, %d, %d}}", 
            weights[best_i], indices[best_i], numbers[best_i],
            weights[best_j], indices[best_j], numbers[best_j]);
    
    return result;
}
