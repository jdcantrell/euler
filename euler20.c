#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "big_int.h"

#define FACT 100

int main(int argc, char *argv[]) {
    int num = FACT;
    if (argc == 2) {
        num = atoi(argv[1]);
    }

    //actual problem 16 code
    big_int ans = bi_init("1");
    big_int* inc = malloc(sizeof(big_int));
    *inc = bi_init("1");
    int i;
    for(i = 1; i <= num; i++) {
        bi_set_int(inc, i);
        ans =  bi_mult(ans, *inc);
    }
    printf("%d! = %s\n", num, bi_get(ans));
    int sum = 0;
    for(i = 1; i <= DIGITS; i++) {
        if (ans.number[i] == EON) {
            break;
        }
        sum += ans.number[i];
    }
    printf("Sum of digits: %d\n", sum);
}
