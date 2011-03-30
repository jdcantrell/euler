#include <stdio.h>
#include <math.h>

//super simple factor routine
int factor_sum(int num) {
	int i;
	int limit = sqrt(num);
	int sum = 0;
	for (i = 1; i <= limit; i++) {
		if (num % i == 0) {
			sum += (i + (num / i));
		}
	}
	//remove the number from the sum since we added when
	//i = 1; a number is not a factor with itself
	return sum - num;
}

int main(int argc, char *argv[]) {
	int i = 0;
	int sum = 0;
	for (i = 0; i < 10000; i++) {
		//since we are counting up, we will only do a second factor_check
		//if our factor_sum > than our number
		int j = factor_sum(i);
		if (j > i) {
			if (factor_sum(j) == i) {
				printf("Amicable Pair found: %d and %d\n", i, j);
				sum += i + j;
			}
		}
	}
	printf("Sum of amicable pairs: %d\n", sum);
}
