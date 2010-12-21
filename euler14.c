#include <stdio.h>
#include <math.h>


int main() {
    int max = 0;
    int maxNum = 1000000;
    int i;

    for (i = 1000000; i > 0; i--) {
        if (i % 10000 == 0) {
            printf("*");
        }
        long unsigned int num = i;
        int count = 1;
        while (num > 1) {
            while (num % 2 == 0) {
                num = num >> 1;
                count++;
            }
            if (num != 1) {
                num = num * 3 + 1;
                count++;
            }
        }
        if (count > max) {
            max = count;
            maxNum = i;
        }
//    printf("Chain produced by %d for %d iterations\n", i ,count);
    }
    printf("\nMax chain produced by %d for %d iterations\n", maxNum ,max);
}
