#include <stdio.h>
#include <math.h>

int *euler_sieve(long long input, int *a, int search) {
	int i;
	int j;
    int count = 0;
	for(i = 0; i < input; i++) {
		a[i] = 1;
	}
	for(i = 2; i < input; i++) {
		if (a[i] == 1) {
            count++;
            if (count == search) {
                printf("The %d prime number is %d\n", search, i);
            }
			for (j = 2; j <= input / i; j++) {
				a[i*j] = 0;
			}
		}
	}
    printf("Found %d primes\n", count);
	return a;
}

/*Notes:
 * 1 is not prime
 * 2 is the only even prime
 * all primes > 3 can be written as 6k +/- 1
 * any n can only have one primefactor great than sqrt(n)
 * so if we cannot find a number less than sqrt(n) then n is 
 * prime because the only primefactor of n would be n itself
 */
int is_prime(int n) {
    if (n==1) return 0;
    else if (n < 4) return 1;
    else if (n % 2 == 0) return 0;
    else if (n < 9) return 0;
    else if (n % 3 == 0) return 0;
    else {
        int r = floor(sqrt(n));
        int f = 5;
        while (f <= r) {
            if (n % f == 0) return 0;
            if (n % (f + 2) == 0) return 0;
            f = f + 6;
        }
    }
    return 1;
}

int main() {
    //searchSize choosen purely on a good guess
	int searchSize = 150000;
	int a[searchSize]; 
	euler_sieve(searchSize, a,10001);
    //below is the trial division method - the above works really well
    //but the search size needs to be known first

    int limit = 10001;
    limit--;
    int candidate = 1;
    while(limit) {
        candidate += 2;
        if (is_prime(candidate)) {
            limit--;
        }
    }
    printf("The 10001 prime number is %d\n", candidate);
    
}
