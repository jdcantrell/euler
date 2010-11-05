#include <stdio.h>
#include <math.h>

main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i < 999; i++) {
        for (j = 1; j < (999 - i); j++) {
            if (i + j + sqrt(i*i + j*j) == 1000) {
                printf("a: %d, b: %d, c: %f\n", i, j, sqrt(i*i + j*j));
            }
        }
    }
}
