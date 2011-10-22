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

int smarter_factor(long long num) {
	long long f, last_f;
	last_f = 1;
	//check 2 as a factor
	//this lets us increment by 2 in the next section
	if (num % 2 == 0) {
		last_f = 2;
		while (num % 2 == 0) {
			num = num / 2;
		}
	}
	f = 3;
	//since the largest prime factor of a number is <= sqrt(num)
	//we only want to loop while our factor is less than that
	long long max_f = (long long)sqrt(num);
	while (num > 1 && f <= max_f) {
		if (num % f == 0) {
			last_f = f;
			printf("Smart Factor found %lld\n",f);
			while (num % f == 0) {
				num = num / f;
			}
			//update our max factor
			max_f = (long long)sqrt(num);
		}
		f+=2;
	}
	if (num == 1)	return last_f;
	return num;
}


int main() {
	int i;
	long long f = 600851475143;
	double d = 600851475143;
	printf("Smart Factor: %d\n",smarter_factor(f));
	double square = sqrt(d);
	int prime_count = (long long)square;
	int a[prime_count]; 
	euler_sieve(prime_count, a);
	for ( i = 2; i < prime_count; i++) {
		if (a[i] == 1) {
			if (f % i == 0) {
				printf("Prime Factor: %d\n", i);
				f = f / i;
			}
		}
		if (i > f) {
			printf("Largest factor found, skipping out at %d\n", i);
			break;
		}
	}
}
