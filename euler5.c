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

int main() {
	int i;
	int prime_count = 10;
    int product = 1;
	int a[prime_count]; 
	euler_sieve(prime_count, a);
	for ( i = 2; i < prime_count; i++) {
		if (a[i] == 1) {
            int fact = i;
            while (fact * i < prime_count) {
                fact = fact * i;
            }
            product = product * fact;
        }
    }
    printf("The smallest number with 1 to %d as factors is %d\n", prime_count, product);
}
            
