#include <stdio.h>
#include <math.h>

//use the close form expression of fibonacci to directly compute
//ideally we would make some of these variables const so we do not
//have to precompute everytime
int fib(int x) {
    double n = (double)x;
    double gr = (1 + sqrt(5)) / 2;
    return (int)((pow(gr, n) - pow((1-gr),n)) / sqrt(5));

}

main() {
    int loop = 1;
    long int sum = 0;
    int i = 3;
    while (loop) {
        long int f = fib(i);
        if (f > 4000000) { loop = 0; }
        else {
            sum = sum + f;
        }
        i += 3;
    }
    printf("The sum of all even Fibonacci numbers below 4,000,000 is: %d\n", sum);
}
