#include <stdio.h>

int SumDivisibleBy(int n) {
    int p = 999 / n;
    return n * (p * (p + 1)) / 2;
}

main() {
    int i = 1;
    int m3 = 0;
    int m5 = 0;
    int sum = 0;
    int loop = 1;
    while(loop) {
        m3= i * 3;
        loop = 0;
        if (m3 < 1000) {
            if (m3 % 5) sum = sum + m3;
            loop = 1;
        }
        m5= i * 5;
        if (m5 < 1000) {
            sum = sum + m5;
            loop = 1;
        }
        printf("i: %d, 3: %d, 5: %d, sum: %d\n",i,m3,m5,sum);
        i++;
    }
    printf("The answer is: %d\n",sum);
    printf("3: %d, 5: %d, 15:  %d\n", SumDivisibleBy(3), SumDivisibleBy(5), SumDivisibleBy(15));
    printf("The answer is: %d\n", SumDivisibleBy(3) + SumDivisibleBy(5) - SumDivisibleBy(15));
}



