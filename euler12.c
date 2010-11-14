#include <stdio.h>
#include <math.h>

int *euler_sieve(long long input, int *a) {
	int i;
	int j;
	for(i = 0; i < input; i++) {
		a[i] = 1;
	}
	for(i = 2; i < input; i++) {
		if (a[i] == 1) {
			for (j = 2; j <= input / i; j++) {
				a[i*j] = 0;
			}
		}
	}
	return a;
}

int get_prime_factorization(unsigned long f, int *primes) {
    int facts[500];
    int powers[500];
    int i;
    int factorIdx = 0;
    int org = f;

    for (i = 0; i < 500; i++) {
        facts[i] = -1;
        powers[i] = -1;
    }
	for ( i = 2; i < 1000; i++) {
		if (primes[i] == 1) {
			if (f % i == 0) {
				f = f / i;
                facts[factorIdx] = i;
                powers[factorIdx] = 1;
                while (f % i == 0 && f != 0 && f != i) {
                    f = f / i;
                    powers[factorIdx]++;
                }
                factorIdx++;
			}
		}
		if (i > f) {
			break;
		}
	}
    //add 2 for 1 and the number itself
    int fc = 1;
    for (i = 0; i < 500; i++) {
        if (powers[i] == -1) {
            break;
        }
        //printf("Prime Factor: %d Power %d\n", facts[i], powers[i]);
        fc = fc * (powers[i] + 1);
    }
    return fc;
}
/*
 * 1: 1
 * 3: 1,3
 * 6: 1,2,3,6
 * 10: 1,2,5,10
 * 15: 1,3,5,15
 * 21: 1,3,7,21
 * 28: 1,2,4,7,14,28
 */
int main() {
    int size = 1000;
	int a[size]; 
	euler_sieve(size, a);
    int j = 0;
    int fact =0;
    int fact2 =0;
    int n, n1;
    for (j = 1; j < 50000; j ++) {
        if (j % 2) {
            n = j;
            n1 = (j + 1) / 2;
        }
        else {
            n = j / 2;
            n1 = j + 1;
        }
        fact = get_prime_factorization(n, a);
        fact2 = get_prime_factorization(n1, a);
        if (fact * fact2 >= 500) {
            break;
        }
    }
    printf("%d has %d factors\n",j, fact * fact2);
}
