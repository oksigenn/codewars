#include <stdio.h>
#include <stdlib.h>

/*https://www.codewars.com/kata/5672682212c8ecf83e000050
4 kyu
*/

int min(int a, int b) {
    return a < b ? a : b;
}

int dblLinear(int n) {
    int *u = (int *)malloc((n + 1) * sizeof(int));

    u[0] = 1;
    
    int *Q2 = (int *)malloc((n + 1) * sizeof(int));
    int *Q3 = (int *)malloc((n + 1) * sizeof(int));

    Q2[0] = 3;
    Q3[0] = 4;

    int q2_index = 0, q3_index = 0;
    int q2_size = 1, q3_size = 1;

    for (int i = 1; i <= n; i++) {
        int next_val = min(Q2[q2_index], Q3[q3_index]);
        u[i] = next_val;

        if (next_val == Q2[q2_index]) {
            q2_index++;
        }
        if (next_val == Q3[q3_index]) {
            q3_index++;
        }

        Q2[q2_size++] = 2 * next_val + 1;
        Q3[q3_size++] = 3 * next_val + 1;
    }

    free(u);
    free(Q2);
    free(Q3);

    return u[n];
}
