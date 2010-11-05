#include <stdio.h>
#include <math.h>

void euler_sieve(int input, int *a) {
	int i;
	int j;
    int count = 0;
	for(i = 0; i <= input; i++) {
		a[i] = 1;
	}
	for(i = 2; i <= input; i++) {
		if (a[i] == 1) {
            count++;
			for (j = 2; j <= input / i + 1; j++) {
                if (i * j <= input) a[i*j] = 0;
			}
		}
	}
    printf("Found %d primes below %d\n", count, input);
}

int main() {
    int limit = 2000000;
    int primes[2000000];
    euler_sieve(limit, primes);
    int i = 0;
    double sum = 0;
    for (i = 2; i < 2000000; i++) {
        if (primes[i] == 1) {
            sum += i;
        }
    }
    printf("The sum of all primes below 2000000 is %f\n", sum);
}

